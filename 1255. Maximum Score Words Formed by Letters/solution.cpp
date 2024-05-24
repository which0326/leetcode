#include <vector>
#include <iostream>
#include <string>

using namespace std;

constexpr int LETTERS = 26;

class Solution {
private:
    int availableLetters[LETTERS] = {};
    int usedLetters[LETTERS] = {};
    int answer = 0;

public:
    void backtracking(int idx, vector<string>& words, vector<int>& score) {
        // Check if word can be formed
        for (int i = 0; i < LETTERS; i++) {
            if (availableLetters[i] < usedLetters[i]) {
                return;
            }
        }

        if (idx == words.size()) {
            int total = 0;
            for (int i = 0; i < LETTERS; i++) {
                total += usedLetters[i] * score[i];
            }
            answer = max(answer, total);
            return;
        }

        backtracking(idx + 1, words, score);
        for (const auto &letter: words[idx]) {
            ++usedLetters[letter - 'a'];
        }
        backtracking(idx + 1, words, score);
        for (const auto &letter: words[idx]) {
            --usedLetters[letter - 'a'];
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        for (const char& letter : letters) {
            ++availableLetters[letter - 'a'];
        }
        backtracking(0, words, score);
        return answer;
    }
};

int main() {
    Solution solution1;
    vector<string> words1 = {"dog","cat","dad","good"};
    vector<char> letters1 = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score1 = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    // expected: 23
    cout << solution1.maxScoreWords(words1, letters1, score1) << endl;

    Solution solution2;
    vector<string> words2 = {"xxxz","ax","bx","cx"};
    vector<char> letters2 = {'z','a','b','c','x','x','x'};
    vector<int> score2 = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
    // expected: 27
    cout << solution2.maxScoreWords(words2, letters2, score2) << endl;

    Solution solution3;
    vector<string> words3 = {"leetcode"};
    vector<char> letters3 = {'l','e','t','c','o','d'};
    vector<int> score3 = {0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};
    // expected: 0
    cout << solution3.maxScoreWords(words3, letters3, score3) << endl;
    return 0;
}