#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gdp.h"

// Function to parse NMEA data
int parse_nmea_sentence(const char *sentence, GDPInfo *info) {
    if (sentence[0] != '$') {
        printf("Sentence does not start with a valid NMEA identifier\n");
        return -1;
    }
    
    char type[6];
    strncpy(type, sentence, 5);
    type[5] = '\0';

    if (strcmp(type, "$GPRMC") != 0) {
        printf("Unsupported NMEA sentence type\n");
        return -1;
    }

    char status;
    char ns, ew, mv_dir;
    int lat_deg, lon_deg;
    float lat_min, lon_min;

    int parsed = sscanf(sentence, "$GPRMC,%10[^,],%c,%2d%5f,%c,%3d%5f,%c,%lf,%lf,%6[^,],%lf,%c",
                        info->time, &status, &lat_deg, &lat_min, &ns, 
                        &lon_deg, &lon_min, &ew, &info->velocity, 
                        &info->heading, info->date_str, &info->mag_var, 
                        &mv_dir);

    if (parsed < 12 || status != 'A') {
        printf("Error parsing NMEA sentence or invalid data status\n");
        return -1;
    }

    info->lat = lat_deg + lat_min / 60.0;
    if (ns == 'S') {
        info->lat = -info->lat;
    }

    info->lon = lon_deg + lon_min / 60.0;
    if (ew == 'W') {
        info->lon = -info->lon;
    }

    if (parsed < 13) {
        info->mag_var = 0.0;
    } else if (mv_dir == 'W') {
        info->mag_var = -info->mag_var;
    }

    return 0;
}

// Function to parse Porsche-specific GPS data
int parse_porsche_sentence(const char *sentence, GDPInfo *info) {
    int parsed = sscanf(sentence, "%10s %lf %lf %lf %lf %6s %lf", 
                        info->time, &info->lat, &info->lon, 
                        &info->velocity, &info->heading, info->date_str, 
                        &info->mag_var);

    if (parsed < 6) {
        printf("Error parsing Porsche-specific data\n");
        return -1;
    }

    if (parsed < 7) {
        info->mag_var = 0.0;
    }

    return 0;
}

// Function to bifurcate and handle the parsing process
int parse_gdp_sentence(const char *sentence, GDPInfo *info) {
    if (sentence[0] == '$') {
        return parse_nmea_sentence(sentence, info);
    } else {
        return parse_porsche_sentence(sentence, info);
    }
}

void display_gdp_info(const GDPInfo *info) {
    printf("GDPInfo(time=%s, lat=%lf, lon=%lf, velocity=%lf, heading=%lf, date_str=%s, mag_var=%lf)\n", 
           info->time, info->lat, info->lon, 
           info->velocity, info->heading, info->date_str, 
           info->mag_var);
}
