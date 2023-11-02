#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
int number_of_records = 0;
int buffer_size = 21;
char line_buffer[21];
char date; 
char time; 
char steps;


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("");
        return 1;
    }
    FITNESS_DATA fitnessdata[1000];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        if (strlen(line_buffer)>3){
            char steps[5];
            tokeniseRecord(line_buffer,",",fitnessdata[number_of_records].date,fitnessdata[number_of_records].time,steps);
            fitnessdata[number_of_records].steps = atoi(steps);
            number_of_records = number_of_records + 1;
        }
    }
    printf("Number of records in file: %d\n",number_of_records);
    for (int i = 0; i<3;i++) {
        printf("%s/%s/%d\n",fitnessdata[i].date,fitnessdata[i].time,fitnessdata[i].steps);
    }
    fclose(file);
    return 0;

}
