class Solution {
public:
    int minJumps(vector<int>& arr) {  //tc=O(n)=sc using BFS

        int n = arr.size();

        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);

        // value -> list of indices
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> que;
        que.push(0);

        visited[0] = true;

        int steps = 0;

        while (!que.empty()) {

            int sz = que.size();

            while (sz--) {

                int curr = que.front();
                que.pop();

                // reached end
                if (curr == n - 1)
                    return steps;

                int left = curr - 1;
                int right = curr + 1;

                // i - 1
                if (left >= 0 && !visited[left]) {
                    visited[left] = true;
                    que.push(left);
                }

                // i + 1
                if (right < n && !visited[right]) {
                    visited[right] = true;
                    que.push(right);
                }

                // same value jumps
                for (int idx : mp[arr[curr]]) {
                    if (!visited[idx]) {
                        visited[idx] = true;
                        que.push(idx);
                    }
                }

                // IMPORTANT optimization
                mp.erase(arr[curr]);
            }

            steps++;
        }

        return -1;
    }
};