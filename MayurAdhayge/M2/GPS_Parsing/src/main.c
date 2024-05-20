#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
    printf("%s",line);
    if (parse(line, (gps+i)) == 0) {
        
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
