#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    int romanToInt(string s){
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            sum+= exchangeRtoI(s[i]);
            sum+= specialRtoI(s,i);
        }
        return sum;
    }
    int exchangeRtoI(char c){
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    int specialRtoI(string s, int i){
        if(i<s.length()-1) {
            if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) return -2;
            else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) return -20;
            else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) return -200;
        }
        return 0;
    }
};