//O(log n) 时间复杂度通常出现在基于分治或二分的算法中。一些常见的算法和数据结构具有O(log n) 时间复杂度，其中 n 代表输入规模。
//1. **二分查找 (Binary Search)**: 在有序数组中查找特定元素的时间复杂度是O(log n)。
//2. **树相关操作 (例如二叉搜索树)**: 在平衡二叉搜索树（如AVL树、红黑树）上进行搜索、插入和删除操作的平均时间复杂度为O(log n)。
//3. **堆操作 (例如堆排序)**: 在堆数据结构上插入和删除最小/最大元素的时间复杂度是O(log n)。
//4. **分治算法 (例如快速排序)**: 在每一次划分时，快速排序算法将数据划分为两部分，时间复杂度为O(log n)。
//这些算法利用了将输入规模对半分解的特性，每次操作都能将问题规模缩小为原来的一半，因此它们的时间复杂度是对数级别的。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
