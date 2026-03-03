class Solution {
public:
    char findKthBit(int n, int k) {  //tc=O(n)=sc usingRecussion
        if (n == 1) 
            return '0';   // must return character
        
        int length = (1 << n) - 1;
        int mid = (length + 1) / 2;   // middle position
        
        if (k == mid) 
            return '1';
        
        if (k < mid) 
            return findKthBit(n - 1, k);
        
        // right half
        char ch = findKthBit(n - 1, length - k + 1);
        return (ch == '0') ? '1' : '0';
    }
};