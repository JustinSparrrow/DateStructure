#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int cmp(ListNode* a,ListNode* b)
{
    return a->val<b->val;
}
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(!list1)  return list2;
        if(!list2)  return list1;

        vector<ListNode*>n;

        while (list1){
            n.push_back(list1);
            list1=list1->next;
        }
        while (list2){
            n.push_back(list2);
            list2=list2->next;
        }
        sort(n.begin(),n.end(), cmp);
        //test
//        for(int i = 0; i< n.size();i++)
//            cout << n[i];
        //end
        ListNode* list3 = new ListNode(n[0]->val);
        ListNode* current;
        ListNode* follow = list3;
        for(int i = 1; i < n.size(); i++){
            current = new ListNode(n[i]->val);
            follow->next=current;
            follow = current;
        }
        return list3;
    }
};


题解：https://blog.csdn.net/qq_74688865/article/details/133592978?spm=1001.2014.3001.5502
