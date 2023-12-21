//
// Created by Lenovo on 2023/12/19.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Graph{
    vector<char> vexs;  //顶点数组
    vector<vector<int>> arcs;   //邻接矩阵
    int vexNum;     //顶点数量
    int arcNUm;     //边数量

    vector<bool> visited;
};

Graph* initGraph(int vexNum){
    Graph *G = new Graph();

    //初始化顶点数量
    G->vexs.resize(vexNum);
    //初始化邻接矩阵
    G->arcs.resize(vexNum, vector<int>(vexNum, 0));

    G->vexNum = vexNum;
    G->arcNUm = 0;

    G->visited.resize(vexNum, false);

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

void BFS(Graph *G, char v){
    queue<char> Q;
    cout << v << '\t';
    int index = -1;
    for(int i = 0; i < G->vexNum; ++i){
        if(G->vexs[i] == v){
            index = i;
            break;
        }
    }
    if(index != -1){
        Q.push(v);
        G->visited[index] = true;
        while (!Q.empty()){
            char front = Q.front();
            Q.pop();
            for(int i = 0; i < G->vexNum; ++i){
                if(G->arcs[index][i] != 0 && !G->visited[i]){
                    cout << G->vexs[i] << '\t';
                    Q.push(G->vexs[i]);
                    G->visited[i] = true;
                }
            }
        }
    }
}

void BFSTraverse(Graph *G){
    for(int i = 0; i < G->vexNum; ++i){
        G->visited[i] = false;
    }
    queue<char> Q;
    for(int i = 0; i < G->vexNum; ++i){
        if(!G->visited[i]){
            Q.push(G->vexs[i]);
            G->visited[i] = true;
            while ((!Q.empty())){
                char v = Q.front();
                Q.pop();
                BFS(G,v);
            }
        }
    }
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
    BFSTraverse(G);

    deleteGraph(G);
}
