class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {  //tc=O(n logN), sc=O(n) due ans vector
        sort(arr.begin(), arr.end()); 

        int minDiff = INT_MAX;
        vector<vector<int>> ans;

        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                // Found a new minimum difference
                minDiff = diff;
                ans.clear();  
                ans.push_back({arr[i - 1], arr[i]});
            } else if (diff == minDiff) {
                // Same as the current minimum, so add this pair
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};
