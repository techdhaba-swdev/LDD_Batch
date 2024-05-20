#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char time[11];
    char status;
    double latitude;
    char lat_dir;
    double longitude;
    char long_dir;
    double speed;
    double course;
    char date[7];
    double variation;
    char var_dir;
} GPSData;

int parseGPSData(char *nmea, GPSData *data) {
    char *token;
    char *search = ",";

    token = strtok(nmea, search);
    if (strcmp(token, "$GPRMC") != 0) {
        printf("Error: Unsupported message type.\n");
        return -1;
    }

    token = strtok(NULL, search);
    strcpy(data->time, token);
    
    token = strtok(NULL, search);
    data->status = token[0];
    
    token = strtok(NULL, search);
    data->latitude = atof(token);
    
    token = strtok(NULL, search);
    data->lat_dir = token[0];
    
    token = strtok(NULL, search);
    data->longitude = atof(token);
    
    token = strtok(NULL, search);
    data->long_dir = token[0];
    
    token = strtok(NULL, search);
    data->speed = atof(token);
    
    token = strtok(NULL, search);
    data->course = atof(token);
    
    token = strtok(NULL, search);
    strcpy(data->date, token);
    
    token = strtok(NULL, search);
    data->variation = atof(token);
    
    token = strtok(NULL, search);
    data->var_dir = token[0];

    return 0;
}

int main() {
    FILE *file;
    char line[100];
    GPSData gpsData;

    file = fopen("gps_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (parseGPSData(line, &gpsData) == 0) {
            printf("Time:%s\n", gpsData.time);
            printf("Status:%c\n", gpsData.status);
            printf("Latitude:%lf %c\n", gpsData.latitude, gpsData.lat_dir);
            printf("Longitude:%lf %c\n", gpsData.longitude, gpsData.long_dir);
            printf("Speed:%lf knots\n", gpsData.speed);
            printf("Course:%lf degrees\n", gpsData.course);
            printf("Date:%s\n", gpsData.date);
            printf("Magnetic Variation:%lf %c\n", gpsData.variation, gpsData.var_dir);
        } else {
            printf("Failed to parse GPS data.\n");
        }
    }

    fclose(file);

    return 0;
}
