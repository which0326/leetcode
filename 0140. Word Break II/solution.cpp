#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <boost/algorithm/string/join.hpp>

using namespace std;

// time complexity O(2^n)
class Solution {
public:
    vector<string>answers;

    void backtracking(int idx, string &sentense, string &inputString, unordered_map<string, bool> &doesExist) {
        if (idx >= inputString.size()) {
            answers.emplace_back(sentense);
            return;
        }

        for (int j = idx + 1; j <= idx + 10 && j <= inputString.size(); j++) {
            int charsToRemove = 0;
            string word = inputString.substr(idx, j-idx);

            if (doesExist.find(word) != doesExist.end()) {
                if (sentense.size() == 0) {
                    charsToRemove = word.size();
                    sentense += word;
                } else {
                    charsToRemove = word.size() + 1;
                    sentense += " " + word;
                }
                backtracking(j, sentense, inputString, doesExist);
                sentense.erase(sentense.size() - charsToRemove);
            }
        }
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> doesExist;
        string sentense;

        for (const auto &word: wordDict) {
            doesExist[word] = true;
        }
        backtracking(0, sentense, s, doesExist);
        return answers;
    }
};

void printSolution(string s, vector<string> wordDict) {
    Solution solution;
    cout << "[" << boost::algorithm::join(solution.wordBreak(s, wordDict), ",") << "]" << endl;
}

int main() {
    // expected: ["cats and dog","cat sand dog"]
    printSolution("catsanddog", {"cat","cats","and","sand","dog"});
    // expected: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
    printSolution("pineapplepenapple", {"apple","pen","applepen","pine","pineapple"});
    // expected: []
    printSolution("catsandog", {"cats","dog","sand","and","cat"});

    return 0;
}
