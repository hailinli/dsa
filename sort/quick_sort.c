/*================================================================
*   Copyright (C) 2021 Xiaomi. All rights reserved.
*   
*   文件名称：quick_sort.c
*   创 建 者：LiHailin
*   创建日期：2021年05月20日
*   描    述：
*
================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// [)
void quick_sort(vector<int>& nums, int i, int j) {
    if (i >= j) return;

    int mid = (i + j) >> 1;
    auto ppos = partition(nums.begin() + i, nums.begin() + j, [nums, mid](const int num) {
            if (num < nums[mid]) return true; 
            return false;
            });
    int posOffset = ppos - nums.begin();
    quick_sort(nums, i, posOffset);
    quick_sort(nums, posOffset + 1, j);
}

void quick_sort(vector<int>& nums) {
    quick_sort(nums, 0, nums.size());
}

void show(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums{1,3,465,22,456,213,7675,1232};
    nums = {1,3};
    nums = {1};
    quick_sort(nums);
    show(nums);

    return 0;
}
