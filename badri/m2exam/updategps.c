#include "gpsstru.h"
void updateGPSDataBuffer(GPSData *buffer , GPSData *data)//function to update the gps data
{
	*buffer = *data;//copy the new data to buffer
//printing the updated format
	printf("Timestamp : %s\n", buffer->timestamp);
	printf("Latitude : %f %c \n" ,buffer->lattitude , buffer->lat_dir);
	printf("Longitude : %f %c \n" , buffer->longitude , buffer->lon_dir);
	printf("speed : %f \n",buffer->speed);
	printf("course :%f \n",buffer->course);
	printf("Date : %s\n",buffer->date);
	printf(" Magnetic Variation : %f %c\n", buffer->magnetic_variation,buffer->my_dir);
}
