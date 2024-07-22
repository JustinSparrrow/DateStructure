#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();  // 字符串的长度
        int max_length = 0;  // 新串的长度
        int left = 0, right = 0;  //左右两个索引

        unordered_set<char> new_str; // 使用集合来存储窗口内的字符

        while (right < n)
        {
            if (new_str.find(s[right]) == new_str.end())
                // find()函数返回一个迭代器，如果字符存在于集合中，迭代器将指向该字符；如果不在，迭代器将等于.end()，表示字符不在集合中
            {
                new_str.insert(s[right]);  // 写入没有的字符
                right++;  // 指针向右移
                max_length = max(max_length, right - left);  // 更新最大长度
            }
            else  // 即子字符串中有该字符
            {
                new_str.erase(s[left]);  // erase()函数将字符左侧连同本字符的集合部分全部删去
                left++;  //指针右移
            }
        }

        return max_length;
    }
};


题解：https://blog.csdn.net/qq_74688865/article/details/132787319
