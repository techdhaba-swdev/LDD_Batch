#include<stdio.h>
#define MAX_LENGTH 200
int main()
{
        FILE *file;

    	double latitude;
    	double longitude;
    	double speed;
    	double course;
    	double variation;
    	char status;
    	file = fopen("gpsdata.txt","r");

    	if(file == NULL)
	{
        	printf("Error opening the file.\n");
        	return 1;
	}
	while(fscanf(file, "%ld %ld %ld %ld %ld", latitude,longitude,speed,course,variation) != EOF)
	{
        	printf("latitude: %ld\n", latitude);
        	printf("longitude: %ld\n", longitude);
        	printf("speed: %ld\n", speed);
        	printf("course: %ld\n", course);
        	printf("variation: %ld\n", variation);
        	printf("status: %s\n", status);
	}
      		fclose(file);

       return 0;
}
