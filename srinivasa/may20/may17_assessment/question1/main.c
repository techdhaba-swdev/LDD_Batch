#include <stdio.h>
#include "gps.h"

int main() {
    // Sample NMEA data
    const char *nmea_data = "$GPRMC,081830.00,A,4045.2222,N,07400.1234,W,0.19,060.0,270520,2.13,W*6D";
    // Sample Porsche-specific data
    const char *porsche_data = "081830.00 40.753703 -74.002056 0.19 60.0 270520 2.13";

    GPSData gps_data;

    // Parsing NMEA data
    if (parse_gps_data(nmea_data, &gps_data) == 0) {
        print_gps_data(&gps_data);
    }

    // Parsing Porsche-specific data
    if (parse_gps_data(porsche_data, &gps_data) == 0) {
        print_gps_data(&gps_data);
    }
    return 0;
}
