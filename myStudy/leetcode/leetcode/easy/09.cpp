//
// Created by 尛柒 on 2023/10/1.
//

#include <iostream>
using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
        int len = 0, n = x;
        while (n!=0){
            len++;
            n/=10;
        }
//        //test
//        cout << len << endl;
//        //end
        if(x>=0) {
            int s[12];
            n = x;
            for (int i = 0; i < len; i++) {
                s[i] = n % 10;
                n /= 10;
            }
            for (int i = 0, j = len - 1; i <= j; i++, j--) {
                if (s[i] == s[j]) continue;
                else return false;
            }
            return true;
        } else return false;
    }
};


题解：https://blog.csdn.net/qq_74688865/article/details/133574894
