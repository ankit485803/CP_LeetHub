//Approach-1 (Sliding Window)
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        unordered_map<int, int> mp;
        //I will go to each subarray of size k (window of size k) and mark which element came in that subarray
        //In the end , I will see which element came in exactly 1 subarray
        
        unordered_set<int> st;
        while(j < n) {
            if(j-i+1 == k) { //k sized subarray

                //Collect which elements are in this window
                for(int l = i; l <= j; l++) {
                    st.insert(nums[l]);
                }
                
                //Mark those elements
                for(int x : st) {
                    mp[x]++;
                }

                st.erase(nums[i]); //shifting window
                i++;
            }
            j++;
        }

        int result = -1;

        //Find the largest element which appeared in one subarray only
        for(auto [num, count] : mp) {
            if(count == 1 && num > result) {
                result = num;
            }
        }

        return result;
        
    }
};