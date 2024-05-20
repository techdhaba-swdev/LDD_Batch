#ifndef GDP_H
#define GDP_H

typedef struct {
    char time[11];
    double lat;
    double lon;
    double velocity;
    double heading;
    char date_str[7];
    double mag_var;
} GDPInfo;


int parse_nmea_sentence(const char *sentence, GDPInfo *info);
int parse_porsche_sentence(const char *sentence, GDPInfo *info);
int parse_gdp_sentence(const char *sentence, GDPInfo *info);
void display_gdp_info(const GDPInfo *info);

#endif // GDP_H

