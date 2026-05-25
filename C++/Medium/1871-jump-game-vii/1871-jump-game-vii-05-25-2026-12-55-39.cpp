class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.length();

        // Early exit: last index must be '0'
        if (s[n - 1] == '1') return false;

        // Difference array
        vector<int> arr(n + 1, 0);

        int count = 0;

        for (int i = 0; i < n; i++) {

            // Apply prefix sum
            count += arr[i];

            // Current index is reachable
            if (i == 0 || (s[i] == '0' && count > 0)) {

                // Mark reachable range
                if (i + minJump < n)
                    arr[i + minJump] += 1;

                if (i + maxJump + 1 < n)
                    arr[i + maxJump + 1] -= 1;
            }
        }

        // Last index reachable or not
        return count > 0;
    }
};