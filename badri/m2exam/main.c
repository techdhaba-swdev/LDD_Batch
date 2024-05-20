#include "gpsstru.h"

int main() {
    // Example GPS sentences
    const char *nmea_sentence = "$GPRMC,081830.00,A,40°45.2222,N,074°00.1234,W,0.19,060.0,270520,2.13,W*6D";//example nmea sentence
    const char *porsche_sentence = "Porsche specific data string"; // Placeholder for Porsche-specific data

    // Buffer to store GPS data
    GPSData buffer;//declare a buffer to hold gps data

    // Determine format and parse accordingly
    if (strncmp(nmea_sentence, "$GPRMC", 6) == 0) { // checks if a secntence nmea sentence
        if (parseNMEA(nmea_sentence, &buffer)) {  //parse the nmea sentence
            printf("Parsed NMEA data successfully.\n"); // print the success message
        } else {
            printf("Failed to parse NMEA data.\n");//prints failure message
        }
    } else if (strncmp(porsche_sentence, "Porsche", 7) == 0) { // Placeholder check for Porsche-specific data
        if (parsePorsche(porsche_sentence, &buffer)) { // parse the porsche sentence
            printf("Parsed Porsche-specific data successfully.\n");//print success message

        } else {
            printf("Failed to parse Porsche-specific data.\n");//print failure message
        }
    } else {
        printf("Unknown data format.\n");//prints message of not known data
    }

    // Update GPS data buffer
    updateGPSDataBuffer(&buffer, &buffer);

    return 0;//it indicates successful execution
}

