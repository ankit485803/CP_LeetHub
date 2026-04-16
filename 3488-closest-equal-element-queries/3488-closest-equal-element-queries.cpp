class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        for(int qi : queries) {  //tc=O(Q)
            int element = nums[qi];
            vector<int>& vec = mp[element];

            int sz = vec.size();

            //no more occurence of this elem
            if(sz == 1) {
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(begin(vec), end(vec), qi) - begin(vec);
            int res = INT_MAX;

            //right neighbour: pos + 1
            int right = vec[(pos + 1) % sz];
            int d = abs(qi - right);  //straight forward dist
            int circularDist = n-d;
            res = min({res, d, circularDist});


            //LEFT neighbour: pos - 1
            int left = vec[(pos - 1 + sz) % sz];
            d = abs(qi - left);  //straight forward dist
            circularDist = n-d;
            res = min({res, d, circularDist});

            result.push_back(res);
        }

        return result;
    }
};