#include <stdlib.h>
#include <stdio.h>

int comp(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

void find_diff_tuples(int *arr, int N, int target, int** tuples, int *t_count){
    *t_count = 0;

    qsort(arr, N, sizeof(int), comp);

    *tuples = malloc(N*2 * sizeof(int));

    int left = 0;
    int right = 1;

    while(right<N){
        int diff = arr[right]-arr[left];

        if(diff == target){
            (*tuples)[*t_count*2] = arr[left];
            (*tuples)[*t_count*2+1] = arr[right];
            (*t_count)++;
            left++;
            right++;
        }
        else if(diff < target) right++;
        else{
            left++;
            if(left == right) right++;
        }
        
    }
    free(*tuples);
    if(*t_count == 0) *tuples = NULL;
}