#include <vector>
#include <cstring>
using namespace std;

class Solution {
private:
    static const int MOD = 1000000007;
    
    // Standard matrix multiplication under mod
    vector<vector<long long>> mul(const vector<vector<long long>>& A, 
                                 const vector<vector<long long>>& B) {
        int m = A.size();
        vector<vector<long long>> C(m, vector<long long>(m, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                long long sum = 0;
                for (int k = 0; k < m; k++) {
                    sum = (sum + A[i][k] * B[k][j]) % MOD;
                }
                C[i][j] = sum;
            }
        }
        return C;
    }
    
    // Binary exponentiation for matrices
    vector<vector<long long>> matPow(vector<vector<long long>> base, 
                                    long long e, int m) {
        // Identity matrix
        vector<vector<long long>> res(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) {
            res[i][i] = 1;
        }
        
        while (e > 0) {
            if (e % 2 == 1) {
                res = mul(res, base);
            }
            base = mul(base, base);
            e >>= 1;
        }
        return res;
    }
    
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        
        // Transition matrix T where T[i][j] = 1 if value i can follow value j in a zigzag
        // i.e. i > j (going up) — the down direction is handled by symmetry (*2 at the end)
        // Time: O(m^3 * log n), Space: O(m^2)
        vector<vector<long long>> T(m, vector<long long>(m, 0));
        for (int j = 0; j < m; j++) {
            for (int i = m - j; i < m; i++) {
                T[i][j] = 1; // value i is strictly greater than value j
            }
        }
        
        // T^(n-1) encodes all valid zigzag transitions across n elements
        vector<vector<long long>> powT = matPow(T, n - 1, m);
        
        // Sum all entries: each (i,j) entry = number of zigzag arrays starting at j ending at i
        long long total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                total = (total + powT[i][j]) % MOD;
            }
        }
        
        // Multiply by 2 to account for both up-first and down-first zigzag sequences
        return static_cast<int>((total * 2) % MOD);
    }
};