#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gps.h"

struct GPSData parse_gps_data(const char *data) {
    struct GPSData gps_data;
    char *copy = strdup(data); // Make a copy of the data to avoid modifying the original string
    if (!copy) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char *pass = strtok(copy, ",");
    if (!pass || strcmp(pass, "$GPRMC") != 0) {
        fprintf(stderr, "Invalid data format\n");
        free(copy);
        exit(EXIT_FAILURE);
    }

    // Parse timestamp
    pass = strtok(NULL, ",");
    if (pass) strncpy(gps_data.timestamp, pass, sizeof(gps_data.timestamp));

    
    pass = strtok(NULL, ",");

    // Parse latitude
    pass = strtok(NULL, ",");
    if (pass) strncpy(gps_data.latitude, pass, sizeof(gps_data.latitude));

    // Parse latitude direction
    pass = strtok(NULL, ",");
    if (pass) gps_data.lat_direction = *pass;

    // Parse longitude
    pass = strtok(NULL, ",");
    if (pass) strncpy(gps_data.longitude, pass, sizeof(gps_data.longitude));

    // Parse longitude direction
    pass = strtok(NULL, ",");
    if (pass) gps_data.lon_direction = *pass;

    // Parse speed
    pass = strtok(NULL, ",");
    if (pass) gps_data.speed = atof(pass);

    // Parse course
    pass = strtok(NULL, ",");
    if (pass) gps_data.course = atof(pass);

    // Parse date
    pass = strtok(NULL, ",");
    if (pass) strncpy(gps_data.date, pass, sizeof(gps_data.date));

    free(copy); // Free allocated memory
    return gps_data;
}

void update_gps_data(struct GPSData gps_data) {
    printf("Timestamp: %s\n", gps_data.timestamp);
    printf("Latitude: %s %c\n", gps_data.latitude, gps_data.lat_direction);
    printf("Longitude: %s %c\n", gps_data.longitude, gps_data.lon_direction);
    printf("Speed: %.2f knots\n", gps_data.speed);
    printf("Course: %.2f degrees\n", gps_data.course);
    printf("Date: %s\n", gps_data.date);
}

