#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 200

// Structure to store GPS information
typedef struct {
    char time[11];
    char latitude[16];
    char longitude[16];
    char speed[11];
    char course[11];
    char date[11];
} GPSData;

// Function to parse NMEA format GPS data
int parseNMEA(const char *data, GPSData *gps) {
    char *token = strtok((char*)data, ",");
    if (token == NULL || strcmp(token, "$GPRMC") != 0) {
        fprintf(stderr, "Error: Invalid data format\n");
        return -1;
    }

    // Tokenize the remaining fields
    for (int i = 0; i < 9; i++) {
        token = strtok(NULL, ",");
       
        switch (i) {
            case 0:
                    if (token == NULL) {
            strncpy(gps->time, "0",1);
           
        }else{
                strncpy(gps->time, token, sizeof(gps->time) - 1);
                gps->time[sizeof(gps->time) - 1] = '\0'; 
                }
                break;
            case 1:
            if (token == NULL) {
            strncpy(gps->latitude, "0",1);
           
        }else{
        
    /*int degrees;
    float minutes;
    char direction;

   
    if (sscanf(token, "%d°%f,%c", &degrees, &minutes, &direction) == 3) {
        printf("Longitude: %d degrees, %.4f minutes %c\n", degrees, minutes, direction);
    } else {
        printf("Invalid input format\n");
    }*/
                strncpy(gps->latitude, token, sizeof(gps->latitude) - 1);
                gps->latitude[sizeof(gps->latitude) - 1] = '\0';
                }
                break;
            case 2:
            if (token == NULL) {
            strncpy(gps->longitude, "0",1);
           
        }else{
                strncpy(gps->longitude, token, sizeof(gps->longitude) - 1);
                gps->longitude[sizeof(gps->longitude) - 1] = '\0';
                }
                break;
            case 7:
            if (token == NULL) {
            strncpy(gps->speed, "0",1);
           
        }else{
                strncpy(gps->speed, token, sizeof(gps->speed) - 1);
                gps->speed[sizeof(gps->speed) - 1] = '\0';
                }
                break;
            case 8:
            if (token == NULL) {
            strncpy(gps->course, "0",1);
           
        }else{
                strncpy(gps->course, token, sizeof(gps->course) - 1);
                gps->course[sizeof(gps->course) - 1] = '\0';
                }
                break;
            case 9:
            if (token == NULL) {
            strncpy(gps->date, "0",1);
           
        }else{
                strncpy(gps->date, token, sizeof(gps->date) - 1);
                gps->date[sizeof(gps->date) - 1] = '\0';
                }
                break;
        }
    }

    return 0; // Success
}

// Function to parse Porsche-specific format GPS data
int parsePorsche(const char *data, GPSData *gps) {
    // For demonstration, let's assume the same format as NMEA
    return parseNMEA(data, gps);
}

// Function to update GPS structure with parsed data
int updateGPSData(const char *data, GPSData *gps) {
    if (strstr(data, "$GPRMC") != NULL) {
        return parseNMEA(data, gps);
    } else {
        return parsePorsche(data, gps);
    }
}

int main() {

int i=0;
FILE *file;
    char line[100];  // Buffer to store each line (adjust size as needed)

    // Open the file
    file = fopen("sample_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read data line by line from the file
     GPSData gps[100];
    while (fgets(line, sizeof(line), file) != NULL) {
    //printf("%s\n",line);
    
    if (updateGPSData(line, &gps[i]) == 0) {
        // Display parsed GPS information
    printf("Time: %s\n", gps[i].time);
        printf("Latitude: %s\n", gps[i].latitude);
        printf("Longitude: %s\n", gps[i].longitude);
        printf("Speed: %s knots\n", gps[i].speed);
        printf("Course: %s degrees\n", gps[i].course);
        printf("Date: %s\n", gps[i].date);
    }
     i++;   
    }

    // Close the file
    fclose(file);

    
   
    
    // Update GPS structure with parsed data
    
    return 0;
}
