#include <stdio.h>
#include "gps.h"

int main() {
    // Sample GPS data
    const char sample_data[] = "$GPRMC,081830.00,A,40°45.2222,N,074°00.1234,W,0.19,060.0,270520,2.13,W*6D";

    // Parse GPS data
    struct GPSData parsed_data = parse_gps_data(sample_data);

    // Update structure with parsed data
    update_gps_data(parsed_data);

    return 0;
}

