#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void my_qsort(int arr[], int first, int last){
    if (first < last)
    {
        int left = first;
        int right = last;
        int  middle = arr[(left + right) / 2];
        do{
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right){
                swap(&arr[right], &arr[left]);
                left++;
                right--;
            }
        } while (left <= right);
        my_qsort(arr, first, right);
        my_qsort(arr, left, last);
    }
}

int main() {
    int n = 0;

    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int)*n);
    if (arr == NULL)
        return 1;

    memset(arr, 0, sizeof(int)*n);// он с отрицательными не работает, выбрасывает null
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    my_qsort(arr, 0, n - 1);

    for (int l = 0; l < n; l++)
        printf("%d ", arr[l]);
    free(arr);
    return 0;

}

