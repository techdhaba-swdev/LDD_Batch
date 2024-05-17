#ifndef GPS_PARSER_H
#define GPS_PARSER_H

// Define a structure to store GPS data
typedef struct {
    char status;
    double latitude;
    char lat_direction;
    double longitude;
    char lon_direction;
    double speed;
    double course;
    char date[7];
    double mag_variation;
    char mag_var_direction;
} GPSData;

// Function prototypes
int parseNMEA(const char* nmea_sentence, GPSData* gpsData);
int parsePorsche(const char* porsche_sentence, GPSData* gpsData); // Placeholder for Porsche-specific format
int parseGPSData(const char* sentence, GPSData* gpsData);

#endif // GPS_PARSER_H
