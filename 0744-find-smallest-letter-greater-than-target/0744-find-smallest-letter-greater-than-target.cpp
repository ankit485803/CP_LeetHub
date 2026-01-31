
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






// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         //optimized using BS because sortedArr given
//         int left = 0, right = letters.size()-1;
//         int result = letters[0];   //defaultSet to firstChar

//         while(left <= right) {
//             int mid = left + (right-left)/2;

//             if(letters[mid] > target) {  //searchInRightHalf
//                 result = letters[mid];
//                 right = mid - 1;

//             } else {
//                 left = mid + 1;  //leftHalfSearching
//             }
//         }

//         return result;
//     }
// };