#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define PASS_MARK 50

// Structure to store student information
typedef struct {
    char name[100];
    int mark;
} Student;

// Function to display all students
void displayStudents(Student students[], int count) {
    int i;

    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n----- Student Grade Book -----\n");

    for (i = 0; i < count; i++) {
        printf("%d. %s - %d marks\n",
               i + 1,
               students[i].name,
               students[i].mark);
    }
}

// Function to find highest mark
int findHighest(Student students[], int count) {
    int max = students[0].mark;
    int i;

    for (i = 1; i < count; i++) {
        if (students[i].mark > max) {
            max = students[i].mark;
        }
    }

    return max;
}

// Function to find lowest mark
int findLowest(Student students[], int count) {
    int min = students[0].mark;
    int i;

    for (i = 1; i < count; i++) {
        if (students[i].mark < min) {
            min = students[i].mark;
        }
    }

    return min;
}

// Function to calculate class average
int calculateAverage(Student students[], int count) {
    int sum = 0;
    int i;

    for (i = 0; i < count; i++) {
        sum += students[i].mark;
    }

    return sum / count;
}

// Function to count passing students
int countPassing(Student students[], int count) {
    int passing = 0;
    int i;

    for (i = 0; i < count; i++) {
        if (students[i].mark >= PASS_MARK) {
            passing++;
        }
    }

    return passing;
}

// Function to add a student
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nStudent limit reached.\n");
        return;
    }

    printf("\nEnter student name: ");
    getchar();
    fgets(students[*count].name,
          sizeof(students[*count].name),
          stdin);

    // Remove newline from name
    students[*count].name[
        strcspn(students[*count].name, "\n")
    ] = '\0';

    printf("Enter marks: ");
    scanf("%d", &students[*count].mark);

    if (students[*count].mark < 0 ||
        students[*count].mark > 100) {

        printf("Invalid marks. Please enter marks between 0 and 100.\n");
        return;
    }

    (*count)++;

    printf("Student added successfully.\n");
}

// Main function
int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    printf("=====================================\n");
    printf("     STUDENT GRADE BOOK MANAGER\n");
    printf("=====================================\n");

    while (1) {

        printf("\n----------- MENU -----------\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Find Highest Mark\n");
        printf("4. Find Lowest Mark\n");
        printf("5. Calculate Class Average\n");
        printf("6. Count Passing Students\n");
        printf("7. Display Complete Analysis\n");
        printf("8. Exit\n");
        printf("----------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent(students, &count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                if (count == 0) {
                    printf("\nNo student records available.\n");
                } else {
                    printf("\nHighest Mark: %d\n",
                           findHighest(students, count));
                }
                break;

            case 4:
                if (count == 0) {
                    printf("\nNo student records available.\n");
                } else {
                    printf("\nLowest Mark: %d\n",
                           findLowest(students, count));
                }
                break;

            case 5:
                if (count == 0) {
                    printf("\nNo student records available.\n");
                } else {
                    printf("\nClass Average: %d\n",
                           calculateAverage(students, count));
                }
                break;

            case 6:
                if (count == 0) {
                    printf("\nNo student records available.\n");
                } else {
                    printf("\nPassing Students: %d\n",
                           countPassing(students, count));
                }
                break;

            case 7:
                if (count == 0) {
                    printf("\nNo student records available.\n");
                } else {
                    printf("\n===== COMPLETE ANALYSIS =====\n");

                    printf("Highest Mark   : %d\n",
                           findHighest(students, count));

                    printf("Lowest Mark    : %d\n",
                           findLowest(students, count));

                    printf("Class Average  : %d\n",
                           calculateAverage(students, count));

                    printf("Passing Students: %d\n",
                           countPassing(students, count));

                    printf("Total Students : %d\n",
                           count);
                }
                break;

            case 8:
                printf("\nThank you for using Student Grade Book Manager!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
