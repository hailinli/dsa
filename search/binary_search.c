/*================================================================
*   Copyright (C) 2021 Xiaomi. All rights reserved.
*   
*   文件名称：binary_serch.c
*   创 建 者：LiHailin
*   创建日期：2021年06月01日
*   描    述：
*
================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(const vector<int> nums, const int target) {
    int i = 0; 
    int j = nums.size();
    
    while (i < j) {
        //cout << i << j << endl;
        int mid = (i + j) >> 1;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }

    return -1;

}

void show(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums{1,3,465,22,456,213,7675,1232};
    sort(nums.begin(), nums.end());
    show(nums);
    cout << binary_search(nums, 455) << endl;
    cout << binary_search(nums, 213) << endl;

    return 0;
}

