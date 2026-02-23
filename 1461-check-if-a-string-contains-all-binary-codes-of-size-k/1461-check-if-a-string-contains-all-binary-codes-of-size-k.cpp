class Solution {
public:
    bool hasAllCodes(string s, int k) {  //tc=O(n * k), sc=O(n)
        unordered_set<string> st;

        for(int i=0; i+k <= s.size(); i++) {
            st.insert(s.substr(i, k));
        }

        //onlyNeed to check size of EachSubstr
        return st.size() == (1 << k);
    }
};