#include <stdio.h>
#include <stdlib.h>
#include "gps_parser.h"

#define LINE_BUFFER_SIZE 256

// Function to handle each line of GPS data
void processGPSLine(const char* line) {
    GPSData gpsData; // Create a GPSData struct to store parsed data
    int result = parseGPSData(line, &gpsData); // Parse the GPS data from the line

    if (result == 0) { // Check if parsing was successful
        // Output the parsed data
        printf("Status: %c\n", gpsData.status);
        printf("Latitude: %.4lf %c\n", gpsData.latitude, gpsData.lat_direction);
        printf("Longitude: %.4lf %c\n", gpsData.longitude, gpsData.lon_direction);
        printf("Speed: %.2lf knots\n", gpsData.speed);
        printf("Course: %.2lf degrees\n", gpsData.course);
        printf("Date: %s\n", gpsData.date);
        printf("Magnetic Variation: %.2lf %c\n", gpsData.mag_variation, gpsData.mag_var_direction);
        printf("--------------------------\n");
    } else {
        printf("Error parsing GPS data: %d\n", result); // Error handling if parsing fails
    }
}

int main() {
    const char* filepath = "data.txt"; // File path containing GPS data
    FILE* file = fopen(filepath, "r"); // Open the file in read mode

    if (!file) { // Check if file opening failed
        perror("Failed to open file"); // Print error message
        return 1; // Return with error code
    }

    char line[LINE_BUFFER_SIZE]; // Buffer to store each line of GPS data

    while (fgets(line, sizeof(line), file)) { // Read each line from the file
        processGPSLine(line); // Process each line using the processGPSLine function
    }

    fclose(file); // Close the file
    return 0; // Return success
}
