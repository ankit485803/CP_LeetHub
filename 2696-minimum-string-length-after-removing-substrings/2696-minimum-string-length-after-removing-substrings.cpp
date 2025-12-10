class Solution {
public:
    int minLength(string s) {  //tc=O(n)=sc
        string st;   // acts as stack

        for (char c : s) {
            if (!st.empty()) {
                char top = st.back();
                // Check canceling pairs
                if ((top == 'A' && c == 'B') || 
                    (top == 'C' && c == 'D')) {
                    st.pop_back();   // remove the pair
                    continue;
                }
            }
            st.push_back(c);  // otherwise push normally
        }

        return st.size();
    }
};
