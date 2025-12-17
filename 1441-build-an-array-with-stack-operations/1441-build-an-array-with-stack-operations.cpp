class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result; 
        int targetIdx = 0;  

        for (int i = 1; i <= n; ++i) {
            result.push_back("Push");
            

            if (i == target[targetIdx]) {
                targetIdx++;  
            } else {
                result.push_back("Pop");
            }
            
            // If we have processed all elements in the target, stop
            if (targetIdx == target.size()) break;
        }
        return result;
    }
};
