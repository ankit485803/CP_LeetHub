class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        int negIdx = -1;

        // Step 1: find negative index
        for (int i = 0; i < n; i++) {
            if (balance[i] < 0) {
                negIdx = i;
                break;
            }
        }

        // No negative balance
        if (negIdx == -1) return 0;

        long long need = -1LL * balance[negIdx];
        long long totalPos = 0;

        // Step 2: sum positive balances
        for (int i = 0; i < n; i++) {
            if (balance[i] > 0)
                totalPos += balance[i];
        }

        // Step 3: impossible case
        if (totalPos < need) return -1;

        // Step 4: collect donors with distances
        vector<pair<int, long long>> donors; // {distance, units}

        for (int i = 0; i < n; i++) {
            if (i == negIdx || balance[i] <= 0) continue;

            int clockwise = (i - negIdx + n) % n;
            int anticlockwise = (negIdx - i + n) % n;
            int dist = min(clockwise, anticlockwise);

            donors.push_back({dist, balance[i]});
        }

        // Step 5: greedy by nearest distance
        sort(donors.begin(), donors.end());

        long long moves = 0;

        for (auto &[dist, units] : donors) {
            if (need == 0) break;

            long long take = min(need, units);
            moves += take * dist;
            need -= take;
        }

        return moves;
    }
};
