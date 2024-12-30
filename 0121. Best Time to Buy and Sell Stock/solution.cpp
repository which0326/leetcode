#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int profit = 0;
        int base = prices[0];

        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < base) {
                base = prices[i];
            } else if (profit < prices[i] - base) {
                profit = prices[i] - base;
            }
        }
        return profit;
    }
};

int getAnswer(const vector<int>& prices) {
    Solution solution;

	return solution.maxProfit(prices);
}

int main() {

	assert(5 == getAnswer({7,1,5,3,6,4}));
    assert(0 == getAnswer({7,6,4,3,1}));

    return 0;
}
