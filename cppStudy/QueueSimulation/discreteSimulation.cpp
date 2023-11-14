//
// Created by moqi on 2023/11/5.
//
#include <bits/stdc++.h>
using namespace std;

struct Event{
    int OccurTime;  //事件发生时刻
    int NType;  //事件类型，0表示到达时间，1至4表示四个窗口的离开事件
};
struct QElemType{
    int ArrivalTime;    //到达时刻
    int Duration;   //办理事务所需时间
};

Event en;   //事件
QElemType customer; //客户记录
int TotalTime, CustomerNum; //累计客户逗留时间，客户数量

//依事件a的发生时刻<或>或=事件b的发生时候分别返回-1或1或0
int cmp(Event a, Event b){
    if(a.OccurTime<b.OccurTime){
        return -1;
    }
    else if(a.OccurTime == b.OccurTime){
        return 0;
    }
    else
        return 1;
}