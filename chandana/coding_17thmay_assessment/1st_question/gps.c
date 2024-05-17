#include "gps.h"//header file to take the functions 


// Function to parse GPS data
int parse(const char* sentence, GPSData* gps_data) {
    if (!sentence || !gps_data) {
        return 0; // Return 0 if input is invalid
    }

    
    //strncmp and string token is used to parse the data and compare and make it in parse string 
 

    if (strncmp(sentence, "$GPRMC,", 7) == 0) {
        char *token;
        char buffer[100];
        strncpy(buffer, sentence, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';

//parsing for time
        token = strtok(buffer, ",");
        token = strtok(NULL, ","); // Time
        if (token) strncpy(gps_data->time, token, sizeof(gps_data->time) - 1);

//parsing for status

        token = strtok(NULL, ","); // Status
        if (token) gps_data->status = token[0];
//
//parsing for latitude
        token = strtok(NULL, ","); // Latitude
        if (token) strncpy(gps_data->latitude, token, sizeof(gps_data->latitude) - 1);

//parsing for lati_direction

  	token = strtok(NULL, ","); // Latitude direction
        if (token) gps_data->lat_direction = token[0];

//parsing for longitude

        token = strtok(NULL, ","); // Longitude
        if (token) strncpy(gps_data->longitude, token, sizeof(gps_data->longitude) - 1);

//parsing for lon direction

        token = strtok(NULL, ","); // Longitude direction
        if (token) gps_data->lon_direction = token[0];
//
//parsing for speed 

        token = strtok(NULL, ","); // Speed
        if (token) strncpy(gps_data->speed, token, sizeof(gps_data->speed) - 1);

//parsing for course
        
	token = strtok(NULL, ","); // Course
        if (token) strncpy(gps_data->course, token, sizeof(gps_data->course) - 1);

//parsing for date
        
	token = strtok(NULL, ","); // Date
        if (token) strncpy(gps_data->date, token, sizeof(gps_data->date) - 1);


        return 1; // Return 1 if parsing is successful
    
    }


    return 0; // Return 0 if sentence is not a GPRMC message

}
