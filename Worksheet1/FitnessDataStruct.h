
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <math.h>
int number_of_records = 0;
int buffer_size = 21;
char line_buffer[21];
char date; 
char time; 
char steps;
// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;
FITNESS_DATA fitnessdata[1000];
// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps){
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

void fewestSteps(){
    int feweststeps = 0;
    for(int i=1;i<number_of_records;i++){
        if (fitnessdata[feweststeps].steps > fitnessdata[i].steps){
            feweststeps = i;
        }
    }
    printf("Fewest steps: %s %s\n",fitnessdata[feweststeps].date,fitnessdata[feweststeps].time);
}

void largestSteps(){
    int largeststeps = 0;
    for(int i=1;i<number_of_records;i++){
        if (fitnessdata[largeststeps].steps < fitnessdata[i].steps){
            largeststeps = i;
        }
    }
    printf("Largest steps: %s %s\n",fitnessdata[largeststeps].date,fitnessdata[largeststeps].time);
}



void Input(){
    char filename[100];
    printf("Enter filename: ");
    scanf("%s",filename);
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error: Could not open file");
    }
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        if (strlen(line_buffer)>3){
            char steps[6];
            tokeniseRecord(line_buffer,",",fitnessdata[number_of_records].date,fitnessdata[number_of_records].time,steps);
            fitnessdata[number_of_records].steps = atoi(steps);
            number_of_records = number_of_records + 1;
        }
    }
    fclose(file);
}

void total(){
    printf("Total records: %d\n",number_of_records);
}

void Mean(){
    int mean;
    for(int i=1;i<number_of_records;i++){
        mean = mean + fitnessdata[i].steps;
    }
    mean = round(mean / number_of_records);
    printf("Mean step count: %d\n",mean);
}

void lognestPeriod(){
    int start = NULL;
    int end = NULL;
    int best = 0;
    for(int i=0;i<number_of_records;i++){
        printf("%d: %d %d %d %d\n",i,start,end,best,fitnessdata[i].steps);
        if (start == NULL){
            if (fitnessdata[i].steps > 500){
                start = i;
            }
        }else if ( start != NULL && fitnessdata[i].steps < 500 && (i-start) > best){
            end = i;
            best = i - start;
            start = NULL;
        }
    }
    printf("Longest period start: %s %s\n",fitnessdata[end-best].date,fitnessdata[end-best].time);
    printf("Longest period end: %s %s\n",fitnessdata[end].date,fitnessdata[end].time);
}

#endif // FITNESS_DATA_STRUCT_H
