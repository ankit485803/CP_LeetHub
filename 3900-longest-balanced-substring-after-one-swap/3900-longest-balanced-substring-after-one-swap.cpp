class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<int, vector<int>> mpp;

        mpp[0].push_back(-1);
        
        int count0 = 0, count1 = 0;

        for(char c : s){
            if(c == '1') count1++;
            else if(c == '0') count0++;
        }
        int sum = 0, ans = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') sum++;
            if(s[i] == '0') sum--;
            if(mpp.count(sum)) ans = max(ans, i - mpp[sum][0]);
            if(mpp.count(sum - 2)){
                for(int j : mpp[sum - 2]){
                    int len = i - j;
                    int usedzeros = (len - 2) / 2;
                    if(count0 > usedzeros){
                        ans = max(ans, len);
                        break;
                    }
                }
            }

            if(mpp.count(sum + 2)){
                for(int j : mpp[sum + 2]){
                    int len = i - j;
                    int usedones = (len - 2) / 2;
                    if(count1 > usedones){
                        ans = max(ans, len);
                        break;
                    }
                } 
            }
            mpp[sum].push_back(i);
        }
        return ans;
    }
};