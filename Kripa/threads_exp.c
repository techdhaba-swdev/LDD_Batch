#include<stdio.h>
#include<pthread.h>

void printMsg(char* msg){
       printf("%s\n",msg);
}
int main(int argc, char** argv){
     pthread_t thrdID;

     printf("creating a new thread\n");
     pthread_create(&thrdID, NULL,(void*)printMsg,argv[1]);
     printf("created thread \n");

     pthread_join(thrdID, NULL);

     return 0;

}
