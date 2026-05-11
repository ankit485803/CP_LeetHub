class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {  //tc=O(totalDigits), sc=O(1)
        vector<int> ans;

        for(int num : nums) {
            string s = to_string(num);  //convert int to str

            //now mainLogic
            for(char ch : s) {
                ans.push_back(ch - '0');  //push into ans
            }
        }

        return ans;
    }
};