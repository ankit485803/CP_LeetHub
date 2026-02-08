class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {  //tc=O(n)=sc
        vector<long long> res;

        for (int x : nums) {
            res.push_back(x);

            // keep merging while last two are equal
            while (res.size() >= 2) {
                int n = res.size();
                if (res[n - 1] == res[n - 2]) {
                    long long merged = res[n - 1] + res[n - 2];
                    res.pop_back();
                    res.pop_back();
                    res.push_back(merged);
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
