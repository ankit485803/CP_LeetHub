class Solution {
public:
    int minAllOneMultiple(int k) {   //tc=O(k), sc=O(1)
        int num = 0;
        for(int leng=1; leng<=k; leng++) {
            num = (num * 10 + 1) % k;

            if(num == 0) {
                return leng;
            }
        }

        return -1;
    }
};