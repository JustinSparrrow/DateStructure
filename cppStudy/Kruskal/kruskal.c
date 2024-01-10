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
    int start;
    int end;
    int weight;
}Edge;

Edge* initEdge(Graph* G){
    int index = 0;
    Edge* edge = (Edge*) malloc(sizeof (Edge)* G->arcNum);
    for(int i = 0; i < G->vexNum; i++){
        for(int j = i + 1; j < G->vexNum; j++){
            if(G->arcs[i][j] != MAX) {
                edge[index].start = i;
                edge[index].end = j;
                edge[index].weight = G->arcs[i][j];
                index++;
            }
        }
    }
    return edge;
}

void sortEdge(Edge* edge, Graph* G){
    for(int i = 0; i < G->arcNum-1; i++){
        for(int j = 0; j < G->arcNum - i - 1; j++){
            if(edge[j].weight > edge[j+1].weight){
                Edge temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
            }
        }
    }
}

void kruskal(Graph* G){
    int* connected = (int*) malloc(sizeof (int)* G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        connected[i] = i;
    }
    Edge* edge = initEdge(G);
    sortEdge(edge, G);
    for(int i = 0; i < G->arcNum; i++){
        int start = connected[edge[i].start];
        int end = connected[edge[i].end];
        if(start != end){
            printf("v%c --> v%c weight = %d\n", G->vexs[edge[i].start], G->vexs[edge[i].end], edge[i].weight);
            for(int j = 0; j < G->vexNum; j++){
                if(connected[j] == end){
                    connected[j] = start;
                }
            }
        }
    }
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
        if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visited[i]){
            DFS(G, visited, i);
        }
    }
}

int main(){
    Graph* G = initGraph(6);
    int* visited = (int*) malloc(sizeof (int )* G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = 0;
    }
    int arcs[6][6] = {
            0,6,1,5,MAX,MAX,
            6,0,5,MAX,3,MAX,
            1,5,0,5,6,4,
            5,MAX,5,0,MAX,2,
            MAX,3,6,MAX,0,6,
            MAX,MAX,4,2,6,0
    };
    createGraph(G, "123456", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    kruskal(G);
    return 0;
}