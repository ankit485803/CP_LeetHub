class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {  //tc=O(n), s=O(1)
        int n = seats.size();
        int last = -1;
        int maxDist = 0;

        for(int i=0; i<n; i++) {
            if(seats[i] == 1) {
                if(last == -1) {
                    maxDist = i;
                } else {
                    maxDist = max(maxDist, (i - last)/2 );
                }
                last = i;
            }
        }
        if(seats[n-1] == 0) {
            maxDist = max(maxDist, n-1 - last);
        }

        return maxDist;
    }
};