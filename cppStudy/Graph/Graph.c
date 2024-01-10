//
// Created by 尛柒 on 2024/1/10.
//
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

typedef struct Graph{
    char* vexs;
    int** arcs;
    int vexNum;
    int arcNum;
}Graph;

Graph* initGraph(int vexNum){
    Graph* G = (Graph*) malloc(sizeof (Graph));
    G->vexs = (char*) malloc(sizeof (char )* vexNum);
    G->arcs = (int**) malloc(sizeof (int*) * vexNum);
    for(int i = 0; i < vexNum; i++){
        G->arcs[i] = (int*) malloc(sizeof (int )* vexNum);
    }
    G->vexNum = vexNum;
    G->arcNum = 0;
    return G;
}

void createGraph(Graph* G, char* vexs, int* arcs){
    for(int i = 0; i < G->vexNum; i++){
        G->vexs[i] = vexs[i];
        for(int j = 0; j < G->vexNum; j++){
            G->arcs[i][j] = *(arcs + i * G->vexNum + j);
            if(G->arcs[i][j] != 0)
                G->arcNum++;
        }
    }
    G->arcNum /= 2;
}

void DFS(Graph* G, int* visited, int index){
    printf("%c\t", G->vexs[index]);
    visited[index] = 1;
    for(int i = 0; i < G->vexNum; i++){
        if(G->arcs[index][i] == 1 && !visited[i]){
            DFS(G, visited, i);
        }
    }
}

void BFS(Graph* G, int* visited, int index){
    Queue* Q = initQueue();
    printf("%c\t", G->vexs[index]);
    visited[index] = 1;
    enQueue(Q, index);
    while (!isEmpty(Q)){
        int i = deQueue(Q);
        for(int j = 0; j < G->vexNum; j++){
            if(G->arcs[i][j] == 1 && !visited[j]){
                printf("%c\t", G->vexs[j]);
                visited[j] = 1;
                enQueue(Q, j);
            }
        }
    }
}

int main(){
    Graph* G = initGraph(5);
    int* visited = (int*) malloc(sizeof (int)* G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = 0;
    }
    int arcs[5][5] = {
            0,1,1,1,0,
            1,0,1,1,1,
            1,1,0,0,0,
            1,1,0,0,1,
            0,1,0,1,0
    };
    createGraph(G, "ABCDE", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = 0;
    }
    BFS(G, visited, 0);
    printf("\n");
    return 0;
}