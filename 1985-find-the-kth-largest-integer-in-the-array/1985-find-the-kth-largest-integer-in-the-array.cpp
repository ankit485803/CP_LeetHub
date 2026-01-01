class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
            if (a.length() != b.length())
                return a.length() > b.length(); // longer = larger
            return a > b; // lexicographically larger
        });
        
        return nums[k - 1];
    }
};
