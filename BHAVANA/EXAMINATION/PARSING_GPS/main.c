#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"




#define LINE_BUFFER_SIZE 256




// Function to handle each line of GPS data
void processGPSLine(const char* line) {
    GPSData gpsData;
    int result = parseGPSData(line, &gpsData);

    if (result == 0) {
        // Output the parsed data
        printf("Status: %c\n", gpsData.status);
        printf("Latitude: %.4lf %c\n", gpsData.latitude, gpsData.lat_direction);
        printf("Longitude: %.4lf %c\n", gpsData.longitude, gpsData.lon_direction);
        printf("Speed: %.2lf knots\n", gpsData.speed);
        printf("Course: %.2lf degrees\n", gpsData.course);
        printf("Date: %s\n", gpsData.date);
        printf("Magnetic Variation: %.2lf %c\n", gpsData.mag_variation, gpsData.mag_var_direction);
        printf("----------------------------------------\n");
    } else {
        printf("Error parsing GPS data: %d\n", result); // Error handling
    }
}





int main() {
    const char* filepath = "gps_data.txt";
    FILE* file = fopen(filepath, "r");

    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char line[LINE_BUFFER_SIZE];

    while (fgets(line, sizeof(line), file)) {
        processGPSLine(line); // Process each line
    }

    fclose(file);
    return 0;
}
