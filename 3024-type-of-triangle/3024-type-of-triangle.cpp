class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Check if the sides form a valid triangle using the triangle inequality theorem
        if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0]) {
            return "none"; // Not a valid triangle
        }
        
        // Check for equilateral triangle
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        
        // Check for isosceles triangle (exactly two sides equal)
        if (nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0]) {
            return "isosceles";
        }
        
        // If no two sides are equal, it's scalene
        return "scalene";
    }
};
