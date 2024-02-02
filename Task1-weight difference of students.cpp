#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 30
#define MAX_NAME_LENGTH 50

void inputStudentData(double weights[], char names[][MAX_NAME_LENGTH], int numStudents);
void calculateWeightDifference(double weights[], double weightDifferences[], int numStudents);
void outputStudentsWithDifference(double weights[], double weightDifferences[], char names[][MAX_NAME_LENGTH], int numStudents);

int main() {
   
    double weights[MAX_STUDENTS];
    char names[MAX_STUDENTS][MAX_NAME_LENGTH];
    double weightDifferences[MAX_STUDENTS];

  
    inputStudentData(weights, names, MAX_STUDENTS);

  
    calculateWeightDifference(weights, weightDifferences, MAX_STUDENTS);

    outputStudentsWithDifference(weights, weightDifferences, names, MAX_STUDENTS);

    return 0;
}


void inputStudentData(double weights[], char names[][MAX_NAME_LENGTH], int numStudents) {
    printf("Enter weights and names for %d students:\n", numStudents);

    for (int i = 0; i < numStudents; i++) {
        printf("Enter weight for student %d: ", i + 1);
        if (scanf("%lf", &weights[i]) != 1 || weights[i] < 0) {
            printf("Invalid weight. Please enter a non-negative numeric value.\n");
            i--; 
            while (getchar() != '\n'); 
        } else {
            printf("Enter name for student %d: ", i + 1);
            scanf("%s", names[i]);
        }
    }
}


void calculateWeightDifference(double weights[], double weightDifferences[], int numStudents) {
    printf("\nCalculating weight differences:\n");

    for (int i = 0; i < numStudents; i++) {
        printf("Enter weight for student %d on the last day of term: ", i + 1);
        double lastDayWeight;
        scanf("%lf", &lastDayWeight);

        weightDifferences[i] = lastDayWeight - weights[i];
    }
}


void outputStudentsWithDifference(double weights[], double weightDifferences[], char names[][MAX_NAME_LENGTH], int numStudents) {
    printf("\nStudents with a difference in weight of more than 2.5 kilograms:\n");

    for (int i = 0; i < numStudents; i++) {
        if (weightDifferences[i] > 2.5 || weightDifferences[i] < -2.5) {
            printf("Name: %s, Difference in weight: %.2lf kg, %s\n", names[i], weightDifferences[i],
                   (weightDifferences[i] > 0) ? "Rise" : "Fall");
        }
    }
}
