#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold GPS data
typedef struct {
    char time[11];
    char status;
    double latitude;
    double longitude;
    double speed;
    double course;
    char date[7];
    double variation;
} GPSData;

double parseCoordinate(const char *field, char direction) {
    double degrees, minutes;
    sscanf(field, "%2lf%lf", &degrees, &minutes);
    double decimal = degrees + minutes / 60.0;
    if (direction == 'S' || direction == 'W') {
        decimal = -decimal;
    }
    return decimal;
}

// parsing gps dataa 
int parseGPSData(const char *nmeaData, GPSData *data) {
    char buffer[100];
    strncpy(buffer, nmeaData, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char *token = strtok(buffer, ",");
    if (strcmp(token, "$GPRMC") != 0) {
        return -1; // Not a GPRMC message
    }

    // Parse thee time
    token = strtok(NULL, ",");
    strncpy(data->time, token, sizeof(data->time) - 1);
    data->time[sizeof(data->time) - 1] = '\0';

    // Parse status
    token = strtok(NULL, ",");
    data->status = token[0];

    // Parse latitude
    token = strtok(NULL, ",");
    char latDir = strtok(NULL, ",")[0];
    data->latitude = parseCoordinate(token, latDir);

    // Parse longitude
    token = strtok(NULL, ",");
    char longDir = strtok(NULL, ",")[0];
    data->longitude = parseCoordinate(token, longDir);

    // Parse speed in knots and convert to km/h
    token = strtok(NULL, ",");
    data->speed = atof(token) * 1.852;

    // Parse course
    token = strtok(NULL, ",");
    data->course = atof(token);

    // Parse date
    token = strtok(NULL, ",");
    strncpy(data->date, token, sizeof(data->date) - 1);
    data->date[sizeof(data->date) - 1] = '\0';

    // Parse variation
    token = strtok(NULL, ",");
    if (token != NULL && token[0] != '*') {
        char varDir = strtok(NULL, ",")[0];
        data->variation = atof(token) * (varDir == 'W' ? -1 : 1);
    } else {
        data->variation = 0.0; 
    }

    return 0; // Success
}

int main() {
    const char *gpsStrings[] = {
        "$GPRMC,081830.00,A,4045.2222,N,07400.1234,W,0.19,060.0,270520,2.13,W*6D",
        "$GPRMC,081830.01,A,4045.2224,N,07400.1235,W,0.20,060.0,270550,2.53,N*6D",
	"$GPRMC,080000.00,A,40.7128,N,74.0059,W,0.00,0.00,170524,000.0,2.13,N*77"
        NULL 
    };

    for (int i = 0; gpsStrings[i] != NULL; i++) {
        GPSData gpsData;
        if (parseGPSData(gpsStrings[i], &gpsData) == 0) {
            printf(" GPS Data for string %d:\n", i + 1);
            printf("Time: %s\n", gpsData.time);
            printf("Status: %c\n", gpsData.status);
            printf("Latitude: %.6f\n", gpsData.latitude);
            printf("Longitude: %.6f\n", gpsData.longitude);
            printf("Speed (km/h): %.2f\n", gpsData.speed);
            printf("Course: %.2f\n", gpsData.course);
            printf("Date: %s\n", gpsData.date);
            printf("Variation: %.2f\n\n", gpsData.variation);
        } else {
            printf("Error parsing the GPS data for string %d.\n\n", i + 1);
        }
    }

    return 0;
}






	
