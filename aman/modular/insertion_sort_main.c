#include <stdio.h> //This line includes the standard input-output library, which provides functions like printf() and scanf() that are used for input and output operations.
#include "insertion_sort.h" // This line includes the header file insertion_sort.h, which contains the function prototype for the insertion_sort function. This inclusion allows us to use the insertion sort function in this file.

#define MAX_SIZE 100//This line defines a macro MAX_SIZE with the value 100. This macro is used to specify the maximum size of the array to be sorted.

int main() {//This line defines the main function, which serves as the entry point of the program. It returns an integer value to the operating system upon completion.
    int arr[MAX_SIZE];//This line declares an integer array arr with a maximum size of MAX_SIZE, which is defined as 100.
    int n;//This line declares an integer variable n to store the number of elements to be sorted in the array.

    printf("Enter the number of elements in the array: ");//This line prints a prompt to the console, asking the user to enter the number of elements in the array.
    scanf("%d", &n);// This line reads an integer value from the console input and stores it in the variable n.

    if (n <= 0 || n > MAX_SIZE) {//This line checks if the value of n is less than or equal to 0 or greater than MAX_SIZE.
        printf("Invalid input size.\n");// If the condition is true, this line prints a message indicating that the input size is invalid.
        return 1;// This line terminates the program with a non-zero exit status, indicating an error condition.
    }

    printf("Enter %d elements: ", n);// This line prints a prompt asking the user to enter the elements of the array, specifying the number of elements entered by the user.
    for (int i = 0; i < n; i++) {//This line starts a loop that iterates n times, reading integer values from the console input and storing them in the array arr.
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);//This line calls the insertion_sort function, passing the array arr and its size n as arguments. This sorts the array in ascending order using the insertion sort algorithm.

    printf("Sorted array: ");//This line prints a message indicating that the array is sorted.
    for (int i = 0; i < n; i++) {//This line starts a loop that iterates over each element of the sorted array.
        printf("%d ", arr[i]);//This line prints each element of the sorted array separated by a space.
    }
    printf("\n");//This line prints a newline character to move the cursor to the next line after printing all the elements of the sorted array.

    return 0;//This line indicates successful termination of the program by returning 0 to the operating system.
}

