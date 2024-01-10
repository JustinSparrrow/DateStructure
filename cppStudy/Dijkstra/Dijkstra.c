//
// Created by 尛柒 on 2024/1/10.
//
#include <stdio.h>
#include <stdlib.h>

/**
 * 图顶点之间不同的，那么邻接矩阵的值为MAX
 * 如果顶点是自己，那么值为0
 */
#define MAX 32767

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
            if(G->arcs[i][j] != 0 && G->arcs[i][j] != MAX)
                G->arcNum++;
        }
    }
    G->arcNum /= 2;
}

void DFS(Graph* G, int* visited, int index){
    printf("%c\t", G->vexs[index]);
    visited[index] = 1;
    for(int i = 0; i < G->vexNum; i++){
        if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visited[i]){
            DFS(G, visited, i);
        }
    }
}

int getMin(int* d, int* s, Graph* G){
    int min = MAX;
    int index;
    for(int i = 0; i < G->vexNum; i++){
        if(!s[i] && d[i] < min){
            min = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(Graph* G, int index){
    int* s = (int*) malloc(sizeof (int )* G->vexNum);
    int* p = (int*) malloc(sizeof (int )* G->vexNum);
    int* d = (int*) malloc(sizeof (int )* G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        if(i == index)
            s[i] = 1;
        else
            s[i] = 0;
    }
    for(int i = 0; i < G->vexNum; i++){
        if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX){
            p[i] = index;
        } else {
            p[i] = -1;
        }
    }
    for(int i = 0; i < G->vexNum; i++){
        if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX){
            d[i] = G->arcs[index][i];
        } else {
            d[i] = MAX;
        }
        if(i == index) d[i] = 0;
    }
    for(int i = 0; i < G->vexNum; i++){
        printf("s = %d, p = %d, d = %d\n", s[i], p[i], d[i]);
    }
    for(int i = 0; i < G->vexNum; i++){
        int index = getMin(d, s, G);
        s[index] = 1;
        for(int j = 0; j < G->vexNum; j++){
            for(int j = 0; j < G->vexNum; j++){
                if(!s[j] && d[index] + G->arcs[index][j] < d[j]){
                    d[j] = d[index] + G->arcs[index][j];
                    p[j] = index;
                }
            }
        }
    }
    for(int i = 0; i < G->vexNum; i++){
        printf("s' = %d, p' = %d, d' = %d\n", s[i], p[i], d[i]);
    }
}

int main(){
    Graph* G = initGraph(7);
    int* visited = (int*) malloc(sizeof (int )* G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = 0;
    }
    int arcs[7][7] = {
            0,12,MAX,MAX,MAX,16,14,
            12,0,10,MAX,MAX,7,MAX,
            MAX,10,0,3,5,6,MAX,
            MAX,MAX,3,0,4,MAX,MAX,
            MAX,MAX,5,4,0,2,8,
            16,7,6,MAX,2,0,9,
            14,MAX,MAX,MAX,8,9,0
    };
    createGraph(G, "1234567", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    dijkstra(G, 4);
    return 0;
}