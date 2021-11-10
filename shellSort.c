#include <stdio.h>

void printArray(int a[], int n);

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort(int a[], int lo, int hi) {
   int hvals[8] = {701, 301, 132, 57, 23, 10, 4, 1};
   int g, h, start, i, j, val;
   // printf("\nIn sort\n");
   for (g = 0; g < 8; g++) {
      h = hvals[g];
      start = lo + h;
      for (i = start+1; i <= hi; i++) {   // Should be i = start
         val = a[i];
         for (j = i; j >= start; j -= h) {
            if (val >= a[j-h]) break;
            a[j] = a[j-h];
         }
         a[j] = val;
      }
      // printArray(a, 10);
   }
   // printf("Finished sort\n\n");
}

void printArray(int a[], int n) {
   printf("{");
   for (int i = 0; i < n-1; i++) printf("%d, ", a[i]);
   if (n > 0) printf("%d}", a[n-1]);
   printf("\n");
}

void arrayCmp(int og[], int correct[], int a[], int n) {
   for (int i = 0; i < n; i++) {
      if (correct[i] != a[i]) {
         printf("Error for array: ");
         printArray(og, 10);
         printf("Result obtained from shellSort: ");
         printArray(a, 10);
         printf("\n");
      }
   }
}

void permutation(int correct[], int a[], int start, int end) {
   if (start == end) {
      int tmp[10] = {a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]};
      // printArray(a,10);
      shellSort(tmp,0,9);
      arrayCmp(a, correct, tmp, 10);
   }
   for(int i = start; i <= end; i++) {
        swap((a+i), (a+start));
        permutation(correct, a, start+1, end);
        swap((a+i), (a+start));
    }
}

// Finds all permutations of array a and executes shellsort on them.
// Prints out if there's an error
int main(void) {
   // int a[10] = {5,3,9,6,4,2,9,8,1,7};
   int correct[10] = {0,1,2,3,4,5,6,7,8,9};
   int a[10] = {0,1,2,3,4,5,6,7,8,9};
   permutation(correct, a, 0, 9);
   // printArray(a, 10);
   // shellSort(a,0,9);
   // printArray(a, 10);
   return 0;
}