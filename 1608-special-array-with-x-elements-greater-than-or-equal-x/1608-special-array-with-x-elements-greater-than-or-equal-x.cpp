#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        
        // Sort the array in non-decreasing order
        sort(nums.begin(), nums.end());

        // Try each possible value of x from 1 to n
        for (int x = 1; x <= n; ++x) {
            // Count how many elements are >= x
            int count = 0;
            for (int num : nums) {
                if (num >= x) {
                    count++;
                }
            }
            
            // If count is exactly x, return x
            if (count == x) {
                return x;
            }
        }
        
        // If no such x is found, return -1
        return -1;
    }
};
