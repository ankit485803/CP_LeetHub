class Solution {
public:
    int countCollisions(string directions) {  //tc=O(n), sc=O(1)
        int n = directions.length();
        int collisions = 0;

        // Step1: Find the leftmost index where we no longer have 'L'
        int i = 0;  // left boundary
        while (i < n && directions[i] == 'L') {
            i++;
        }

        // Step2: Find the rightmost index where we no longer have 'R'
        int j = n - 1;  // right boundary
        while (j >= 0 && directions[j] == 'R') {
            j--;
        }

        // Step3: Count the collisions
        while (i <= j) {
            char c = directions[i];

            if (c != 'S') {
                collisions++;
            }

            i++;
        }

        return collisions;
    }
};
