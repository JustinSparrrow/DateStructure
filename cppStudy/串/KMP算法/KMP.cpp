//
// Created by moqi on 2023/11/16.
//
#include <iostream>
#include <string>
using namespace std;

// 计算“next”数组的函数
void get_next(string T, int next[]) {
    int i = 0, j = -1;
    next[0] = -1;
    // 循环计算“next”数组
    while (i < T.length()) {
        // 如果位置i和j处的字符相同
        if (j == -1 || T[i] == T[j]) {
            ++i; ++j;
            next[i] = j;    // 设置位置i的“next”值
        } else {
            j = next[j];    // 将j移动到前一个位置
        }
    }
}

int Index_KMP(string S, string T, int next[]) {
    int i = 0, j = 0;
    // 循环遍历文本和模式进行匹配
    while (i < S.length() && j < T.length()) {
        // 如果位置i和j出的字符相同
        if (j == -1 || S[i] == T[j]) {
            ++i; ++j;
        } else {
            j = next[j];    //根据“next”数组将j移动到前一个位置
        }
    }
    if (j == T.length())
        return i - j;
    else
        return -1; // indicates no match found
}

void test_KMP() {
    string text = "ababcababcabcabc";
    string pattern = "abcabc";
    int next[pattern.length()];
    get_next(pattern, next);

    int index = Index_KMP(text, pattern, next);

    if (index != -1) {
        cout << "Pattern found at index: " << index << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }
}
