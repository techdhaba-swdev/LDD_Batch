#include <stdio.h>
#include <stdlib.h>
#include <string.h>

                                                  // Defining the structure to store GPS data
struct GPSData {
    char timestamp[10];
    double latitude;
    double longitude;
    double speed;
    char date[7];
    double magnetic_variation;
};

                                                                                 // Function to parse an NMEA sentence
void parse_data(const char *nmea_sentence, struct GPSData *buffer, int *count)  //nmea_sentance -> A ponter to string contain NMEA sentance
{                                                                               //buffer -> a ponter to an array of GPSData structure were
										//parse data will be stored 
										//count -> ponter to integer that keeps trackof the no. of
										//valid data point in the buffer.
    char sentence[100];                                                         // Copy the input sentence to avoid modifying the original
    strcpy(sentence, nmea_sentence);

    char *token = strtok(sentence, ",");
    if (strcmp(token, "$GPRMC") == 0) {
                                                            // Assuming the input format: $GPRMC,hhmmss.sss,
			                                    // A,latitude,N,longitude,E,speed,date,magnetic_variation*checksum
        token = strtok(NULL, ",");                    
                                                 	// Skip the sentence identifier
        strcpy(buffer[*count].timestamp, token);

        token = strtok(NULL, ",");                      //strtok its the function that split the sentence into tokens base on commas
        buffer[*count].latitude = atof(token);

        token = strtok(NULL, ",");
        token = strtok(NULL, ",");            // Skip the latitude direction (N or S)

        token = strtok(NULL, ",");
        buffer[*count].longitude = atof(token);

        token = strtok(NULL, ",");
        token = strtok(NULL, ","); // Skip the longitude direction (E or W)

        token = strtok(NULL, ",");
        buffer[*count].speed = atof(token);

        token = strtok(NULL, ",");
        strcpy(buffer[*count].date, token);

        token = strtok(NULL, ",");
        buffer[*count].magnetic_variation = atof(token);

        (*count)++;
    } else {
        printf("Invalid NMEA sentence: %s\n", nmea_sentence);
    }
}

int main() {
    const char *sample_data = "$GPRMC,080003.00,A,40.7127,-N,74.0060,-W,0.02,0.8,170524,000.0,M,N*68";
    struct GPSData gps_buffer[100];                                                        // Assuming a maximum of 100 data points
    int data_count = 0;

                                                                                         // Process the sample data
    parse_data(sample_data, gps_buffer, &data_count);

                                                                                        // Print the parsed data
    for (int i = 0; i < data_count; i++) {
        printf("Timestamp: %s\n", gps_buffer[i].timestamp);
        printf("Latitude: %.6lf\n", gps_buffer[i].latitude);
        printf("Longitude: %.6lf\n", gps_buffer[i].longitude);
        printf("Speed: %.2lf knots\n", gps_buffer[i].speed);
        printf("Date: %s\n", gps_buffer[i].date);
        printf("Magnetic Variation: %.2lf\n", gps_buffer[i].magnetic_variation);
        printf("\n");
    }

    return 0;
}
