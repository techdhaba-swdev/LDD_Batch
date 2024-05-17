#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

// Structure to store GPS information
typedef struct {
    char time[11];
    char latitude[16];
    char longitude[16];
    char speed[11];
    char course[11];
    char date[11];
} GPSData;

// Function to parse NMEA format GPS data
int parseNMEA(const char *data, GPSData *gps) {
    char *token = strtok((char*)data, ",");
    if (token == NULL || strcmp(token, "$GPRMC") != 0) {
        fprintf(stderr, "Error: Invalid data format\n");
        return -1;
    }

    // Tokenize the remaining fields
    for (int i = 0; i < 9; i++) {
        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Error: Missing fields in GPS data\n");
            return -1;
        }
        switch (i) {
            case 0:
                strncpy(gps->time, token, sizeof(gps->time) - 1);
                gps->time[sizeof(gps->time) - 1] = '\0'; // Ensure null-termination
                break;
            case 1:
                strncpy(gps->latitude, token, sizeof(gps->latitude) - 1);
                gps->latitude[sizeof(gps->latitude) - 1] = '\0';
                break;
            case 2:
                strncpy(gps->longitude, token, sizeof(gps->longitude) - 1);
                gps->longitude[sizeof(gps->longitude) - 1] = '\0';
                break;
            case 7:
                strncpy(gps->speed, token, sizeof(gps->speed) - 1);
                gps->speed[sizeof(gps->speed) - 1] = '\0';
                break;
            case 8:
                strncpy(gps->course, token, sizeof(gps->course) - 1);
                gps->course[sizeof(gps->course) - 1] = '\0';
                break;
            case 9:
                strncpy(gps->date, token, sizeof(gps->date) - 1);
                gps->date[sizeof(gps->date) - 1] = '\0';
                break;
        }
    }

    return 0; // Success
}

// Function to parse Porsche-specific format GPS data
int parsePorsche(const char *data, GPSData *gps) {
    // For demonstration, let's assume the same format as NMEA
    return parseNMEA(data, gps);
}

// Function to update GPS structure with parsed data
int updateGPSData(const char *data, GPSData *gps) {
    if (strstr(data, "$GPRMC") != NULL) {
        return parseNMEA(data, gps);
    } else {
        return parsePorsche(data, gps);
    }
}

int main() {
    const char *gps_data = "$GPRMC,081830.00,A,40°45.2222,N,074°00.1234,W,0.19,060.0,270520,2.13,W*6D";
    GPSData *gps=(GPSData *) malloc(sizeof(GPSData));
    
    // Update GPS structure with parsed data
    if (updateGPSData(gps_data, gps) == 0) {
        // Display parsed GPS information
        printf("Time: %s\n", gps->time);
        printf("Latitude: %s\n", gps->latitude);
        printf("Longitude: %s\n", gps->longitude);
        printf("Speed: %s knots\n", gps->speed);
        printf("Course: %s degrees\n", gps->course);
        printf("Date: %s\n", gps->date);
    }

    return 0;
}
