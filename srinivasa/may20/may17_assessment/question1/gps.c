#include "gps.h"

void parseGPSData(const char *nmeaSentence, GPSData *data) {
    if (strncmp(nmeaSentence, "$GPGGA", 6) == 0) {
        char temp[MAX_NMEA_LEN];
        strcpy(temp, nmeaSentence);

        char *token = strtok(temp, ",");
        int fieldIndex = 0;

        while (token != NULL) {
            switch (fieldIndex) {
                case 2:
                    data->latitude = atof(token) / 100.0; // Convert from ddmm.mmmm to decimal degrees
                    break;
                case 3:
                    data->latitudeDirection = token[0];
                    break;
                case 4:
                    data->longitude = atof(token) / 100.0; // Convert from dddmm.mmmm to decimal degrees
                    break;
                case 5:
                    data->longitudeDirection = token[0];
                    break;
                case 7:
                    data->satellites = atoi(token);
                    break;
                case 8:
                    data->hdop = atof(token);
                    break;
                case 9:
                    data->altitude = atof(token);
                    break;
            }
            token = strtok(NULL, ",");
            fieldIndex++;
        }

        // Adjust latitude and longitude based on direction
        if (data->latitudeDirection == 'S') {
            data->latitude = -data->latitude;
        }
        if (data->longitudeDirection == 'W') {
            data->longitude = -data->longitude;
        }
    }
}
