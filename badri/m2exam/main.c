#include "gpsstru.h"

int main() {
    // Example GPS sentences
    const char *nmea_sentence = "$GPRMC,081830.00,A,40°45.2222,N,074°00.1234,W,0.19,060.0,270520,2.13,W*6D";
    const char *porsche_sentence = "Porsche specific data string"; // Placeholder for Porsche-specific data

    // Buffer to store GPS data
    GPSData buffer;

    // Determine format and parse accordingly
    if (strncmp(nmea_sentence, "$GPRMC", 6) == 0) {
        if (parseNMEA(nmea_sentence, &buffer)) {
            printf("Parsed NMEA data successfully.\n");
        } else {
            printf("Failed to parse NMEA data.\n");
        }
    } else if (strncmp(porsche_sentence, "Porsche", 7) == 0) { // Placeholder check for Porsche-specific data
        if (parsePorsche(porsche_sentence, &buffer)) {
            printf("Parsed Porsche-specific data successfully.\n");
        } else {
            printf("Failed to parse Porsche-specific data.\n");
        }
    } else {
        printf("Unknown data format.\n");
    }

    // Update GPS data buffer
    updateGPSDataBuffer(&buffer, &buffer);

    return 0;
}

