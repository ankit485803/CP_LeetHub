class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // Collision only when last is moving right and current is moving left
            while (!st.empty() && st.back() > 0 && a < 0) {
                if (abs(st.back()) < abs(a)) {
                    // stack top explodes
                    st.pop_back();
                    continue;
                } 
                else if (abs(st.back()) == abs(a)) {
                    // both explode
                    st.pop_back();
                }
                
                // current asteroid explodes
                destroyed = true;
                break;
            }

            if (!destroyed) {
                st.push_back(a);
            }
        }

        return st;
    }
};
