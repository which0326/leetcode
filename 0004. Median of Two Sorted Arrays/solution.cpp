#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Now n1 is smaller
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2;
        int low = 0;
        int high = n1;
         
        while (true) {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1) {
                r1 = nums1[mid1];
            }
            if (mid2 < n2) {
                r2 = nums2[mid2];
            }
            if (mid1 - 1 >= 0) {
                l1 = nums1[mid1 - 1];
            }
            if (mid2 - 1 >= 0) {
                l2 = nums2[mid2 - 1];
            }

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) {
                    return max(l1, l2);
                } else {
                    return ((double)(max(l1, l2) + min(r1, r2)) / 2.0);
                }
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        // Cannot reach here
        return 0;
    }
};

double getAnswer(const vector<int>& nums1, const vector<int>& nums2) {
    Solution solution;

	return solution.findMedianSortedArrays(nums1, nums2);
}

int main() {

	assert(2.00000 == getAnswer({1,3}, {2}));
    assert(2.50000 == getAnswer({1,2}, {3,4}));

    return 0;
}
