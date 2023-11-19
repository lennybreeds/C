#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array


// Complete the main function
int main() {
    printf("A: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the data and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Exit\n");
    while(1){
        char menu;
        printf("Option: ");
        scanf("%s",&menu);
        switch (menu) {
            case 'A':
                Input();
                break;
            case 'B':
                total();
                break;
            case 'C':
                fewestSteps();
                break;
            case 'D':
                largestSteps();
                break;
            case 'E':
                Mean();
                break;
            case 'F':
                lognestPeriod();
                break;
            case 'Q':
                return 0;
        }
    }


}
