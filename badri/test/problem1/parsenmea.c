#include"gpsstru.h"//includes the structure and functions of gpsdata
int parseNMEA(const char *sentence, GPSData *data) { // function to parse nmea sentence
    char type[6];//variable to hold the sentence type
    char status;//variable to hold status of sentence
    double lat_deg, lon_deg;//variables to hod the degrees of latitude and longitude
    double lat_min, lon_min;//variable to hold the minutes of latitude and longitude

    char lat_dir, lon_dir;//variable to hold the direction of latitude and longitude
    double speed, course;//variables to hols speed and course 
    char date[7];//variable to hold date
    double mag_var;//variable to hold the magnetic direction
    char mv_dir;//variable to hold magnetic variation direction
//parse nmea secentence and store the values in variables
    int n = sscanf(sentence, "$%5[^,],%[^,],%c,%lf°%lf,%c,%lf°%lf,%c,%lf,%lf,%6s,%lf,%c",
                   type, data->timestamp, &status, &lat_deg, &lat_min, &lat_dir,
                   &lon_deg, &lon_min, &lon_dir, &speed, &course, date,
                   &mag_var, &mv_dir);

    if (n == 14) { // checks all the values were successfully parsed
        data->lattitude = lat_deg + lat_min / 60.0;
        data->lat_dir = lat_dir;
        data->longitude = lon_deg + lon_min / 60.0;
        data->lon_dir = lon_dir;
        data->speed = speed;
        data->course = course;
        strncpy(data->date, date, 6);
        data->date[6] = '\0';
        data->magnetic_variation = mag_var;
        data->my_dir = mv_dir;
        return 1;//to indicate successfull parsing
    } else {
        return 0;//indicates failed parsing
    }
}
