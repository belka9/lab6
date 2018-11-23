#include <stdio.h>

#define SIZE_ARR 2000000

static void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void qsort(int arr[], int first, int last)
{
    if (first < last)
    {
        int left = first;
        int right = last;
        int  middle = arr[(left + right) / 2];
        do
        {
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right)
            {
                swap(&arr[right], &arr[left]);
                left++;
                right--;
            }
        } while (left <= right);
        qsort(arr, first, right);
        qsort(arr, left, last);
    }
}

int main() {
    int n = 0;

    scanf("%d", &n);
    int arr[SIZE_ARR] = {0};

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, 0, n - 1);

    for (int l = 0; l < n; l++)
        printf("%d ", arr[l]);

    return 0;
}