#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i = 0; i < nums.size(); ){
            if(nums[i]==val){
                for(int j = i; j < nums.size()-1; j++){
                    nums[j]=nums[j+1];
                }
                nums.pop_back();
            }
            else
                i++;
        }
        return nums.size();
    }
};

/*
  #include <iostream>
  #include <vector>
  using namespace std;

  class Solution {
  public:
      int removeElement(vector<int>& nums, int val) {
          nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
          return nums.size();
      }
  };
*/
