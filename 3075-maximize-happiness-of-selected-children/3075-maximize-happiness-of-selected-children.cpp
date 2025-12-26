class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());

        long long maxHapp = 0;
        int dec = 0;
        for(int i=n-1; i>=n-k; i--) {
            int reduced = happiness[i] - dec;
            dec++;

            if(reduced > 0) {
                maxHapp += reduced;
            } else {
                break;
            }
        }

        return maxHapp;
    }
};