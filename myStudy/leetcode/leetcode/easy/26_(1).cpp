#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        unordered_set<int> numsSet;
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(isNotExist(numsSet, nums[i])){
                numsSet.insert(nums[i]);
                nums[index] = nums[i];
                index++;
            }
        }
        return numsSet.size();
    }
    bool isNotExist(unordered_set<int> numsSet, int num){
        return numsSet.count(num) == 0;
    }
};
