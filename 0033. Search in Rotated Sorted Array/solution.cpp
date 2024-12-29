#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int search(const vector<int>& nums, int target) {
        int leftIdx = 0;
        int rightIdx = nums.size() - 1;

        while (leftIdx <= rightIdx) {
            int midIdx = leftIdx + (rightIdx - leftIdx) / 2;

            if (nums[midIdx] == target) {
                return midIdx;
            }

            if (nums[leftIdx] <= nums[midIdx]) {
                if (nums[leftIdx] <= target && target < nums[midIdx]) {
                    rightIdx = midIdx - 1;
                } else {
                    leftIdx = midIdx + 1;
                }
            } else {
                if (nums[midIdx] < target && target <= nums[rightIdx]) {
                    leftIdx = midIdx + 1;
                } else {
                    rightIdx = midIdx - 1;
                }
            }
        }
        return -1; /* Not found */
    }
};

int getAnswer(const vector<int>& nums, int target) {
    Solution solution;

	return solution.search(nums, target);
}

int main() {

	assert(4 == getAnswer({4,5,6,7,0,1,2}, 0));
	assert(-1 == getAnswer({4,5,6,7,0,1,2}, 3));
	assert(-1 == getAnswer({1}, 0));
    assert(1 == getAnswer({3, 1}, 1));

    return 0;
}
