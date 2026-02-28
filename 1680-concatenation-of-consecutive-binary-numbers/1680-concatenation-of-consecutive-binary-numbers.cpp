class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        string s = "";
        
        // Step 1 & 2: build binary string
        for (int i = 1; i <= n; i++) {
            s += bitset<32>(i).to_string();
            
            // remove leading zeros
            while (s.back() == '0' && s.size() > 1 && s[s.size()-2] == '0') break;
        }

        // Better way to build binary properly:
        s = "";
        for (int i = 1; i <= n; i++) {
            int num = i;
            string temp = "";
            while (num > 0) {
                temp = char('0' + num % 2) + temp;
                num /= 2;
            }
            s += temp;
        }

        // Step 3: convert binary string to decimal
        long long ans = 0;
        for (char c : s) {
            ans = (ans * 2 + (c - '0')) % MOD;
        }

        return ans;
    }
};