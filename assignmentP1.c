#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Structure to hold student details
struct Student {
    int rollNo;
    char name[NAME_LENGTH];
    int marks;
};

// Function prototypes
void inputStudents(struct Student students[], int *count);
void sortStudentsByMarks(struct Student students[], int count);
void displayTopStudents(const struct Student students[], int count);
int binarySearchByRollNo(const struct Student students[], int count, int rollNo);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;

    // Input student records
    inputStudents(students, &count);

    // Sort students by marks
    sortStudentsByMarks(students, count);

    // Display sorted students
    printf("Sorted by Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%d)\n", students[i].name, students[i].marks);
    }

    // Display top 3 students
    displayTopStudents(students, count);

    // Search for a student's record by roll number
    int rollNoToSearch;
    printf("Enter Roll No to search: ");
    scanf("%d", &rollNoToSearch);
    int index = binarySearchByRollNo(students, count, rollNoToSearch);
    if (index != -1) {
        printf("Found: %s, Marks: %d\n", students[index].name, students[index].marks);
    } else {
        printf("Student with Roll No %d not found.\n", rollNoToSearch);
    }

    return 0;
}

// Function to input student records
void inputStudents(struct Student students[], int *count) {
    printf("Enter number of students: ");
    scanf("%d", count);
    getchar(); // To consume the newline character

    for (int i = 0; i < *count; i++) {
        printf("Enter Roll No, Name, Marks (e.g., 101 Alice 85): ");
        scanf("%d %49s %d", &students[i].rollNo, students[i].name, &students[i].marks);
    }
}

// Function to sort students by marks in descending order
void sortStudentsByMarks(struct Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to display the top 3 students
void displayTopStudents(const struct Student students[], int count) {
    printf("Top 3 Students:\n");
    for (int i = 0; i < count && i < 3; i++) {
        printf("%s (%d)\n", students[i].name, students[i].marks);
    }
}

// Function to perform binary search by roll number
int binarySearchByRollNo(const struct Student students[], int count, int rollNo) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (students[mid].rollNo == rollNo) {
            return mid; // Found
        } else if (students[mid].rollNo < rollNo) {
            right = mid - 1; // Search in the left half
        } else {
            left = mid + 1; // Search in the right half
        }
    }
    return -1; // Not found
}
