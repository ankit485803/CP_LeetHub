class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //nestedLoop approach

        for(int i=0; i<arr.size(); i++) {
            int maxRight = -1;
            for(int j=i+1; j<arr.size(); j++) {
                maxRight = max(maxRight, arr[j]);
            }
            arr[i] = maxRight;
        }

        return arr;
    }
};