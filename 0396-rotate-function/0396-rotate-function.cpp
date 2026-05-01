class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {  //tc=O(n), sc=O(1)
        int n = nums.size();
        int sum = 0;
        int fsum = 0;  //initialize 

        for(int i=0; i < n; i++) {
            sum += nums[i];
            fsum += i*(nums[i]);  //calculate
        }

        int maxVal = fsum;
        for(int i = 1; i < n; i++) {
            //weGeneralizeFormula: fsum = fsum[i] + sum - n*nums[n-i]
            fsum = fsum + sum - n*nums[n-i];
            maxVal = max(fsum, maxVal);
        }

        return maxVal;
    }
};