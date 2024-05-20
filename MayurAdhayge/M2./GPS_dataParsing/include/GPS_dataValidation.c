
#include <stdbool.h>
#include <string.h>

#include "main.h"

bool validateMessageID(const char *message_id) {
    return message_id[0] != '\0';
}

bool validateTime(const char *time) {
    return time[0] != '\0';
}

bool validateStatus(const char status) {
    return status == 'A';
}

bool validateLatitude(const float latitude_degrees, const float latitude_minutes, const char latitude_dir) {
    return (latitude_degrees >= -90 && latitude_degrees <= 90) &&
           (latitude_minutes >= 0 && latitude_minutes < 60) &&
           (latitude_dir == 'N' || latitude_dir == 'S');
}

bool validateLongitude(const float longitude_degrees, const float longitude_minutes, const char longitude_dir) {
    return (longitude_degrees >= -180 && longitude_degrees <= 180) &&
           (longitude_minutes >= 0 && longitude_minutes < 60) &&
           (longitude_dir == 'E' || longitude_dir == 'W');
}

bool validateSpeed(const float speed) {
    return speed > 0;
}

bool validateCourse(const float course) {
    return course >= 0 && course <= 360;
}

bool validateDate(const char *date) {
    int day, month, year;
    if (sscanf(date, "%2d%2d%2d", &day, &month, &year) != 3)return false;
  if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0 || year > 99 ) return false;
    return true;
}

bool validateMagneticVariation(const float magnetic_variation) {
    // Add validation if needed
    return true;
}

bool validateChecksum(const char *checksum) {
    return checksum[0] != '\0';
}
