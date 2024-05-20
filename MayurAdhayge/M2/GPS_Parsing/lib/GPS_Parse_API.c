#include <stdbool.h>
#include <string.h>
//----struct to store the parse data in it ------------//
typedef struct {
    char message_id[8]; //--message_id variable is store the message identifier statements in string formate
    char time[12]; //--time variavle store the UTC time in the joined time formate for ex.(12:20:30.20 in 122030.20) in strin formate
    char status; //--status variable store the staus of the data. data valid or not valid  where for ex.(A=Data Valid) 
    float latitude_degrees; //--latitude_degrees variable store the value of degree in the latitude
    float latitude_minutes; //--latitude_minutes variable store the latitude minutes in latitude data string
    char latitude_dir; //--latitude_dir variable store the latitude direction in latitude data string
    float longitude_degrees; //--longitude_degrees variable store the value of degree in the longitude
    float longitude_minutes; //--longitude_minutes variable store the longitude minutes in longitude data string
    char longitude_dir; //--longitude_dir variable store the longitude direction in longitude data string
    float speed; //--speed variable store the speed of vehicle in knot
    float course; //--course variable store the angle of course in degree
    char date[7]; //--date variable store the date  time-stamp
    float magnetic_variation; //--magnetic_variation variable store the magnetic variation in data
    char checksum[4]; //--checksum stored the value of checksum for authentication
} GPSData; //GPSData is the typedef for the gps struct data

//-----------------end of struct---------------------//





//-------------validation function for validating the parsed data before stroing to the struct GPSData ---------------------//


//----------validateMessageID function use to validate the validate Message identifier string is empty or not
bool validateMessageID(const char *message_id) 
{

    if (message_id[0] == '\0') //--here we check that we get the data or empty string 
    {
        return false; //--if message identifier is empty then it retun false
    }
    return true; //--if message identifier is present then it retun true
}
//-- end of validateMessage function-------------//



//-- validateTime function is use to validate the time string
bool validateTime(const char *time) 
{
    if (time[0] == '\0') //--check if string empty then our validation fail and return false
    {
        return false; //--it return the value falese on fail validation
    }
    int hour; //--hour is temp variable use to store the hours from parseing value from time
    int min; //--min is temp variable use to store the minute  from parseing time
    float sec; //--sec is the temp variable use to store the second from parseing time 
    sscanf(time,"%2d%2d%2lf",&hour,&min,&sec); //--here we parse the time in hour min and sec by two decimal (%2d)
    if(hour>24||min>60||sec>60||sec<0||hour<0||min<0) //--here we can che time hour min value is greater 60 or less than 0
    {
    return false; //--return false is validation fail
    }
    return true; //--return true if validation in pass
}
//-----end of validateTime function-----------------//



//-----------validateStatus function to validate the status of data 
bool validateStatus(const char status) {
   
    if (status != 'A' ) //--check if the status value is not equal to A then its invalid data
    {
        return false; //--return false if validation fail
    }
    return true; //--return true is validation pass
}
//-------------end of validateStatus------------------//


//validateLatitude function use to check the latitude validtaions it taking the three constant latitude_degrees latitude_minute and latitude_dir
bool validateLatitude(const float latitude_degrees, const float latitude_minutes, const char latitude_dir) 
{
   
    if (latitude_degrees < -90 || latitude_degrees > 90 ||
        latitude_minutes < 0 || latitude_minutes >= 60 ||
        (latitude_dir != 'N' && latitude_dir != 'S')) //-- here we check the the valid latitude componente
        {
        return false; //--return false if validation fail
        }
    return true; //--return true if validation pass
}
//------------end of validate 
bool validateLongitude(const float longitude_degrees, const float longitude_minutes, const char longitude_dir) {
    
    if (longitude_degrees < -180 || longitude_degrees > 180 ||
        longitude_minutes < 0 || longitude_minutes >= 60 ||
        (longitude_dir != 'E' && longitude_dir != 'W')) {
        return false;
    }
    return true;
}

bool validateSpeed(const float speed) {
    
    if (speed <=0) {
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
    if (strlen(date) != 6) {
        return false; 
    }
    int day, month, year;
    sscanf(date, "%2d%2d%2d", &day, &month, &year);
   
    if (day < 1 || day > 31 || month < 1 || month > 12 || 23<year) {
     printf("%d %d %d",day,month,year);
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

gps->longitude_degrees=-1;
gps->longitude_minutes=-1;
gps->longitude_dir=-1;

}
if(validateSpeed(speed))
{
gps->speed=speed;
}
else
{
gps->speed=-1;
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


