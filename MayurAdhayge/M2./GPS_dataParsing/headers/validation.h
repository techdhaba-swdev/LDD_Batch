#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdbool.h>

bool validateMessageID(const char *message_id);
bool validateTime(const char *time);
bool validateStatus(const char status);
bool validateLatitude(const float latitude_degrees, const float latitude_minutes, const char latitude_dir);
bool validateLongitude(const float longitude_degrees, const float longitude_minutes, const char longitude_dir);
bool validateSpeed(const float speed);
bool validateCourse(const float course);
bool validateDate(const char *date);
bool validateMagneticVariation(const float magnetic_variation);
bool validateChecksum(const char *checksum);

#endif 

