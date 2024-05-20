#ifndef GDP_PARSER_H
#define GDP_PARSER_H

typedef struct {
    char time[11];
    double lat;
    double lon;
    double velocity;
    double heading;
    char date_str[7];
    double mag_var;
} GDPInfo;

// Function to parse NMEA data
int parse_nmea_sentence(const char *sentence, GDPInfo *info);

// Function to parse Porsche-specific GPS data
int parse_porsche_sentence(const char *sentence, GDPInfo *info);

// Function to bifurcate and handle the parsing process
int parse_gdp_sentence(const char *sentence, GDPInfo *info);

// Function to print GPS data
void display_gdp_info(const GDPInfo *info);

#endif // GDP_PARSER_H
