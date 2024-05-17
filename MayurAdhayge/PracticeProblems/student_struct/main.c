#include<stdio.h>
typedef struct {
char *name;
int roll_no;
int class;
char *dob;
}student;

//------------variable section--------------------------//

  //variable for taking input from console 
char name[10]; //buffer variable is use to store the name of the student
int roll_no; //roll_no variable is use to store the name of the student
int class; //class variable is use to store the class of the student
char dob[10]; //dob is use for storing the date of birth of student
 //end variable for taking input from console 

 //variable take data from file
char buffer[1024];
 //end of variable take data from file
 
//-------------end variable section-------------------------//

//the execution of the program is start with main function
void main()
{
student st1;
FILE *fd=fopen("student1.txt","a"); //open the file  student.txt in append mode and refference access by fd file variable
FILE *fd1=fopen("student.txt","a");

if (fd!=NULL) //checking that file open successfully or not if successfully open then we start our data insertion in it
{
	for(int i=0;i<1;i++) //this loop for how many student we have to insert in the file and there data
	{
        //------input taking code section of program
            	
	  printf("\n enter the name of student:-"); //prompt for console for taking name as input
	  scanf("%s",name); //storing the name of student in buffer variable
	  printf("\n enter the roll number of student:-"); //prompt for console for taking roll number as input
	  scanf("%d",&roll_no); //storing roll number of student  in roll_no variable
	  printf("\n enter the class  of student:-"); //prompt for console for taking class as input
	  scanf("%d",&class); //storing the class of student  in class variable
	  printf("\n enter the date of birth of student:-"); //prompt for console for taking date of birth as input
	  scanf("%s",dob); //storing the data of birth of student  in dob variable
	  
	//------input taking code section of program
	 
	//here we storing the data in sample.txt file in fomat of  "name roll_no class  date_of_birth" all are in one line space 
	  fprintf(fd,"%s %d %d %s \n",name,roll_no,class,dob);  
	                                                      
	}
	
        while(fgets(buffer,sizeof(buffer),fd1)!=NULL)
        {
          sscanf(buffer,"%s %d %d %s",st1.name,&st1.roll_no,&st1.class,st1.dob);
          break;
        } 
        printf("name=%s",st1.name);       
}
fclose(fd); // here we deintializing the fd pointer 
fclose(fd1);
}
