//Adam Wheeler
//CS1 Torosdagli
//Lab 6

#include <stdio.h>
#include <stdlib.h>

typedef struct element{
int data;
int numswaps;
}element;

void selectionSort(int* arr, int size, element* swapCount) {
    int i, j, minIdx, totalSwaps = 0;
    for (i = 0; i < size; i++) {
        swapCount[i].data = arr[i];
        swapCount[i].numswaps = 0;
    }

    for (i = 0; i < size - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i){
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            for (int k = 0; k < size; k++) {
                if (swapCount[k].data == arr[i]) {
                    swapCount[k].numswaps++;
                } else if (swapCount[k].data == arr[minIdx]) {
                    swapCount[k].numswaps++;
                }
            }

            totalSwaps++;
        }
    }
    for (i = 0; i < size; i++) {
        printf("%d: %d\n", swapCount[i].data, swapCount[i].numswaps);
    }
    printf("Total Selection Sort swaps: %d\n", totalSwaps);
}



element* numSwapsBubbleSort(int* arr, int size) {
    element* swaps = (element*)malloc(sizeof(element) * size);
    if (swaps == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }

  for (int j = 0; j < size - 1; j++) {
      for (int k = 0; k < size - j - 1; k++) {
          if (swaps[k].data > swaps[k + 1].data) {
              element temp = swaps[k];
              swaps[k] = swaps[k + 1];
              swaps[k + 1] = temp;
              swaps[k].numswaps++;
              swaps[k+1].numswaps++; 
              int tempData = arr[k];
              arr[k] = arr[k + 1];
              arr[k + 1] = tempData;
          }
      }
  }
    return swaps;
}






void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int array1bubble[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n1 = sizeof(array1bubble) / sizeof(array1bubble[0]);
    int totalSwaps1 = 0;

   

    element *swapsBubble = numSwapsBubbleSort(array1bubble, n1);
    for(int i=0;i<n1;i++){
      printf("%d: %d\n", swapsBubble[i].data, swapsBubble[i].numswaps);
      totalSwaps1+=swapsBubble[i].numswaps;
    }
    totalSwaps1=totalSwaps1/2;
    printf("Total Bubble swaps for array 1: %d\n", totalSwaps1);
    printArray(array1bubble, n1);
    printf("\n");
    totalSwaps1=0;
    int array1selection[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    element *swapSelection = (element*)malloc(n1*sizeof(element));
  selectionSort(array1selection, n1, swapSelection);
  printf("\n");
  

    int array2bubble[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};int array2selection[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n2 = sizeof(array2bubble) / sizeof(array2bubble[0]);
    int totalSwaps2 = 0;
    element *swapsBubble2 = numSwapsBubbleSort(array2bubble, n2);
    for(int i=0;i<n2;i++){
      printf("%d: %d\n", swapsBubble2[i].data, swapsBubble2[i].numswaps);
      totalSwaps2+=swapsBubble2[i].numswaps;
    }
  totalSwaps2=totalSwaps2/2;
    printf("Total Bubble swaps for array 2: %d\n", totalSwaps2);
    printArray(array2bubble, n2);
    printf("\n");
    element *swapSelection2 = (element*)malloc(n2*sizeof(element));
    selectionSort(array2selection, n2, swapSelection2);
    free(swapSelection2);
    free(swapSelection);
    free(swapsBubble);
    free(swapsBubble2);
    return 0;
}
