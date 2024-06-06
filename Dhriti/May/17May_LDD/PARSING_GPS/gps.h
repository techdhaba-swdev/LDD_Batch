#ifndef GPS_PARSER_H
#define GPS_PARSER_H

struct GPSData {
    char timestamp[20];
    char latitude[20];
    char lat_direction;
    char longitude[20];
    char lon_direction;
    float speed;
    float course;
    char date[20];
};

struct GPSData parse_gps_data(const char *data);
void update_gps_data(struct GPSData gps_data);

#endif

