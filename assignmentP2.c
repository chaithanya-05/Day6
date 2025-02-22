#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

// Structure to hold product details
struct Product {
    char name[NAME_LENGTH];
    int price;
};

// Function prototypes
void inputProducts(struct Product products[], int *count);
void sortProductsByPrice(struct Product products[], int count);
void displayCheapestAndMostExpensive(const struct Product products[], int count);
int binarySearchByName(const struct Product products[], int count, const char *name);

int main() {
    struct Product products[MAX_PRODUCTS];
    int count = 0;

    // Input product records
    inputProducts(products, &count);

    // Sort products by price
    sortProductsByPrice(products, count);

    // Display sorted products
    printf("Sorted by Price:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%d)\n", products[i].name, products[i].price);
    }

    // Display cheapest and most expensive products
    displayCheapestAndMostExpensive(products, count);

    // Search for a product by name
    char productName[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", productName);
    int index = binarySearchByName(products, count, productName);
    if (index != -1) {
        printf("Found: %s (Price: %d)\n", products[index].name, products[index].price);
    } else {
        printf("Product '%s' not found.\n", productName);
    }

    return 0;
}

// Function to input product records
void inputProducts(struct Product products[], int *count) {
    printf("Enter number of products: ");
    scanf("%d", count);
    getchar(); // To consume the newline character

    for (int i = 0; i < *count; i++) {
        printf("Enter Product Name and Price (e.g., Laptop 50000): ");
        scanf("%49s %d", products[i].name, &products[i].price);
    }
}

// Function to sort products by price in ascending order
void sortProductsByPrice(struct Product products[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (products[j].price > products[j + 1].price) {
                struct Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

// Function to display the cheapest and most expensive products
void displayCheapestAndMostExpensive(const struct Product products[], int count) {
    if (count > 0) {
        printf("Cheapest Product: %s (%d)\n", products[0].name, products[0].price);
        printf("Most Expensive Product: %s (%d)\n", products[count - 1].name, products[count - 1].price);
    } else {
        printf("No products available.\n");
    }
}

// Function to perform binary search by product name
int binarySearchByName(const struct Product products[], int count, const char *name) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cmp = strcmp(products[mid].name, name);
        if (cmp == 0) {
            return mid; // Found
        } else if (cmp < 0) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Not found
}
