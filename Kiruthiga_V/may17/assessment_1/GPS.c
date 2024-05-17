#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store GPS data
typedef struct {
    float latitude;
    float longitude;
    char time_stamp[10];
    float speed;
    float course_angle;
    char date[7]; 
    float magnetic_variation;
} GPSdata;

GPSdata parse_nmea(const char *data) {
    GPSdata gps_data;
    char *token;
    char copy[100];
    strcpy(copy, data);

    
    token = strtok(copy, ",");
    for (int i = 0; token != NULL && i < 12; i++) {
        switch (i) {
            case 1:
                strcpy(gps_data.time_stamp, token);
                break;
            case 3:
                gps_data.latitude = atof(token) / 100;
                break;
            case 4:
                if (strcmp(token, "S") == 0)
                    gps_data.latitude *= -1;
                break;
            case 5:
                gps_data.longitude = atof(token) / 100;
                break;
            case 6:
                if (strcmp(token, "W") == 0)
                    gps_data.longitude *= -1;
                break;
            case 7:
                gps_data.speed = atof(token);
                break;
            case 8:
                gps_data.course_angle = atof(token);
                break;
            case 9:
                strcpy(gps_data.date, token);
                break;
            case 10:
                gps_data.magnetic_variation = atof(token);
                break;
        }
        token = strtok(NULL, ",");
    }

    return gps_data;
}


GPSdata parse_porsche(const char *data) {
    GPSdata gps_data;
    char *token;
    char copy[100];
    strcpy(copy, data);

    token = strtok(copy, "<>,=");
    for (int i = 0; token != NULL && i < 5; i++) {
        switch (i) {
            case 3:
                gps_data.latitude = atof(token) / 100;
                break;
            case 4:
                if (strcmp(token, "S") == 0)
                    gps_data.latitude *= -1;
                break;
            case 7:
                gps_data.longitude = atof(token) / 100;
                break;
            case 8:
                if (strcmp(token, "W") == 0)
                    gps_data.longitude *= -1;
                break;
            case 10:
                gps_data.speed = atof(token);
                break;
            case 12:
                gps_data.course_angle = atof(token);
                break;
            case 14:
                strcpy(gps_data.date, token);
                break;
        }
        token = strtok(NULL, "<>,=");
    }

    return gps_data;
}


GPSdata parse_gps_data(const char *data) {
    if (strncmp(data, "$GPRMC", 6) == 0)
        return parse_nmea(data);
    else
        return parse_porsche(data);
}

int main() {
    char input_data[100];
    printf("Enter GPS data: ");
    fgets(input_data, sizeof(input_data), stdin);
    input_data[strcspn(input_data, "\n")] = 0; // Remove newline character

    GPSdata parsed_data = parse_gps_data(input_data);
    printf("Latitude: %.4f\nLongitude: %.4f\nTimestamp: %s\nSpeed: %.2f\nCourse Angle: %.1f\nDate: %s\nMagnetic Variation: %.2f\n",
           parsed_data.latitude, parsed_data.longitude, parsed_data.time_stamp, parsed_data.speed, parsed_data.course_angle, parsed_data.date, parsed_data.magnetic_variation);
    return 0;
}


