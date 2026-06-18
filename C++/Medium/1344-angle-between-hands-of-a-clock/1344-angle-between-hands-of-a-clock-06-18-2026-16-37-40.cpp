class Solution {
public:
    double angleClock(int hour, int minutes) {  //tc=O(1)=sc
        //using maths formula angle b/w hour and minutes hand
        double angle = abs(30.0 * hour - 5.5 * minutes);

        return min(angle, 360.0 - angle);
    }
};