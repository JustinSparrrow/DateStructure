//
// Created by 尛柒 on 2024/1/11.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int* data;
    int length;
    int num;
}List;

List* initList(int length){
    List* list = (List*) malloc(sizeof (List));
    list->data = (int*) malloc(sizeof (int )* length);
    list->length = length;
    list->num = 0;
    return list;
}

void listAdd(int data, List* list){
    if(list->num >= list->length) return;
    list->data[list->num] = data;
    list->num = list->num + 1;
}

void printList(List* list){
    for(int i = 0; i < list->num; i++){
        printf("%d ",list->data[i]);
    }
    printf("\n");
}

int binarySearch(int key, List* list){
    int start = 0;
    int end = list->num-1;
    int mid;
    while (start <= end){
        mid = (start + end) / 2;
        if(list->data[mid] < key){
            start = mid + 1;
        }
        else if(list->data[mid] > key){
            end = mid - 1;
        }
        else
            return mid;
    }
    return -1;
}

int binarySearchRecursion(int key, List* list, int start, int end){
    if(start == end){
        if(list->data[start] == key){
            return start;
        }
        else{
            return -1;
        }
    }
    int mid = (start + end) / 2;
    if(list->data[mid] < key){
        return binarySearchRecursion(key, list, mid+1, end);
    }
    else if (list->data[mid] > key){
        return binarySearchRecursion(key, list, start, mid-1);
    }
    else {
        return mid;
    }
}

int main(){
    List* list = initList(9);
    listAdd(1, list);
    listAdd(2, list);
    listAdd(3, list);
    listAdd(4, list);
    listAdd(5, list);
    listAdd(6, list);
    listAdd(7, list);
    listAdd(8, list);
    listAdd(9, list);
    printList(list);
    printf("data %d in %d\n", 7, binarySearch(7, list));
    printf("data %d in %d\n", 2, binarySearchRecursion(2, list,0,list->num-1));
    return 0;
}