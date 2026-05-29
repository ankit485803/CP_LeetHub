class Solution {
public:
    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {   //tc=O(no of digits), sc=O(1)
        int mini = INT_MAX;

        for (int num : nums) {
            mini = min(mini, digitSum(num));
        }

        return mini;
    }
};