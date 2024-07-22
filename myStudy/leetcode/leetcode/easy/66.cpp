#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        digits[digits.size()-1] += 1;
        int carry = 0;
        for(int i = digits.size()-1; i >= 0; i--){
            digits[i] += carry;
            if(digits[i]>=10&&i!=0){
                digits[i] -= 10;
                carry = 1;
            }
            else if(digits[i]>=10&&i==0) {
                digits[i]-=10;
                digits.insert(digits.begin(), 1);
                carry = 0;
            }
            else
                carry=0;
        }
        return digits;
    }
};
