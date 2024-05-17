#ifndef GPS_H 
#define GPS_H
#define MAX_GPS_DATA 100//defines max no. of gps data entery 100 which will be stored
#define MAX_TOKEN_LEN 20// definee max length of each token


typedef struct {
    char utc_time[11];
    char status;
    char latitude[10];
    char lat_direction;
    char longitude[11];
    char lon_direction;   // defineing structure named gps data to store parsed data.it include all parametre.s .
    float speed;
    float course;
    char date[7];
    float magnetic_variation;
    char mv_direction;
    char checksum[3];
} GPSData;
int parse_gprmc(const char *sentence, GPSData *data);// declaring function parse gprmc

#endif
