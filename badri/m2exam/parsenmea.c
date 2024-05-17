#include"gpsstru.h"
int parseNMEA(const char *sentence, GPSData *data) {
    char type[6];
    char status;
    double lat_deg, lon_deg;
    double lat_min, lon_min;
    char lat_dir, lon_dir;
    double speed, course;
    char date[7];
    double mag_var;
    char mv_dir;

    int n = sscanf(sentence, "$%5[^,],%[^,],%c,%lf°%lf,%c,%lf°%lf,%c,%lf,%lf,%6s,%lf,%c",
                   type, data->timestamp, &status, &lat_deg, &lat_min, &lat_dir,
                   &lon_deg, &lon_min, &lon_dir, &speed, &course, date,
                   &mag_var, &mv_dir);

    if (n == 14) {
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
        return 1;
    } else {
        return 0;
    }
}
