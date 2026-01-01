class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Count distinct elements in the whole array
        unordered_set<int> st(nums.begin(), nums.end());
        int totalDistinct = st.size();
        
        unordered_map<int, int> freq;
        int ans = 0;
        int r = 0;
        
        // Step 2: Sliding window
        for (int l = 0; l < n; l++) {
            
            // Expand right pointer until window is complete
            while (r < n && freq.size() < totalDistinct) {
                freq[nums[r]]++;
                r++;
            }
            
            // Step 3: If window is complete, count subarrays
            if (freq.size() == totalDistinct) {
                ans += (n - r + 1);
            }
            
            // Step 4: Shrink window from left
            freq[nums[l]]--;
            if (freq[nums[l]] == 0) {
                freq.erase(nums[l]);
            }
        }
        
        return ans;
    }
};
