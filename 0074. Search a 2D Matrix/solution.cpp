#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {

        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int leftIdx = 0;
        int rightIdx = m * n - 1;

        while (leftIdx <= rightIdx) {
            int midIdx = leftIdx + (rightIdx - leftIdx) / 2;
            int rowIdx = midIdx / n;
            int colIdx = midIdx % n;
            int currentMid = matrix[rowIdx][colIdx];

            if (target == currentMid) {
                return true;
            } else if (target < currentMid) {
                rightIdx = midIdx - 1;
            } else {
                leftIdx = midIdx + 1;
            }
        }
        return false;
    }
};

bool getAnswer(const vector<vector<int>>& matrix, int target) {
    Solution solution;

    return solution.searchMatrix(matrix, target);
}

int main() {

    assert(getAnswer({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 3) == true);
    assert(getAnswer({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 13) == false);
    return 0;
}
