class Solution {
public:
    int minimumK(vector<int>& nums) {
        int n = nums.size();

        int left = 1;
        int right = 100000; // According to given  constraints
        int ans = right;

        while (left <= right) {
            int k = left + (right - left) / 2;
            long long ops = 0;

            for (int i = 0; i < n; i++) {
                ops += (nums[i] + k - 1) / k; // ceil(nums[i] / k)
                if (ops > 1LL * k * k) break; // early stop
            }

            if (ops <= 1LL * k * k) {
                ans = k;
                right = k - 1;
            } else {
                left = k + 1;
            }
        }

        return ans;
    }
};
