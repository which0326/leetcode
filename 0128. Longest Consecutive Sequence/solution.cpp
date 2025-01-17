#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_set<int> numSet;

        for (int num: nums) {
            numSet.insert(num);
        }

        vector<int> uniqueNums(numSet.begin(), numSet.end()); // avoid TLE

        int longestConsecutiveSequence = 0;
        for (int num: uniqueNums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currNum = num;
                int currSeqLength = 1;
                while (numSet.find(currNum + 1) != numSet.end()) {
                    ++currNum;
                    ++currSeqLength;
                }
                longestConsecutiveSequence = max(currSeqLength, longestConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
};

int getAnswer(const vector<int>& nums) {
    Solution solution;

	return solution.longestConsecutive(nums);
}

int main() {

	assert(4 == getAnswer({100,4,200,1,3,2}));
    assert(9 == getAnswer({0,3,7,2,5,8,4,6,0,1}));

    return 0;
}
