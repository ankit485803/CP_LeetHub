class Solution {
public:
    typedef long long ll;
    vector<ll> distance(vector<int>& nums) {  //O(N) = tc = sc
        int n = nums.size();
        vector<ll> arr(n, 0);

        unordered_map<int, ll> idxSum;  //nums[i] -> sum of 1's
        unordered_map<int, ll> idxCount;  //nums[i] -> freq

        //left to right LHS  
        for(int i = 0; i < n; i++) {
            ll freq = idxCount[nums[i]];
            ll sum = idxSum[nums[i]];

            //yahi formula banaye the
            arr[i] += freq * i - sum;

            idxCount[nums[i]] += 1;
            idxSum[nums[i]] += i;
        }

        //pahle clearMap
        idxSum.clear();
        idxCount.clear();

        //righToLeft  RHS
        for(int i = n-1; i >= 0; i--) {
            ll freq = idxCount[nums[i]];
            ll sum = idxSum[nums[i]];

            //formula
            arr[i] += sum - freq * i;

            idxCount[nums[i]] += 1;
            idxSum[nums[i]] += i;
        }

        return arr;
    }
};