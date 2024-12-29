#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

class Solution {
public:
    long long calculateHoursToEatAll(vector<int>& piles, int eatPerHour) {
        long long hours = 0; // TODO check type

        for (const int &pile: piles) {
            hours += ceil(pile / (double) eatPerHour);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int answer = -1;
        long long maxHoursToEat = static_cast<long long>(h);

        while (low <= high) {
            int eatPerHour = low + ( high - low ) / 2;
            long long hoursToEatAll = calculateHoursToEatAll(piles, eatPerHour);
            
            if (hoursToEatAll <= maxHoursToEat) {
                answer = eatPerHour;
                high = eatPerHour - 1;
            } else {
                low = eatPerHour + 1;
            }
        }
        return answer;
    }
};

int getAnswer(vector<int>& piles, int h) {
    Solution solution;

	return solution.minEatingSpeed(piles, h);
}

int main() {
    vector<int>piles;

    piles = {3,6,7,11};
	assert(4 == getAnswer(piles, 8));
    piles = {30,11,23,4,20};
    assert(30 == getAnswer(piles, 5));
    assert(23 == getAnswer(piles, 6));
    return 0;
}
