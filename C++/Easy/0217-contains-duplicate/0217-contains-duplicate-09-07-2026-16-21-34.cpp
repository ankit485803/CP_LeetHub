class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;  //sc = O(n) = sc using Hash Set

        for(int num : nums) {
            if(seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};