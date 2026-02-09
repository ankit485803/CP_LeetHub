class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;  // to count the number of "drops" (nums[i] > nums[i+1])
        
        // Traverse the entire array
        for (int i = 0; i < n; i++) {
            // Compare current element with the next one (circular using % n)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;  // found a "drop" in order
            }
        }
        
        // If there is more than 1 drop, it's not a sorted-then-rotated array
        return count <= 1;
    }
};


//tc=O(n), sc=O(1)
// This is a   VALIDATION  problem, not a SEARCH problem. so not pefer BinarySearch here