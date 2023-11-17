#include <iostream>
#include <string>
using namespace std;

int Index(string S, string T){
    int i = 0;
    while (i + T.length() <= S.length()){
        string temp = S.substr(i, T.length());
        if(temp == T){
            return i;
        } else {
            ++i;
        }
    }
    return -1;
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
