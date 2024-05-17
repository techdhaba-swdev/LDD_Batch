#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for to  store GPS data
struct GPSData {
    char time[10];      // UTC time of the fix
    char status;        // Status of the fix (A = Data valid)
    double latitude;    // Latitude
    double longitude;   // Longitude
    double speed;       // Speed in knots
    double course;      // Course angle
    char date[7];       // Date of the fix
    double variation;   // Magnetic variation
};
void parseGPSData(const char *gpsData, struct GPSData *gpsStruct) {
    // Use sscanf to parse the GPS data
    sscanf(gpsData, "$GPRMC,%9s,%c,%lf,%*c,%lf,%*c,%lf,%lf,%6s,%lf", 
           gpsStruct->time, &gpsStruct->status, &gpsStruct->latitude, 
           &gpsStruct->longitude, &gpsStruct->speed, &gpsStruct->course, 
           gpsStruct->date, &gpsStruct->variation);
}


// Main function
int main() {
    // Sample GPS data
    const char *gpsData = "$GPRMC,081830.00,A,40°45.2222,N,074°00.1234,W,0.19,060.0,270520,2.13,W*6D";
    struct GPSData gpsStruct;//declare a GPSData structure to store parsed data
    parseGPSData(gpsData, &gpsStruct); // Parse GPS data
// Print parsed GPS data
    printf("Time: %s\n", gpsStruct.time);
    printf("Status: %c\n", gpsStruct.status);
    printf("Latitude: %.4f\n", gpsStruct.latitude);
    printf("Longitude: %.4f\n", gpsStruct.longitude);
    printf("Speed: %.2f knots\n", gpsStruct.speed);
    printf("Course: %.1f degrees\n", gpsStruct.course);
    printf("Date: %s\n", gpsStruct.date);
    printf("Magnetic Variation: %.2f degrees\n", gpsStruct.variation);

    return 0;
}
	

