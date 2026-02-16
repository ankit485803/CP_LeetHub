class Solution {
public:
    int reverseBits(int n) {  //tc=O(32 bit only)=sc
        uint32_t result = 0;

        for(int i=0; i<32; i++) {
            result <<= 1;  //giveSpace for nextBit
            result |= (n & 1);   //addLast bit of n
            n >>= 1;  //shift n right
        }

        return result;
    }
};