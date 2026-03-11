class Solution {
public:
    int bitwiseComplement(int n) {  //tc=O(logN) = sc
        if(n == 0) return 1;

        vector<int> binary;

        // Step 1: decimal -> binary
        while(n > 0){
            binary.push_back(n % 2);
            n /= 2;
        }

        // Step 2: flip bits
        for(int &bit : binary){
            bit = !bit;
        }

        // Step 3: binary -> decimal
        int ans = 0;
        int power = 1;

        for(int bit : binary){
            ans += bit * power;
            power *= 2;
        }

        return ans;
    }
};