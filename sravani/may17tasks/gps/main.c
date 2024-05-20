#include <stdio.h>
#include "gdp.h"

int main() {
    // Sample NMEA data
    const char *nmea_sentence = "$GPRMC,081830.00,A,4045.2222,N,07400.1234,W,0.19,060.0,270520,2.13,W*6D";
    // Sample Porsche-specific data
    const char *porsche_sentence = "081830.00 40.753703 -74.002056 0.19 60.0 270520 2.13";

    GDPInfo info;

    // Parsing NMEA data
    if (parse_gdp_sentence(nmea_sentence, &info) == 0) {
        display_gdp_info(&info);
    }

    // Parsing Porsche-specific data
    if (parse_gdp_sentence(porsche_sentence, &info) == 0) {
        display_gdp_info(&info);
    }
    return 0;
}

