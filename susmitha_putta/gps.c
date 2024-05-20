#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char timestamp[11];
    double latitude;
    double longitude;
    double speed;
    double course;
    char date[7];
    double magnetic_variation;
} GPSData;

// Function prototypes
int parse_nmea(const char *data, GPSData *gps_data);
int parse_porsche(const char *data, GPSData *gps_data);
int parse_gps_data(const char *data, GPSData *gps_data);
void print_gps_data(const GPSData *gps_data);
void convert_latlon(int deg, float min, char dir, double *result);

// Function to convert latitude and longitude from degrees and minutes to decimal format
void convert_latlon(int deg, float min, char dir, double *result) {
    *result = deg + min / 60.0;
    if (dir == 'S' || dir == 'W') {
        *result = -(*result);
    }
}

// Function to parse NMEA data
int parse_nmea(const char *data, GPSData *gps_data) {
    if (data[0] != '$') {
        fprintf(stderr, "Data does not start with a valid NMEA sentence\n");
        return -1;
    }

    char type[6];
    strncpy(type, data, 5);
    type[5] = '\0';

    if (strcmp(type, "$GPRMC") != 0) {
        fprintf(stderr, "Unsupported NMEA sentence type: %s\n", type);
        return -1;
    }

    char status;
    char ns, ew, mv_direction;
    int lat_deg, lon_deg;
    float lat_min, lon_min;

    int parsed = sscanf(data, "$GPRMC,%10[^,],%c,%2d%5f,%c,%3d%5f,%c,%lf,%lf,%6[^,],%lf,%c",
                        gps_data->timestamp, &status, &lat_deg, &lat_min, &ns,
                        &lon_deg, &lon_min, &ew, &gps_data->speed,
                        &gps_data->course, gps_data->date, &gps_data->magnetic_variation,
                        &mv_direction);

    if (parsed < 12 || status != 'A') {
        fprintf(stderr, "Error parsing NMEA data or invalid data status\n");
        return -1;
    }

    convert_latlon(lat_deg, lat_min, ns, &gps_data->latitude);
    convert_latlon(lon_deg, lon_min, ew, &gps_data->longitude);

    if (parsed < 13) {
        gps_data->magnetic_variation = 0.0;
    } else if (mv_direction == 'W') {
        gps_data->magnetic_variation = -gps_data->magnetic_variation;
    }

    return 0;
}

// Function to parse Porsche-specific GPS data
int parse_porsche(const char *data, GPSData *gps_data) {
    int parsed = sscanf(data, "%10s %lf %lf %lf %lf %6s %lf",
                        gps_data->timestamp, &gps_data->latitude, &gps_data->longitude,
                        &gps_data->speed, &gps_data->course, gps_data->date,
                        &gps_data->magnetic_variation);

    if (parsed < 6) {
        fprintf(stderr, "Error parsing Porsche-specific data\n");
        return -1;
    }

    if (parsed < 7) {
        gps_data->magnetic_variation = 0.0;
    }

    return 0;
}

// Function to bifurcate and handle the parsing process
int parse_gps_data(const char *data, GPSData *gps_data) {
    if (data[0] == '$') {
        return parse_nmea(data, gps_data);
    } else {
        return parse_porsche(data, gps_data);
    }
}

void print_gps_data(const GPSData *gps_data) {
    printf("GPSData(timestamp=%s, latitude=%lf, longitude=%lf, speed=%lf, course=%lf, date=%s, magnetic_variation=%lf)\n",
           gps_data->timestamp, gps_data->latitude, gps_data->longitude,
           gps_data->speed, gps_data->course, gps_data->date,
           gps_data->magnetic_variation);
}

int main() {
    // Sample NMEA data
    const char *nmea_data = "$GPRMC,081830.00,A,4045.2222,N,07400.1234,W,0.19,060.0,270520,2.13,W*6D";
    // Sample Porsche-specific data
    const char *porsche_data = "081830.00 40.753703 -74.002056 0.19 60.0 270520 2.13";

    GPSData gps_data;

    // Parsing NMEA data
    if (parse_gps_data(nmea_data, &gps_data) == 0) {
        print_gps_data(&gps_data);
    }

    // Parsing Porsche-specific data
    if (parse_gps_data(porsche_data, &gps_data) == 0) {
        print_gps_data(&gps_data);
    }

    return 0;
}
