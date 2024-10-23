#include <stdio.h>
#include <stdlib.h> // For malloc and free

void applyMedianFilter(int arr[], int size) {
    // Dynamically allocate memory for the result array
    int *result = (int *)malloc(size * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }

    result[0] = arr[0]; // First element remains unchanged
    result[size - 1] = arr[size - 1]; // Last element remains unchanged

    // Apply median filter to each element, except the first and last
    for (int i = 1; i < size - 1; i++) {
        // Extract the current window of three elements
        int window[3] = {arr[i-1], arr[i], arr[i+1]};
        
        // Sort the window to find the median
        for (int j = 0; j < 3 - 1; j++) {
            for (int k = 0; k < 3 - j - 1; k++) {
                if (window[k] > window[k + 1]) {
                    // Swap window[k] and window[k+1]
                    int temp = window[k];
                    window[k] = window[k + 1];
                    window[k + 1] = temp;
                }
            }
        }

        // The median is the middle value after sorting (window[1])
        result[i] = window[1];
    }

    // Print the filtered array
    printf("Filtered array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(result);
}

int main() {
    // Example array (from the exercise)
    int arr[] = {95, 91, 211, 97, 94, 99, 92, 96, 91, 91, 92, 91, 94};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Apply the median filter
    applyMedianFilter(arr, size);

    return 0;
}
