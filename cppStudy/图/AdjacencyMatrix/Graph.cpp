//
// Created by Lenovo on 2023/12/19.
//
#include <iostream>
#include <vector>
using namespace std;

struct Graph{
    vector<char> vexs;  //顶点数组
    vector<vector<int>> arcs;   //邻接矩阵
    int vexNum;     //顶点数量
    int arcNUm;     //边数量
};

Graph* initGraph(int vexNum){
    Graph *G = new Graph();

    //初始化顶点数量
    G->vexs.resize(vexNum);
    //初始化邻接矩阵
    G->arcs.resize(vexNum, vector<int>(vexNum, 0));

    G->vexNum = vexNum;
    G->arcNUm = 0;

    return G;
}

void deleteGraph(Graph* G){
    delete G;
}

void createGraph(Graph* G, vector<char>* vexs, vector<vector<int>>* arcs){
    for(int i = 0; i < G->vexNum; i++){
        G->vexs[i] = (*vexs)[i];
        for(int j = 0; j < G->vexNum; j++){
            G->arcs[i][j] = (*arcs)[i][j];
            if(G->arcs[i][j] != 0)
                G->arcNUm++;
        }
    }
    G->arcNUm /= 2;
}

void DFS(Graph* G, int* visited, int index){
    cout << G->vexs[index] << '\t';

}

int main(){
    Graph* G = initGraph(5);
    vector<char> vexs{'A','B', 'C', 'D', 'E'};
    vector<vector<int>> arcs = {
            {0,1,1,1,0},
            {1,0,1,1,1},
            {1,1,0,0,0},
            {1,1,0,0,1},
            {0,1,0,1,0}
    };
    createGraph(G, &vexs, &arcs);
}