#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Defining the structure for a student
typedef struct {
    int id;
    char name[50];
    float marks;
    float assignmentMarks;
    char grade;
    int isAssignmentCompleted;
} Student;

// Function to assign grade based on marks
char assignGrade(float marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 75) return 'B';
    else if (marks >= 50) return 'C';
    else return 'F'; // Fail
}

// Function to sort students by marks and name
void sortStudents(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks || 
                (students[j].marks == students[j + 1].marks && strcmp(students[j].name, students[j + 1].name) > 0)) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to calculate and display class average marks
float calculateClassAverage(Student students[], int n) {
    float totalMarks = 0;
    for (int i = 0; i < n; i++) {
        totalMarks += students[i].marks;
    }
    return totalMarks / n;
}

// Function to display student details
void displayStudents(Student students[], int n) {
    printf("\nStudent Results (Sorted by Marks):\n");
    printf("ID\tName                Marks   Assignment Marks    Assignment Completed    Grade\n");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-18s %-7.2f %-18.2f %-21s     %-7c\n",
               students[i].id, students[i].name, students[i].marks,
               students[i].assignmentMarks,
               students[i].isAssignmentCompleted ? "Yes" : "No",
               students[i].grade);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int n;

    // Input number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Input student details
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name); // Read a full line for the name

        printf("Marks (Out of 100): ");
        scanf("%f", &students[i].marks);

        printf("Assignment Marks: ");
        scanf("%f", &students[i].assignmentMarks);

        printf("Has the student completed the assignment? (1 for Yes, 0 for No): ");
        scanf("%d", &students[i].isAssignmentCompleted);

        // Calculate final grade based on marks and assignment completion
        students[i].grade = assignGrade(students[i].marks + (students[i].isAssignmentCompleted ? students[i].assignmentMarks : 0));
    }

    // Sort students by marks and name
    sortStudents(students, n);

    // Calculate and display class average
    float average = calculateClassAverage(students, n);
    printf("\nClass Average Marks: %.2f\n", average);

    // Display student details
    displayStudents(students, n);

    return 0;
}
