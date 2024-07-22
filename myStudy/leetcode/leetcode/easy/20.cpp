#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
    bool isValid(string s){
        stack<char> charStack;  //使用栈来追踪括号的顺序
        unordered_map<char,char> map = {{')', '('},{']','['},{'}','{'}};    //定义括号的映射关系

        //遍历字符串中的每个字符
        for(char c : s){
            //如果是右括号
            if(map.find(c)!=map.end()){
                char topElement = charStack.empty() ? '#' : charStack.top();    //获取栈顶元素，如果栈为空就用‘#’代替
                charStack.pop();

                if(topElement!=map[c]){
                    return false;
                }
            }
            else
                charStack.push(c);
        }
        return charStack.empty();
    }
};


题解：https://blog.csdn.net/qq_74688865/article/details/133580518?spm=1001.2014.3001.5501
