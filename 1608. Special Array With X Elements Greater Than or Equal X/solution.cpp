#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {
    constexpr int BIGGEST_NUM = 100;
}

class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int>counting(BIGGEST_NUM+1);
        for (const auto num: nums) {
            counting[num > BIGGEST_NUM? BIGGEST_NUM : num]++;
        }
        for (int i = BIGGEST_NUM; i > 0; i--) {
            if (i != BIGGEST_NUM) {
                counting[i] = counting[i+1] + counting[i];
            }
            if (counting[i] == i) {
                return i;
            }
        }
        return -1;
    }
};

void printSolution(vector<int> nums) {
    Solution solution;
    
    cout << solution.specialArray(nums) << endl;
}

int main() {
    // Expected Output: 2
    printSolution({3,5});
    // Expected Output: -1
    printSolution({0,0});
    // Expected Output: 3
    printSolution({0,4,3,0,4});
    return 0;
}
