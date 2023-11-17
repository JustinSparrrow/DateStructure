#include <iostream>
#include <string>
using namespace std;

int Index(string S, string T){
    int i = 0, j = 0;
    while (i < S.length() && j < T.length()){
        //如果两个该位置两个字符相同，比较后续字符
        if(S[i] == T[j]){
            ++i; ++j;   //比较后续字符
        } else {
            i = i-j+1;  j = 0;  //更新
        }
    }
    if(j >= T.length()) return i-j;   //返回匹配的起始位置
    else return -1; //没有找到匹配
}

int main() {
    string S = "ababcabcacbab";
    string T = "abcac";
    int result = Index(S, T);
    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found" << endl;
    }
    return 0;
}
