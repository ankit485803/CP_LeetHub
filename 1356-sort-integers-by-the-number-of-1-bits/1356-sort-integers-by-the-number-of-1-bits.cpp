class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {

            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);

            if(countA == countB) {
                return a < b;  //sort by value if bit same
            }

            return countA < countB;  //sort by bitCount
        });

        return arr;
    }
};