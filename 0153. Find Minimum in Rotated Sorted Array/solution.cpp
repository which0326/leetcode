#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int findMin(const vector<int>& nums) {
        int leftIdx = 0;
        int rightIdx = nums.size() - 1;

        while (leftIdx < rightIdx) {
            int midIdx = leftIdx + (rightIdx - leftIdx) / 2;
            if (nums[midIdx] < nums[rightIdx]) {
                rightIdx = midIdx;
            } else {
                leftIdx = midIdx + 1;
            }
        }
        return nums[leftIdx];
    }
};

int getAnswer(const vector<int>& nums) {
    Solution solution;

	return solution.findMin(nums);
}

int main() {

	assert(1 == getAnswer({3,4,5,1,2}));
	assert(0 == getAnswer({4,5,6,7,0,1,2}));
	assert(11 == getAnswer({11,13,15,17}));
    assert(1 == getAnswer({2,1}));
    assert(1 == getAnswer({3,1,2}));
    
    return 0;
}
