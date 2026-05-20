class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {  //tc=O(n^3), sc=O(1) bruteForce
        int n = A.size();
        vector<int> result(n);

        for(int i=0; i<n; i++) {
            int count = 0;
            for(int x = 0; x <= i; x++) {
                //find if we have A[x] in B not till index i
                for(int y = 0; y <= i; y++) {  //B
                    if(B[y] == A[x]) {
                        count++;
                        break;
                    }
                }
            }

            result[i] = count;
        }

        return result;
    }
};