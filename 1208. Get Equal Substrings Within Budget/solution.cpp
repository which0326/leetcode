#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
// sliding windows: O(n)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int startIdx = 0;
        int cost = maxCost;

        for (int endIdx = 0; endIdx < s.size(); ++endIdx) {
            cost -= abs(s[endIdx] - t[endIdx]);
            if (cost < 0) {
                cost += abs(s[startIdx]-t[startIdx]);
                ++startIdx;
            }
        }
        return s.size() - startIdx;
    }
};
*/

// binary search: O(nlogn)
namespace {
    int binarySearch(int n, vector<int> &prefixSum, int maxCost) {
        int ans = 0;
        int l = 0;
        int h = n;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            bool isOK = false;
            
            for (int j = mid; j <= n; j++) {
                if (prefixSum[j] - prefixSum[j - mid] <= maxCost) {
                    isOK = true;
                    break;
                }
            }

            if (isOK) {
                l = mid + 1;
                ans = mid;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
}

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int>prefixSum(n+1, 0);

        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i-1] + abs(s[i-1] - t[i-1]);
        }
        return binarySearch(n, prefixSum, maxCost);
    }
};

void printSolution(string s, string t, int maxCost, int answer, string ID) {
    Solution solution;
    int ret = 0;

    if (answer == (ret = solution.equalSubstring(s, t, maxCost))) {
        cout << ID << " is correct !" << endl;
    } else {
        cout << ID << " is wrong ! Expected:  " << answer << ", return: " << ret << endl;
    }
}

int main() {
    printSolution("abcd", "bcdf", 3, 3, "Example 1");
    printSolution("abcd", "cdef", 3, 1, "Example 2");
    printSolution("abcd", "acde", 0, 1, "Example 3");
    printSolution("abcd", "bcde", 0, 0, "Example 4");
    return 0;
}
