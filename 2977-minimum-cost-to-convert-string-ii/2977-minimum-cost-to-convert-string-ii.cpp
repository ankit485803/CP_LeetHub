class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string> P;

    const ll BIG_VALUE = 1e10;

    // Graph: string -> [(nextString, cost)]
    unordered_map<string, vector<pair<string, ll>>> adj;

    // Memo for shortest path between two strings
    unordered_map<string, unordered_map<string, ll>> dijkstraMemo;

    // DP memo for index in source
    vector<ll> dpMemo;

    string sourceStr, targetStr;
    set<int> validLengths;

    // Dijkstra from start to end
    ll dijkstra(const string& start, const string& end) {
        if (dijkstraMemo[start].count(end)) {
            return dijkstraMemo[start][end];
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        unordered_map<string, ll> dist;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [currCost, node] = pq.top();
            pq.pop();

            if (node == end) break;
            if (currCost > dist[node]) continue;

            for (auto& edge : adj[node]) {
                string next = edge.first;
                ll w = edge.second;

                if (!dist.count(next) || currCost + w < dist[next]) {
                    dist[next] = currCost + w;
                    pq.push({currCost + w, next});
                }
            }
        }

        ll ans = dist.count(end) ? dist[end] : BIG_VALUE;
        return dijkstraMemo[start][end] = ans;
    }

    // DP over index
    ll solve(int i) {
        if (i == sourceStr.size()) return 0;
        if (dpMemo[i] != -1) return dpMemo[i];

        ll ans = BIG_VALUE;

        // Option 1: characters already match
        if (sourceStr[i] == targetStr[i]) {
            ans = solve(i + 1);
        }

        // Option 2: try all valid substring lengths
        for (int len : validLengths) {
            if (i + len > sourceStr.size()) continue;

            string sSub = sourceStr.substr(i, len);
            string tSub = targetStr.substr(i, len);

            ll cost = dijkstra(sSub, tSub);
            if (cost == BIG_VALUE) continue;

            ans = min(ans, cost + solve(i + len));
        }

        return dpMemo[i] = ans;
    }

    long long minimumCost(string source,
                          string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        sourceStr = source;
        targetStr = target;

        int M = original.size();

        // Build graph
        for (int i = 0; i < M; i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
            validLengths.insert(original[i].size());
        }

        dpMemo.assign(source.size(), -1);

        ll ans = solve(0);
        return ans >= BIG_VALUE ? -1 : ans;
    }
};
