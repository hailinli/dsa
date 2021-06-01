/*================================================================
*   Copyright (C) 2021 Xiaomi. All rights reserved.
*   
*   文件名称：merge_sort.c
*   创 建 者：LiHailin
*   创建日期：2021年05月20日
*   描    述：
*
================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// []
void merge_sort(vector<int>& nums, int i, int j) {
    if (i == j) return;
    int mid = (i + j) >> 1;

    merge_sort(nums, i, mid);
    merge_sort(nums, mid+1, j);
    inplace_merge(nums.begin()+i, nums.begin()+mid+1, nums.begin()+j+1);
}

void merge_sort(vector<int>& nums) {
    merge_sort(nums, 0, nums.size()-1);
}

void show(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums{1,3,465,22,456,213,7675,1232};
    //nums = {1,3};
    //nums = {1};
    merge_sort(nums);
    show(nums);

    return 0;
}

