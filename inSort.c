// This program implements the insertion sort algorithm to sort an array of integers in ascending order.
#include <stdio.h>

/**
 * Sorts an array of integers in ascending order using the insertion sort algorithm.
 * 
 * @param A The array to be sorted.
 * @param n The number of elements in the array.
 */
int inSort(int A[], int n){

    int chave, j;
    
    for (int i = 1; i < n; i++)
    {
        chave = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > chave)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = chave;
    }

}

/**
 * The main function initializes an array of integers, sorts it using the inSort function, and prints the sorted array.
 */
int main()
{
    int A[6] = {5, 8, 4, 7, 1, 3};
    int n = 6;
    inSort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}
