#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution {
public:
    int search(const vector<int>& nums, int target) {
        int leftIdx = 0;
        int rightIdx = nums.size() - 1;

        if (nums[leftIdx] == target) {
            return leftIdx;
        }

        if (nums[rightIdx] == target) {
            return rightIdx;
        }

        while (leftIdx <= rightIdx) {
            int midIdx = leftIdx + (rightIdx - leftIdx)/2;

            if (target == nums[midIdx]) {
                return midIdx;
            } else if (target < nums[midIdx]) {
                rightIdx = midIdx - 1;
            } else {
                leftIdx = midIdx + 1;
            }
        }
        return -1; 
    }
};

int getAnswer(const vector<int>& nums, int target) {
    Solution solution;
    
    return solution.search(nums, target);
}

int main() {
    assert(4 == getAnswer({-1,0,3,5,9,12}, 9));
    assert(-1 == getAnswer({-1,0,3,5,9,12}, 4));
    assert(1 == getAnswer({-1,0,3,5,9,12}, 0));
    assert(0 == getAnswer({5}, 5));
}