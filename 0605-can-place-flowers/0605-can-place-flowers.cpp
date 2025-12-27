class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        
        int count = 0;  
        
        for (int i = 0; i < flowerbed.size(); ++i) {
            // Check if we can plant a flower at position i
            if (flowerbed[i] == 0 && 
                (i == 0 || flowerbed[i - 1] == 0) && 
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                
                // Plant the flower
                flowerbed[i] = 1;
                count++;
                
                // If we've planted enough flowers, return true
                if (count >= n) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
