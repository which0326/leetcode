#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        int n = s.size();
        int left = 0;
        int mostFreqCharNum = 0;
        unordered_map<char, int>charMap;

        if (n <= 1) {
            return n;
        }

        for (int right = 0; right < n; ++right) {
            char currentChar = s[right];
            charMap[currentChar] += 1;
            mostFreqCharNum = max(mostFreqCharNum, charMap[currentChar]);
            int windowSize = (right - left + 1);

            if (windowSize- mostFreqCharNum > k) {
                char leftMostChar = s[left];
                charMap[leftMostChar] -= 1;
                ++left;
            } else {
                maxLength = max(maxLength, windowSize);
            }
        }
        return maxLength;
    }
};

int getAnswer(string s, int k) {
    Solution solution;

	return solution.characterReplacement(s, k);
}

int main() {

	assert(4 == getAnswer("ABAB", 2));
	assert(4 == getAnswer("AABABBA", 1));

    return 0;
}
