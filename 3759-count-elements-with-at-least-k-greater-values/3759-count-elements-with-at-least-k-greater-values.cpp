#include <algorithm>

class Solution {
public:
    int countElements(vector<int>& nums, int k) {  //tc=O(n logN), sc=O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int qualified = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            int j = binarySearch(nums, nums[i]);

            // The number of elements strictly greater than nums[i] is (n - j)
            count = n - j;

            if (count >= k) {
                qualified++;
            }
        }

        return qualified;
    }

private:
    // Binary search to find the first index where elements are strictly greater than target
    int binarySearch(const vector<int>& arr, int target) {
        int left = 0, right = arr.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left; 
    }
};
