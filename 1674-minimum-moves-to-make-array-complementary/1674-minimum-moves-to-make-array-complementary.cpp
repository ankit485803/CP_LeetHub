class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {  //tc=O(n + limit), sc=O(limit)  using prefixSum approach

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int x = nums[i];
            int y = nums[n - 1 - i];

            int a = min(x, y);
            int b = max(x, y);

            // Initially every sum needs 2 moves
            diff[2] += 2;

            // [a+1 , b+limit] => at most 1 move
            diff[a + 1] -= 1;
            diff[b + limit + 1] += 1;

            // exactly a+b => 0 move
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};