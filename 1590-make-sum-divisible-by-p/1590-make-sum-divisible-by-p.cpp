class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {  //tc=O(n)=sc
        int n = nums.size();
        long long sum = 0;

        // Calculate the sum of all elements and take % p
        for (int num : nums) {
            sum = (sum + num) % p;
        }

        int target = sum % p;
        if (target == 0) {
            return 0;
        }

        unordered_map<int, int> map;
        map[0] = -1; 
        
        long long curr = 0;
        int result = n;
        for (int j = 0; j < n; ++j) {
            curr = (curr + nums[j]) % p;

            // Calculate the remainder needed to achieve the target
            int remain = (curr - target + p) % p;
            
            // If the required remainder exists in the map, update the result
            if (map.count(remain)) {
                result = min(result, j - map[remain]);
            }
            
            // Store the current remainder with its index
            map[curr] = j;
        }

        return result == n ? -1 : result;
    }
};
