class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        // Step 1: Count total Y's
        int penalty = 0;
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        // Step 2: Try closing at each hour j (1 to n)
        for (int j = 1; j <= n; j++) {
            if (customers[j - 1] == 'Y') {
                penalty--;   // no longer closed during a customer hour
            } else {
                penalty++;   // stayed open with no customers
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }

        return bestHour;
    }
};
