class Solution {
public:
    int largestAltitude(vector<int>& gain) {  //tc=O(n), sc=O(1)
        int n = gain.size();
        vector<int> altitude(n+1);  //take arr size n+1

        altitude[0] = 0;  //firstElem always 0 because given in prob

        for(int i=0; i<n; i++) {
            altitude[i+1] = altitude[i] + gain[i]; 
        }

        return *max_element(altitude.begin(), altitude.end());
    }
};