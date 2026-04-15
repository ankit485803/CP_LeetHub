class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {  
        int n = words.size();
        int result = INT_MAX;

        for(int i=0; i<n; i++) {  //tc=O(n * Length), sc=O(1)
            if(words[i] == target) {
                int straightDist = abs(i - startIndex);
                int circularDist = n - straightDist;  //createdFormula on penPaperDiag

                result = min({result, straightDist, circularDist});
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};