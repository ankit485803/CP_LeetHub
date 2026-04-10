class Solution {
public:
    int minimumDistance(vector<int>& nums) {  //tc=O(n)=sc
        unordered_map<int, vector<int>> mp;

        // store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // check each value
        for (auto &p : mp) {
            vector<int> &v = p.second;

            if (v.size() < 3) continue;

            // check consecutive triples
            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i+2] - v[i]);
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};