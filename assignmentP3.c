#include <stdio.h>

#define MAX_AMBULANCES 100

// Function prototypes
void inputDistances(int distances[], int *count);
void selectionSort(int distances[], int count);
int assignNearestAmbulance(int distances[], int count);

int main() {
    int distances[MAX_AMBULANCES];
    int count = 0;

    // Input distances of ambulances
    inputDistances(distances, &count);

    // Sort distances using selection sort
    selectionSort(distances, count);

    // Display sorted distances
    printf("Sorted: [");
    for (int i = 0; i < count; i++) {
        printf("%d", distances[i]);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Assign the nearest ambulance
    int nearestDistance = assignNearestAmbulance(distances, count);
    printf("Nearest Ambulance Assigned: Distance %d km\n", nearestDistance);

    return 0;
}

// Function to input distances of ambulances
void inputDistances(int distances[], int *count) {
    printf("Enter number of ambulances: ");
    scanf("%d", count);

    printf("Enter distances (in km): ");
    for (int i = 0; i < *count; i++) {
        scanf("%d", &distances[i]);
    }
}

// Function to sort distances using selection sort
void selectionSort(int distances[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (distances[j] < distances[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            int temp = distances[i];
            distances[i] = distances[minIndex];
            distances[minIndex] = temp;
        }
    }
}

// Function to assign the nearest ambulance
int assignNearestAmbulance(int distances[], int count) {
    if (count > 0) {
        return distances[0]; // The first element is the nearest after sorting
    }
    return -1; // No ambulances available
}
