class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step1: Create a vector of pairs (value, index)
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < n; ++i) {
            indexed_nums.push_back({nums[i], i});
        }
        
        // Step2: Sort the pairs by value in descending order
        sort(indexed_nums.begin(), indexed_nums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        // Step3: Select first k elements and store their indices
        vector<int> result;
        vector<int> indices;
        for (int i = 0; i < k; ++i) {
            indices.push_back(indexed_nums[i].second);
        }
        
        // Step4: Sort indices in ascending order to maintain originalOrder
        sort(indices.begin(), indices.end());
        
        // Step5: buildResult 
        for (int i = 0; i < k; ++i) {
            result.push_back(nums[indices[i]]);
        }
        
        return result;
    }
};
