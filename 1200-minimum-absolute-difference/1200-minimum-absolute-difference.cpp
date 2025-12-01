#include <algorithm>


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        vector<vector<int>> result;

        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                // Found a new minimum difference
                minDiff = diff;
                result.clear();  
                result.push_back({arr[i - 1], arr[i]});
            } else if (diff == minDiff) {
                // Same as the current minimum, so add this pair
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        return result;
    }
};
