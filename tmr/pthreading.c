#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
typedef struct{ 
	FILE *ipfile;
	FILE *opfile;
	pthread_mutex_t *mutex;
	int strtline;
	}
ThrdData;
typedef struct{
	FILE *file;
}RdThrdData;

FILE* open_file(const char* fname, const char* mode)
{
	FILE* file=fopen(fname,mode);
	if(!file)
	{
	perror("File openbing operation failed");
	exit(EXIT_FAILURE);
	}
}
void* write_lines(void *arg)
{
ThrdData data=(ThrdData) arg;
char *line=NULL;
size_t len =0;
ssize_t read;
int lineno=0;

while(1)
{
pthread_mutex_lock(data->mutex);
read = getline(&line,&len,data->ipfile);
if(read==-1)
{
	pthread_mutex_unlock(data->mutex);
	break;
}
if((lineno%2)==data->strtline)
{
	fprintf(data->opfile,"%s",line);
}
lineno++;
pthread_mutex_unlock(data->mutex);
}
free(line);
return NULL;
}


void* read_and_print(void *arg) {
    RdThrdData data = (RdThrdData) arg;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, data->file)) != -1) {
        printf("%s", line);
    }

    free(line);
    return NULL;
}

int main() {
    pthread_t writeThread1, writeThread2, readThread1, readThread2;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    FILE *ipfile = open_file("input.txt", "r");
    FILE *fileone = open_file("fileone.txt", "w");
    FILE *filetwo = open_file("filetwo.txt", "w");

    ThrdData writeData1 = {ipfile, fileone, &mutex, 0};
    ThrdData writeData2 = {ipfile, filetwo, &mutex, 1};

    if (pthread_create(&writeThread1, NULL, write_lines, &writeData1) != 0 ||
        pthread_create(&writeThread2, NULL, write_lines, &writeData2) != 0) {
        perror("creation of writing threads its failed");
        fclose(ipfile);
        fclose(fileone);
        fclose(filetwo);
        return EXIT_FAILURE;
    }

    pthread_join(writeThread1, NULL);
    pthread_join(writeThread2, NULL);

    close_file(ipfile);
    close_file(fileone);
    close_file(filetwo);

    fileone = open_file("fileone.txt", "r");
    filetwo = open_file("filetwo.txt", "r");

    RdThrdData readData1 = {fileone};
    RdThrdData readData2 = {filetwo};

    if (pthread_create(&readThread1, NULL, read_and_print, &readData1) != 0 ||
        pthread_create(&readThread2, NULL, read_and_print, &readData2) != 0) {
        perror("creation of reading threads its failed");
        fclose(fileone);
        fclose(filetwo);
        return EXIT_FAILURE;
    }

    pthread_join(readThread1, NULL);
    pthread_join(readThread2, NULL);

    close_file(fileone);
    close_file(filetwo);

    return EXIT_SUCCESS;
}
