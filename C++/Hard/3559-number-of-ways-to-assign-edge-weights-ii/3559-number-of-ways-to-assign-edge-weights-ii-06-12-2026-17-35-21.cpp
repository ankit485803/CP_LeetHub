class Solution {
    static const int mod = 1000000007;
    vector<int> depth;
    unordered_map<int, vector<int>> hmap;
    vector<vector<int>> lift; // Binary lifting table

public:
    // Time:  O(n) build adjacency + O(n) BFS + O(n log n) lift table + O(q log n) queries
    // Space: O(n log n) for lift table, O(n) for depth/visited

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        depth.assign(n + 1, 0);
        hmap.clear();
        lift.assign(n + 1, vector<int>(18, 0)); // 2^18 > 10^5

        // Build undirected adjacency list
        for (auto& e : edges) {
            int s = e[0], d = e[1];
            hmap[s].push_back(d);
            hmap[d].push_back(s);
        }

        // BFS from root (node 1) to compute depth and direct parents
        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.push(1);
        visited[1] = true;
        lift[1][0] = 1; // Root's parent points to itself

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (hmap.find(curr) == hmap.end()) continue;

            for (int next : hmap[curr]) {
                if (visited[next]) continue;

                visited[next] = true;
                depth[next] = depth[curr] + 1;
                lift[next][0] = curr; // Direct parent
                q.push(next);
            }
        }

        // Build binary lifting table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < 18; j++) {
                lift[i][j] = lift[lift[i][j - 1]][j - 1];
            }
        }

        // Answer queries
        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            int dist = depth[u] + depth[v] - 2 * depth[lca(u, v)];

            // Number of valid assignments = 2^(dist-1)
            ans[i] = (dist == 0) ? 0 : power(2, dist - 1);
        }

        return ans;
    }

private:
    // LCA via binary lifting
    int lca(int u, int v) {
        // Ensure u is deeper
        if (depth[u] < depth[v])
            return lca(v, u);

        // Bring u up to v's depth
        int diff = depth[u] - depth[v];

        for (int j = 0; j < 18; j++) {
            if (diff & 1)
                u = lift[u][j];
            diff >>= 1;
        }

        if (u == v) return u;

        // Move both up until ancestors diverge
        for (int j = 17; j >= 0; j--) {
            if (lift[u][j] != lift[v][j]) {
                u = lift[u][j];
                v = lift[v][j];
            }
        }

        return lift[u][0];
    }

    // Fast binary exponentiation under mod
    int power(int base, int exp) {
        long long res = 1;
        long long b = base % mod;

        while (exp > 0) {
            if (exp & 1)
                res = (res * b) % mod;

            b = (b * b) % mod;
            exp >>= 1;
        }

        return static_cast<int>(res);
    }
};