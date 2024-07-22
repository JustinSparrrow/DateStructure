#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        double mid = 0;
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        std::sort(nums1.begin(), nums1.end());
        if(nums1.size()%2!=0)
            mid = nums1[nums1.size()/2];
        else
            mid = (nums1[nums1.size()/2]+nums1[nums1.size()/2-1])*1.00000/2;
        return mid;
    }
};

*//去看题解
