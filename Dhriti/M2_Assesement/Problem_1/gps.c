#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef GPSDATA {
        
        double latitute[20];
        double longitude[20];
	char timestamp[10];
        double speed;
        double course;
        char date[20];
};

struct GPSDATA parse_data(const char *data) {
	struct GPSDATA gps_data;
	char *pass;
	char *copy = strdup(data);
	if(!copy) {
		fprintf(stderr, "Memory Allocation Failed");
		exit(EXIT_FAILURE);
	}

	pass = strtok(copy, ",");
	if(!pass || strcmp(pass, "$GPRMC") != 0){
	    fprintf(stderr, "Wrong Data Format\n");
	    exit(EXIT_FAILURE);
	}

	strcpy(gps_data.longitude, pass);

	pass = strtok(copy, ",");
        if(!pass){
            fprintf(stderr, "Latitude not found\n");
            exit(EXIT_FAILURE);
        }
       
	strcpy(gps_data.latitude, pass);

	pass = strtok(copy, ",");
        if(!pass){
            fprintf(stderr, "Longitude not found\n");
            exit(EXIT_FAILURE);
        }

        strcpy(gps_data.longitude, pass);

	pass = strtok(copy, ",");
        if(!pass){
            fprintf(stderr, "Timestamp not found\n");
            exit(EXIT_FAILURE);
        }

        strcpy(gps_data.timestamp, pass);

	pass = strtok(copy, ",");
        if(!pass){
            fprintf(stderr, "Speed not found\n");
            exit(EXIT_FAILURE);
        }

        gps_data.speed = atof(speed);

	pass = strtok(copy, ",");
        if(!pass){
            fprintf(stderr, "course not found\n");
            exit(EXIT_FAILURE);
        }

        gps_data.speed = atof(course);

	pass = strtok(copy, ",");
        if(!pass){
            fprintf(stderr, "Date not found\n");
            exit(EXIT_FAILURE);
        }

        strcpy(gps_data.Date, pass);



void update_struct(struct GPSDATA gps_data) {
	printf("Latitude: %s\n", gps_data.latitude);
    printf("Longitude: %s\n", gps_data.longitude);
    printf("Timestamp: %s\n", gps_data.timestamp);
    printf("Speed: %.2f\n", gps_data.speed);
    printf("Course: %.2f\n", gps_data.course);
    printf("Date: %s\n", gps_data.date);
   
}

int main() {
    
    const char sample_data[] = "$GPRMC,081830.00,A,40°45.2222,N,074°00.1234,W,0.19,060.0,270520,2.13";

    
    struct GPSData parsed_data = parse_gps_data(sample_data);

    
    update_struct(parsed_data);

    return EXIT_SUCCESS;
}
