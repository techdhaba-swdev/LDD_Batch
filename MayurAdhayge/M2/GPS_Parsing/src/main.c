#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    char message_id[8];
    char time[12]; 
    char status;
    float latitude_degrees;
    float latitude_minutes;
    char latitude_dir;
    float longitude_degrees;
    float longitude_minutes;
    char longitude_dir;
    float speed;
    float course;
    char date[7];
    float magnetic_variation;
    char checksum[4];
} GPSData;

bool validateMessageID(const char *message_id) {
    if (message_id[0] == '\0') {
        return false;
    }
    return true;
}




bool validateTime(const char *time) {
    
    
    if (time[0] == '\0') {
        return false;
    }
    return true;
}

bool validateStatus(const char status) {
   
    if (status != 'A' ) {
        return false;
    }
    return true;
}

bool validateLatitude(const float latitude_degrees, const float latitude_minutes, const char latitude_dir) {
   
    if (latitude_degrees < -90 || latitude_degrees > 90 ||
        latitude_minutes < 0 || latitude_minutes >= 60 ||
        (latitude_dir != 'N' && latitude_dir != 'S')) {
        return false;
    }
    return true;
}

bool validateLongitude(const float longitude_degrees, const float longitude_minutes, const char longitude_dir) {
    
    if (longitude_degrees < -180 || longitude_degrees > 180 ||
        longitude_minutes < 0 || longitude_minutes >= 60 ||
        (longitude_dir != 'E' && longitude_dir != 'W')) {
        return false;
    }
    return true;
}

bool validateSpeed(const float speed) {
    
    if (speed < 0) {
        return false;
    }
    return true;
}

bool validateCourse(const float course) {
    
    if (course < 0 || course > 360) {
        return false;
    }
    return true;
}

bool validateDate(const char *date) {
   
    if (date[0] == '\0') {
        return false;
    }
    return true;
}

bool validateMagneticVariation(const float magnetic_variation) {
    
    return true;
}

bool validateChecksum(const char *checksum) {
   
    if (checksum[0] == '\0') {
        return false;
    }
    return true;
}



bool parse(const char *data, GPSData *gps) {
    
    char message_id[8];
    char time[12]; 
    char status;
    float latitude_degrees;
    float latitude_minutes;
    char latitude_dir;
    float longitude_degrees;
    float longitude_minutes;
    char longitude_dir;
    float speed;
    float course;
    char date[7];
    float magnetic_variation;
    char checksum[4];
    
    int result = sscanf(data, "%7[^,],%9[^,],%c,%f°%f,%c,%f°%f,%c,%f,%f,%6[^,],%f,%3[^*]",
                        message_id, time, &status,
                        &latitude_degrees, &latitude_minutes, &latitude_dir,
                        &longitude_degrees, &longitude_minutes,&longitude_dir,
                        &speed, &course, date,&magnetic_variation, checksum);
                        

if (validateMessageID(message_id))
{

strcpy(gps->message_id,message_id);
}
else
{
strcpy(gps->message_id,"-1");
}
if (validateTime(time))
{
strcpy(gps->time,time);
}
else
{
strcpy(gps->time,"-1");
}
if (validateStatus(status))
{
  gps->status=status;
}
else
{
  gps->status=-1;
}
if(validateLatitude(latitude_degrees,latitude_minutes,latitude_dir))
{
   gps->latitude_degrees=latitude_degrees;
   gps->latitude_minutes=latitude_minutes;
   gps->latitude_dir=latitude_dir;
}
else
{
	gps->latitude_degrees=-1;
	gps->latitude_minutes=-1;
	gps->latitude_dir=-1;
}
if(validateLongitude(longitude_degrees,longitude_minutes,longitude_dir))
{
gps->longitude_degrees=longitude_degrees;
gps->longitude_minutes=longitude_minutes;
gps->longitude_dir=longitude_dir;
}
else
{
{
gps->longitude_degrees=-1;
gps->longitude_minutes=-1;
gps->longitude_dir=-1;
}
}
if(validateCourse(course))
{
gps->course=course;
}
else
{
gps->course=-1;
}
if(validateDate(date))
{
strcpy(gps->date,date);
}
else
{
strcpy(gps->date,"-1");
}

if(validateMagneticVariation(magnetic_variation))
{
  gps->magnetic_variation=magnetic_variation;     
}
else
{
gps->magnetic_variation=-1;
}

if(validateChecksum(checksum))
{
strcpy(gps->checksum,checksum);
}
return 0;
    }


int main() {
int i=0;
FILE *file;
    char line[100];  // Buffer to store each line (adjust size as needed)

    // Open the file
    file = fopen("sample_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read data line by line from the file
     GPSData gps[100];
    while (fgets(line, sizeof(line), file) != NULL) {
    
    if (parse(line, &gps[i]) == 0) {
        
     printf("\n--------------------------------------------------------------------------\n");   
        
    printf("Message ID: %s\n", gps[i].message_id);
    printf("Time: %s\n", gps[i].time);
    printf("Status: %c\n", gps[i].status);
    printf("Latitude: %.0f°%.4f' %c\n", gps[i].latitude_degrees, gps[i].latitude_minutes, gps[i].latitude_dir);
    printf("Longitude: %.0f°%.4f' %c\n", gps[i].longitude_degrees, gps[i].longitude_minutes, gps[i].longitude_dir);
    printf("Speed: %.2f knots\n", gps[i].speed);
    printf("Course: %.1f degrees\n", gps[i].course);
    printf("Date: %s\n", gps[i].date);
    printf("Magnetic Variation: %.2f degrees\n", gps[i].magnetic_variation);
    printf("Checksum: %s\n", gps[i].checksum);
        
    }
     i++;

       
    }
   

   
    return 0;
}
