
#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string/join.hpp>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return {0, 1};
    }
};

bool isCorrect(vector<int>answer, vector<int>output) {
    if (answer.size() != output.size()) {
        return false;
    }
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] != output[i]) {
            return false;
        }
    }
    return true;
}

void printSolution(vector<int> nums, int target, vector<int> answer, string ID) {
    Solution solution;
    vector<int> output = solution.twoSum(nums, target);

    if (isCorrect(answer, output)) {
        cout << ID << " is correct!" << endl;
    } else {
        cout << ID << " is wrong! Your output is " << boost::algorithm::join(output,",") << endl;
    }

}

int main() {
    printSolution({2,7,11,15}, 9, {0, 1}, "Example 1");
    printSolution({3,2,4}, 6, {1,2}, "Example 2");
    printSolution({3,3}, 6, {0,1}, "Example 3");

    return 0;
}
