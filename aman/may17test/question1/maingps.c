#include <stdio.h>
#include "gps.h"//header file

int main() {//starting main func
    const char *gps_data[] = {//array of gps data which contain the provided sample gps data
        "$GPRMC,080000.00,A,40.7128,N,74.0059,W,0.00,0.0,170524,000.0,M,N*77",
        "$GPRMC,080001.00,A,40.7128,N,74.0060,W,0.01,0.5,170524,000.0,M,N*74",
        "$GPRMC,080002.00,A,40.7127,N,74.0061,W,0.02,1.0,170524,000.0,M,N*71",
        "$GPRMC,080003.00,A,40.7127,N,74.0060,W,0.02,0.8,170524,000.0,M,N*68",
    };
    int num_data = sizeof(gps_data) / sizeof(gps_data[0]);//calculating no. of element in array gps data
    GPSData gps_data_struct[MAX_GPS_DATA];// declaring array gps data struct of GPSData which has a maximum capacity of maxgps data.

    for (int i = 0; i < num_data; ++i) {//loop to iterate in each gps sample data of the array gpsdata
        if (parse_gprmc(gps_data[i], &gps_data_struct[i]) == 0) {//calling parse gprmc  function with current gps data and address of
            printf("Parsed GPS Data %d:\n", i + 1);
            printf("UTC Time: %s\n", gps_data_struct[i].utc_time);
            printf("Status: %c\n", gps_data_struct[i].status);
            printf("Latitude: %s %c\n", gps_data_struct[i].latitude, gps_data_struct[i].lat_direction);
            printf("Longitude: %s %c\n", gps_data_struct[i].longitude, gps_data_struct[i].lon_direction);
            printf("Speed: %.2f knots\n", gps_data_struct[i].speed);
            printf("Course: %.2f degrees\n", gps_data_struct[i].course);
            printf("Date: %s\n", gps_data_struct[i].date);
            printf("Magnetic Variation: %.2f %c\n", gps_data_struct[i].magnetic_variation, gps_data_struct[i].mv_direction);
            printf("Checksum: %s\n", gps_data_struct[i].checksum);
            printf("\n");
        } else {
            printf("Failed to parse GPS data: %s\n", gps_data[i]);//prints this message if it is failed to print gps data
        }
    }

    
    return 0;
}
