class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int lorqavined = n; // required by problem
        
        unordered_map<int, int> count;
        
        int limit = cbrt(n); // cube root
        
        // Step 1: generate all a^3 + b^3
        for (int a = 1; a <= limit; a++) {
            long long a3 = 1LL * a * a * a;
            
            for (int b = a; b <= limit; b++) {
                long long sum = a3 + 1LL * b * b * b;
                
                if (sum > n) break;
                
                count[sum]++;
            }
        }
        
        // Step 2: collect good integers
        vector<int> result;
        for (auto &it : count) {
            if (it.second >= 2) {
                result.push_back(it.first);
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};