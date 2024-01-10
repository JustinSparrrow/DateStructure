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

typedef struct Edge{
    char vex;
    int weight;
}Edge;

/**
 * 当edge.weight = 0时，代表顶点加入U集合中
 */

Edge* initEdge(Graph* G, int index){
    Edge* edge = (Edge*) malloc(sizeof (Edge)* G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        edge[i].vex = G->vexs[index];
        edge[i].weight = G->arcs[index][i];
    }
    return edge;
}

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
        if(G->arcs[index][i] >= 1 && G->arcs[index][i] != MAX && !visited[i]){
            DFS(G, visited, i);
        }
    }
}

void floyd(Graph* G){
    int d[G->vexNum][G->vexNum];
    int p[G->vexNum][G->vexNum];
    for(int i = 0; i < G->vexNum; i++){
        for(int j = 0; j < G->vexNum; j++){
            d[i][j] = G->arcs[i][j];
            if(G->arcs[i][j] > 0 && G->arcs[i][j] != MAX){
                p[i][j] = i;
            } else {
                p[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < G->vexNum; i++){
        for(int j = 0; j < G->vexNum; j++){
            for(int k = 0; k < G->vexNum; k++){
                if (d[j][i] + d[i][k] < d[j][k]){
                    d[j][k] = d[j][i] + d[i][k];
                    p[j][k] = p[i][k];
                }
            }
        }
    }
    for(int i = 0; i < G->vexNum; i++){
        for(int j = 0; j < G->vexNum; j++){
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < G->vexNum; i++){
        for(int j = 0; j < G->vexNum; j++){
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}

int main(){
    Graph* G = initGraph(4);
    int* visited = (int*) malloc(sizeof (int )* G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = 0;
    }
    int arcs[4][4] = {
            0,1,MAX,3,
            1,0,2,2,
            MAX,2,0,8,
            3,2,8,0
    };
    createGraph(G, "1234", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    floyd(G);
    return 0;
}