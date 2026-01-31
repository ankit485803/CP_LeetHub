class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //bruteForeApporach - O(n) tc,  sc=O(1)
        int n = letters.size();

        for(int i=0; i<n; i++) {
            if(letters[i] > target) {  //checkCondition just greater using ASCII value
                return letters[i];
            }
        }
        //notFound in letter then return firstChar 
        return letters[0];
    }
};