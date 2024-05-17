#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  structure to hold GPS data
typedef struct {
    char utc_time[10];        // UTC time of the fix
    char status;              
    double latitude;          // Latitude in degrees and minutes
    char lat_direction;       
    double longitude;         // longitude in degrees and minutes
    char lon_direction;      
    double speed;             // Speed over ground in knots
    double course;            // Course over ground in degrees
    char date[7];             // Date 
    double magnetic_variation;// variation in degrees
    char mv_direction;        // 'E' = East, 'W' = West
} GPS_DATA;

// function to parse NMEA sentences
int parse_nmea(const char* line, GPS_DATA* data) {
    // Check if the sentence is a GPRMC sentence
    if (strncmp(line, "$GPRMC", 6) != 0) {
        return -1; 
    }

    char token_hold[12][20];
    int i = 0;
    const char* start = line;
    const char* end = strchr(start, ',');
    
    // Extract token_hold from the sentence
    while (end != NULL) {
        strncpy(token_hold[i], start, end - start); 
        token_hold[i][end - start] = '\0';          // null-terminate the string
        start = end + 1;
        end = strchr(start, ',');
        i++;
    }
    strcpy(token_hold[i], start); // Copy the last token

    // Extract data from token_hold
    strcpy(data->utc_time, token_hold[1]);          // extract UTC time
    data->status = token_hold[2][0];                // extract status
    data->latitude = atof(token_hold[3]);           // extract latitude
    data->lat_direction = token_hold[4][0];         // extract latitude direction
    data->longitude = atof(token_hold[5]);          // extract longitude
    data->lon_direction = token_hold[6][0];         // extract longitude direction
    data->speed = atof(token_hold[7]);              // extract speed
    data->course = atof(token_hold[8]);             // extract course
    strcpy(data->date, token_hold[9]);              // extract date
    data->magnetic_variation = atof(token_hold[10]);// extract magnetic variation
    data->mv_direction = token_hold[11][0];         // extract magnetic variation direction

    return 0; // parsing successful
}

//  function to parse porsche-specific gps data
int parse_porsch(const char* line, GPS_DATA* data) {
    
    return 0;
}


int main() {
    // sample GPS data in NMEA format
    const char* sample_data = "$GPRMC,081830.00,A,40°45.2222,N,074°00.1234,W,0.19,060.0,270520,2.13,W*6D";
    GPS_DATA data; //  GPS_DATA structure to hold parsed data

    // checking if the sample data is an NMEA sentence
    if (strncmp(sample_data, "$GPRMC", 6) == 0) {
        // parse  data
        if (parse_nmea(sample_data, &data) == 0) {
            // Parsing successful, print the parsed data
            printf("parsed  data successfully.\n");
            printf("UTC Time: %s\n", data.utc_time);
            printf("Status: %c\n", data.status);
            printf("Latitude: %.4f %c\n", data.latitude, data.lat_direction);
            printf("Longitude: %.4f %c\n", data.longitude, data.lon_direction);
            printf("Speed: %.2f knots\n", data.speed);
            printf("Course: %.2f degrees\n", data.course);
            printf("Date: %s\n", data.date);
            printf("Magnetic Variation: %.2f %c\n", data.magnetic_variation, data.mv_direction);
        } else {
            // parsing failed
            printf("failed to parse data.\n");
        }
    } else {
        
        if (parse_porsch(sample_data, &data) == 0) {
            // successful, print the parsed data
            printf("parsed  data successfully.\n");
            // Printfields here (to be implemented)
        } else {
            //  failed
            printf("faiiled to parse Porsche data.\n");
        }
    }

    return 0; // nd of main function
}