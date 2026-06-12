class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        long long globalMax = *max_element(nums.begin(), nums.end());
        long long globalMin = *min_element(nums.begin(), nums.end());

        //find best ans
        long long bestVal = globalMax - globalMin;

        //print the ans by k times
        return k * bestVal;
    }
};

//tc=O(n) take by scan array once for max and min
//sc = O(1)  just store min, max, and resul