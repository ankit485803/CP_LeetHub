class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) { 
        vector<vector<int>> ans; 
        if (n < 4) return ans; //baseCase: smallest primePairSum is 2+2=4 

        // Step1: Sieve of Eratosthenes techniques
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {  //tc=O(log logN), sc=O(n)  
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step2: Find valid primePairs - Enumeration
        for (int x = 2; x <= n / 2; x++) {
            if (isPrime[x] && isPrime[n - x]) {
                ans.push_back({x, n - x});
            }
        }

        return ans;
    }
};
