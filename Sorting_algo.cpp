/* ------------------------------ Quuick Sort  ------------------------------ */

//   Best case = Average case = O(nlogn)
//   Worst case = O(n^2)  {One sub-array is always empty and another sub-array contains n - 1 elements. }
//   space complexity of merge sort is O(logn)

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int z = *a;
    *a = *b;
    *b = z;
}

void QuickSort(int *arr, int start, int end)
{
    if (end > start)
    {
        int p = arr[end];
        int i = start - 1, j = start;
        while (j < end && j >= i)
        {
            if (arr[j] <= p)
            {
                i++;
                swap(arr + i, arr + j);
            }
            j++;
        }
        i++;
        swap(arr + i, arr + end);
        QuickSort(arr, start, i - 1);
        QuickSort(arr, i + 1, end);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    printf("Before Sorting Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    QuickSort(arr, 0, n - 1);

    printf("After Quick Sort Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
// --------------------------------------------- END ---------------------------------------------



/* ------------------------------ Merge Sort  ------------------------------ */

//   Best case = Average case = Worst case = O(nlogn)
//   space complexity of merge sort is O(n)

#include <stdio.h>
#include <stdlib.h>

void Merge(int *arr, int start, int mid, int end)
{
    int x = mid - start + 1;
    int y = end - mid;
    int a[x], b[y];
    for (int i = 0; i < x; i++)
        a[i] = arr[start + i];
    for (int i = 0; i < y; i++)
        b[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = start;
    while (i < x && j < y)
    {
        if (a[i] >= b[j])
        {
            arr[k++] = b[j++];
        }
        else
        {
            arr[k++] = a[i++];
        }
    }
    while (i < x)
        arr[k++] = a[i++];
    while (j < y)
        arr[k++] = b[j++];
}

void Mergesort(int *arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    Mergesort(arr, start, mid);
    Mergesort(arr, mid + 1, end);
    Merge(arr, start, mid, end);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    printf("Before Sorting Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    Mergesort(arr, 0, n - 1);

    printf("After Merge Sort Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
// --------------------------------------------- END ---------------------------------------------



/* ------------------------------ Insertion Sort  ------------------------------ */

//   Average case = Worst case: O(n^2)
//   Best case = O(n)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    printf("Before Sorting Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int i, j, curr;
    for (int i = 1; i < n; i++)
    {
        curr = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > curr))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }

    printf("After Insertion Sort Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
// --------------------------------------------- END ---------------------------------------------



/* ------------------------------ Bubble Sort  ------------------------------ */

// TC:  Best case = Average case = Worst case: O(n^2)
// TC:  Best case = O(n)

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int z = *a;
    *a = *b;
    *b = z;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    printf("Before Sorting Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    int z = 0;
    for (int i = 0; i < n; i++)
    {
        int x = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);
                z++;
                x = 0;
            }
        }
        if (x)
            break;
    }
    // printf("%d \n", z);
    printf("After Bubble Sort Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
// --------------------------------------------- END ---------------------------------------------



/* ------------------------------ Selection Sort  ------------------------------ */

//   Best case = Average case = Worst case = O(n^2)

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int z = *a;
    *a = *b;
    *b = z;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    printf("Before Sorting Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
                min_ind = j;
        }
        swap(arr + i, arr + min_ind);
    }

    printf("After Selection Sort Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
// --------------------------------------------- END ---------------------------------------------
