class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> v;  // height, name

        for (int i = 0; i < n; i++) {
            v.push_back({heights[i], names[i]});
        }

        // Sort by height descending
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        vector<string> ans;
        for (auto &p : v) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
