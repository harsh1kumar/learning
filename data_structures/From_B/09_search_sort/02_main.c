#include <stdio.h>
#include "02_selection_sort.h"

int main()
{
        int arr[] = {25,44,-3,20,1,65,-10};
        int i;

        for (i=0; i<(sizeof arr/sizeof arr[0]); ++i)
                printf("%d ", arr[i]);
        printf("\n");

        selection_sort(arr, sizeof arr/sizeof arr[0]);

        for (i=0; i<(sizeof arr/sizeof arr[0]); ++i)
                printf("%d ", arr[i]);
        printf("\n");

        return 0;
}

