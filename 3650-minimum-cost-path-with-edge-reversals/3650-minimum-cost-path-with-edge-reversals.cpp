class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {  //tc=O((n + m) log n), sc=o(n+m)
        vector<vector<pair<int,int>>> adj(n);

        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});        // normal edge
            adj[v].push_back({u, 2 * w});    // reversed edge option
        }

        // Dijkstra
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == LLONG_MAX ? -1 : dist[n - 1];
    }
};
