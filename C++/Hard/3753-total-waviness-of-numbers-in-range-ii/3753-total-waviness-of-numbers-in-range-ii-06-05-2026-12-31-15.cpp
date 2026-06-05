#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, pair<long long, long long>> mp;

public:
    // Time: O(D * 11 * 11 * 2 * 2) = O(D), Space: O(D)
    // where D = number of digits in num2

    long long totalWaviness(long long num1, long long num2) {
        // Count waviness in [num1, num2] using prefix subtraction
        return getWaves(num2) - getWaves(num1 - 1);
    }

    // Returns total waviness for all numbers in [0, num]
    long long getWaves(long long num) {
        if (num < 0) return 0;

        mp.clear();
        string s = to_string(num);

        // Numbers with fewer than 3 digits can't have a wave peak/valley
        if ((int)s.size() < 3) return 0;

        auto ans = helper(s, 0, true, -1, -1, true);
        return ans.second; // ans.first = count, ans.second = total waviness
    }

    // Returns {count of valid numbers, total waviness}
    pair<long long, long long> helper(
        string &s,
        int idx,
        bool isBound,
        int twobefore,
        int onebefore,
        bool leadingZero
    ) {
        // Base case: full number formed
        if (idx == (int)s.size()) {
            // Leading zero means the number was effectively empty/zero — not valid
            return leadingZero ? make_pair(0LL, 0LL)
                               : make_pair(1LL, 0LL);
        }

        string key = to_string(idx) + "#" +
                     to_string(isBound) + "#" +
                     to_string(twobefore) + "#" +
                     to_string(onebefore) + "#" +
                     to_string(leadingZero);

        if (mp.count(key))
            return mp[key];

        int upper = isBound ? (s[idx] - '0') : 9;

        long long totalCount = 0;
        long long totalWaves = 0;

        for (int i = 0; i <= upper; i++) {
            long long wave = 0;
            int nextTwoBefore, nextOneBefore;

            if (leadingZero) {
                // Still in leading zero phase
                nextTwoBefore = -1;
                nextOneBefore = (i == 0) ? -1 : i;
            } else {
                nextTwoBefore = onebefore;
                nextOneBefore = i;

                // Check if onebefore forms a wave peak or valley
                if (twobefore >= 0 && onebefore >= 0) {
                    if ((onebefore > twobefore && onebefore > i) || // peak
                        (onebefore < twobefore && onebefore < i)) { // valley
                        wave = 1;
                    }
                }
            }

            bool nextBound = isBound && (i == upper);
            bool nextLeadingZero = leadingZero && (i == 0);

            auto sub = helper(
                s,
                idx + 1,
                nextBound,
                nextTwoBefore,
                nextOneBefore,
                nextLeadingZero
            );

            totalCount += sub.first;

            // Each of the sub.first numbers contributes current wave
            // plus their own internal waves
            totalWaves += sub.second + sub.first * wave;
        }

        return mp[key] = {totalCount, totalWaves};
    }
};