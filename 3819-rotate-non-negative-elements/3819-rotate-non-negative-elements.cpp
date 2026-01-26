class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {  //tc=O(n)=sc
        vector<int> nonNeg;
        
        //step1: collect non-negative elements
        for (int x : nums) {
            if (x >= 0) {
                nonNeg.push_back(x);
            }
        }

        int m = nonNeg.size();
        if (m == 0) return nums;

        //step2: handle large k
        k %= m;
        if (k == 0) return nums;

        //step3: left rotate non-negative elements
        vector<int> rotated;
        for (int i = k; i < m; i++)
            rotated.push_back(nonNeg[i]);
        for (int i = 0; i < k; i++)
            rotated.push_back(nonNeg[i]);

        //step4: place back into original array
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                nums[i] = rotated[idx++];
            }
        }

        return nums;
    }
};
