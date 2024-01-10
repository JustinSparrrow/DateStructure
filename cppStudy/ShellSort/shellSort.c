#include <stdio.h>

void printArray(int array[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void shellSort(int array[], int length, int step){
    for(int i = 0; i < length; i++){
        for(int j = i+step; j < length; j += step){
            for(int k = i; k < j; k+= step){
                if(array[j] < array[k]){
                    int temp = array[j];
                    for(int l = j-step; l >= k; l-=step){
                        array[l+step] = array[l];
                    }
                    array[k] = temp;
                }
            }
        }
    }
}

int main(){
    int array[10] = {49,38,65,97,76,13,27,49,55,4};
    int steps[3] = {5,3,1};
    for(int i = 0; i < 3; i++){
        shellSort(array, 10, steps[i]);
        printArray(array,10);
    }
    return 0;
}