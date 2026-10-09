class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {  //tcO(n^2) nestedLoop, sc=O(1)
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int st = i + 1;
            int end = n - 1;

            while (st < end) {
                int sum = nums[i] + nums[st] + nums[end];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[st], nums[end]});

                    st++;
                    end--;

                    // Skip duplicate second elements
                    while (st < end && nums[st] == nums[st - 1]) {
                        st++;
                    }

                    // Skip duplicate third elements
                    while (st < end && nums[end] == nums[end + 1]) {
                        end--;
                    }
                }
                else if (sum < 0) {
                    st++;
                }
                else {
                    end--;
                }
            }
        }

        return ans;
    }
};