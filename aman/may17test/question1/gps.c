#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gps.h"//includes header file

int parse_gprmc(const char *sentence, GPSData *data) { implementing parsegpmrc function
    if (strncmp(sentence, "$GPRMC", 6) != 0) {
        return -1;
    }

    
    char tokens[13][MAX_TOKEN_LEN];
    int token_idx = 0;
    char *temp = strdup(sentence);
    if (temp == NULL) {
        return -1; 
    }

    char *token = strtok(temp, ",");
    while (token != NULL && token_idx < 13) {
        if (strlen(token) >= MAX_TOKEN_LEN) {
            free(temp);
            return -1; 
        }

        strncpy(tokens[token_idx], token, MAX_TOKEN_LEN - 1);
        tokens[token_idx][MAX_TOKEN_LEN - 1] = '\0'; 
        token_idx++;
        token = strtok(NULL, ",");
    }
	if (token_idx < 12) {
        free(temp);
        return -1; 
    }
    strncpy(data->utc_time, tokens[1], sizeof(data->utc_time) - 1);
    data->utc_time[sizeof(data->utc_time) - 1] = '\0';
    data->status = tokens[2][0];
    strncpy(data->latitude, tokens[3], sizeof(data->latitude) - 1);
    data->latitude[sizeof(data->latitude) - 1] = '\0';
    data->lat_direction = tokens[4][0];
    strncpy(data->longitude, tokens[5], sizeof(data->longitude) - 1);
    data->longitude[sizeof(data->longitude) - 1] = '\0';
    data->lon_direction = tokens[6][0];
    data->speed = atof(tokens[7]);
    data->course = atof(tokens[8]);
    strncpy(data->date, tokens[9], sizeof(data->date) - 1);
    data->date[sizeof(data->date) - 1] = '\0';
    data->magnetic_variation = atof(tokens[10]);
    data->mv_direction = tokens[11][0];

    
    if (strlen(tokens[12]) < 2) {
        free(temp);
        return -1; 
    }
    strncpy(data->checksum, &tokens[12][1], sizeof(data->checksum) - 1);
    data->checksum[sizeof(data->checksum) - 1] = '\0';
    free(temp);
    return 0;
}
