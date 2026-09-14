class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {  //tc=O(1)=sc
        //by geometry observation
        //horizontalRange rec1[0] < rec2[2] && rec2[0] < rec1[2] 
        //vertical 1, 3 just similary vice-versa

        return rec1[0] < rec2[2] && rec2[0] < rec1[2] && 
                                rec1[1] < rec2[3] && rec2[1] < rec1[3];
    }
};