#include "gps.h" //header file to take the functions 



// Function to print GPS data
void print_gps_data(const GPSData* gps_data) {
    if (gps_data == NULL) {
        return;
    }
//print the data in parse
 printf("Status: %c\n", gps_data->status);
  printf("Time: %s\n", gps_data->time);
  printf("Latitude: %s %c\n", gps_data->latitude, gps_data->lat_direction);
 
 printf("Date: %s\n", gps_data->date);
  printf("Longitude: %s %c\n", gps_data->longitude, gps_data->lon_direction);
   printf("Speed: %s \n", gps_data->speed);
   printf("Course: %s \n", gps_data->course);
}

//main function to call

int main()
{
const char* sentence = "$GPRMC,081830.00,A,40°45.2222,N,074°00.1234,W,0.19,060.0,270520,2.13,W*6D";
  
GPSData gps_data;
//passing to parse

    if (parse(sentence, &gps_data)) {
        print_gps_data(&gps_data);
    } else {
        printf("Failed to parse GPS data.\n");
    }

    return 0;//return 0 t if success
}
