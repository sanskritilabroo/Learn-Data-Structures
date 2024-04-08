#include <stdio.h>

void delete_smaller_elements(int arr[], int n, int k) {
  // Initialize the current and next element indices.
  int i = 0, j = 1;

  // Iterate through the array.
  while (j < n) {
    // If the current element is smaller than the next element, delete it.
    if (arr[i] < arr[j]) {
      for (int m = i; m < n - 1; m++) {
        arr[m] = arr[m + 1];
      }
      n--;
      k--;
    } else {
      // Otherwise, move on to the next element.
      i++;
      j++;
    }

    // If k is 0, we are done.
    if (k == 0) {
      break;
    }
  }
}

int main() {
  // Initialize the array.
  int n;
  printf("Enter size of array:\n");
  scanf("%d", &n);
  int arr[n]; //= {20, 10, 25, 30, 40};
  printf("Enter values:\n");
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  int k;
  printf("Enter value of k:\n");
  scanf("%d", &k);

  // Delete the k elements.
  delete_smaller_elements(arr, n, k);

  // Print the resulting array.
  for (int i = 0; i < n-k; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}