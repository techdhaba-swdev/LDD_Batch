#ifndef GDP_H
#define GDP_H

#define BUFFER_SIZE 100
struct {
	double lat;
	char latdir;
	double lt;
	char ts[15];
	char status;
	char long_dir;
	double sd;
	double cs;
	char data[10];
	double variation;
	char var_dir;
	char checksum[5];
}GDPData;

int parse_data(char *data, GDPData *gdp);
int parse_por(char *data, GDPData *gdp);
void update(GDPData *buffer,int *buffersize, GDPData *newdata);
void print_GDPData(const GDPData *gdp);

#endif // GDP_H

