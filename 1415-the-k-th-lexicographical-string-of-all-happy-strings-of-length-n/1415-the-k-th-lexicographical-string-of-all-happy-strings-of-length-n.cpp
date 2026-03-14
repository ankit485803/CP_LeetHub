class Solution {
private:
    void solve(int n, string &curr, vector<string> &res) {  //tc=O(3 × 2^(n-1))=sc
        if(curr.size() == n) {
            res.push_back(curr);
            return;
        }

        for(char c : {'a','b','c'}) {
            if(curr.empty() || curr.back() != c) {
                curr.push_back(c);
                solve(n, curr, res);
                curr.pop_back();
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        vector<string> res;
        string curr = "";

        solve(n, curr, res);

        if(k > res.size()) return "";
        return res[k-1];
    }
};