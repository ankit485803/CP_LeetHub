
class Solution {
public:
    int maxArea(vector<int>& height) {  //today 9th Oct 2026 (Friday sem7iitp)
        int st = 0;
        int end = height.size() - 1;
        int maxWater = 0;

        while (st < end) {
            int width = end - st;
            int h = min(height[st], height[end]);

            int area = width * h;
            maxWater = max(maxWater, area);

            // Move the pointer with smaller height
            if (height[st] < height[end]) {
                st++;
            } else {
                end--;
            }
        }

        return maxWater;
    }
};