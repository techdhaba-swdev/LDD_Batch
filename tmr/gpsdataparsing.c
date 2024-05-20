#include <stdio.h>

// Define the GPSData structure
typedef struct {
    double latitude;
    double longitude;
    char timestamp[11];
    double speed;
    double course;
    char date[7];
    double variation;
    char status;
} GPSData;

// Function to print GPSData
void printGPSData(GPSData data) {
    printf("Latitude: %.6f\n", data.latitude);
    printf("Longitude: %.6f\n", data.longitude);
    printf("Timestamp: %s\n", data.timestamp);
    printf("Speed: %.2f\n", data.speed);
    printf("Course: %.2f\n", data.course);
    printf("Date: %s\n", data.date);
    printf("Variation: %.2f\n", data.variation);
    printf("Status: %c\n", data.status);
}

int main() {
    // Declare and initialize a GPSData variable
    GPSData myGPSData = {
        37.7749,     // latitude
        -122.4194,   // longitude
        "12:34:56",  // timestamp
        55.5,        // speed
        180.0,       // course
        "230417",    // date
        1.5,         // variation
        'A'          // status
    };

    // Print the GPSData
    printGPSData(myGPSData);

    return 0;
}
