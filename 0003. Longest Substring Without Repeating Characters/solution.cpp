#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        unordered_map<char, int> charMap;
        int left = 0;

        if (n <= 1) {
            return n;
        }

        for (int right = 0; right < n; ++right) {
            char currChar = s[right];

            if (0 == charMap.count(currChar) || charMap[currChar] < left) { /* Not found in map */
                maxLength = max(maxLength, right - left + 1);
            } else { /* Found in map*/
                left = charMap[currChar] + 1;
            }
            charMap[currChar] = right;
        }
        return maxLength;
    }
};

int getAnswer(string s) {
    Solution solution;

	return solution.lengthOfLongestSubstring(s);
}

int main() {
	assert(3 == getAnswer("abcabcbb"));
	assert(1 == getAnswer("bbbbb"));
	assert(3 == getAnswer("pwwkew"));
	assert(5 == getAnswer("tmmzuxt"));

    return 0;
}
