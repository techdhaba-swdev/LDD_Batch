#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gps_parser.h"

// NMEA data parsing function
int parseNMEA(const char* nmea_sentence, GPSData* gpsData) {
    if (nmea_sentence == NULL || gpsData == NULL) {
        return -1; // Error due to null pointer
    }

    char type[6];
    sscanf(nmea_sentence, "$%5[^,]", type);

    if (strcmp(type, "GPRMC") != 0) {
        return -2; // Error for unsupported type
    }

    int ret = sscanf(nmea_sentence,
        "$GPRMC,%*f,%c,%lf,%c,%lf,%c,%lf,%lf,%6s,%lf,%c",
        &gpsData->status,
        &gpsData->latitude,
        &gpsData->lat_direction,
        &gpsData->longitude,
        &gpsData->lon_direction,
        &gpsData->speed,
        &gpsData->course,
        gpsData->date,
        &gpsData->mag_variation,
        &gpsData->mag_var_direction);

    return (ret == 10) ? 0 : -3; // Parsing result
}

// Placeholder for Porsche-specific parsing logic
int parsePorsche(const char* porsche_sentence, GPSData* gpsData) {
    return -1; // Placeholder implementation
}

// Function to identify and parse GPS data format
int parseGPSData(const char* sentence, GPSData* gpsData) {
    if (sentence == NULL || gpsData == NULL) {
        return -1; // Error due to null pointer
    }

    if (strncmp(sentence, "$GPRMC", 6) == 0) {
        return parseNMEA(sentence, gpsData); // Parse NMEA format
    } else {
        return parsePorsche(sentence, gpsData); // Placeholder for other formats
    }
}
