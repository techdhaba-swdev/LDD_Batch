#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store GPS data
struct GPSData {
    char timestamp[20];
    char status;
    char latitude[20];
    char lat_direction;
    char longitude[20];
    char lon_direction;
    float speed;
    float course;
    char date[20];
    float mag_variation;
    char mag_var_direction;
};

// Function to parse standard NMEA format
struct GPSData parse_standard_nmea(const char *data) {
    struct GPSData gps_data;
    char *token;
    char *copy = strdup(data); // Make a copy of the data to avoid modifying the original string
    if (!copy) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Tokenize the data using comma as delimiter
    token = strtok(copy, ",");
    if (!token || strcmp(token, "$GPRMC") != 0) {
        fprintf(stderr, "Invalid data format\n");
        free(copy);
        exit(EXIT_FAILURE);
    }

    // Parse fields according to the $GPRMC format
    token = strtok(NULL, ",");
    if (token) strncpy(gps_data.timestamp, token, sizeof(gps_data.timestamp));

    token = strtok(NULL, ",");
    if (token) gps_data.status = token[0];

    token = strtok(NULL, ",");
    if (token) strncpy(gps_data.latitude, token, sizeof(gps_data.latitude));

    token = strtok(NULL, ",");
    if (token) gps_data.lat_direction = token[0];

    token = strtok(NULL, ",");
    if (token) strncpy(gps_data.longitude, token, sizeof(gps_data.longitude));

    token = strtok(NULL, ",");
    if (token) gps_data.lon_direction = token[0];

    token = strtok(NULL, ",");
    if (token) gps_data.speed = atof(token);

    token = strtok(NULL, ",");
    if (token) gps_data.course = atof(token);

    token = strtok(NULL, ",");
    if (token) strncpy(gps_data.date, token, sizeof(gps_data.date));

    token = strtok(NULL, ",");
    if (token) gps_data.mag_variation = atof(token);

    token = strtok(NULL, ",");
    if (token) gps_data.mag_var_direction = token[0];

    free(copy); // Free allocated memory
    return gps_data;
}

// Function to update structure with parsed data
void update_struct(struct GPSData gps_data) {
    printf("Timestamp: %s\n", gps_data.timestamp);
    printf("Status: %c\n", gps_data.status);
    printf("Latitude: %s %c\n", gps_data.latitude, gps_data.lat_direction);
    printf("Longitude: %s %c\n", gps_data.longitude, gps_data.lon_direction);
    printf("Speed: %.2f knots\n", gps_data.speed);
    printf("Course: %.2f degrees\n", gps_data.course);
    printf("Date: %s\n", gps_data.date);
    printf("Magnetic Variation: %.2f %c\n", gps_data.mag_variation, gps_data.mag_var_direction);
}

int main() {
    // Sample GPS data
    const char sample_data[] = "$GPRMC,081830.00,A,40°45.2222,N,074°00.1234,W,0.19,060.0,270520,2.13,W*6D";

    // Parse GPS data
    struct GPSData parsed_data = parse_standard_nmea(sample_data);

    // Update structure with parsed data
    update_struct(parsed_data);

    return EXIT_SUCCESS;
}
