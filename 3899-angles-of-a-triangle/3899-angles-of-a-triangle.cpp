class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {  //tc=O(1)=sc
        vector<int> norqavelid = sides; // required
        
        double a = sides[0], b = sides[1], c = sides[2];
        
        // Step 1: Check triangle validity
        if (a + b <= c || b + c <= a || a + c <= b) {
            return {};
        }
        
        // Step 2: Law of Cosines
        double A = acos((b*b + c*c - a*a) / (2*b*c));
        double B = acos((a*a + c*c - b*b) / (2*a*c));
        double C = acos((a*a + b*b - c*c) / (2*a*b));
        
        // Step 3: Convert to degrees
        double pi = acos(-1);
        A = A * 180.0 / pi;
        B = B * 180.0 / pi;
        C = C * 180.0 / pi;
        
        vector<double> ans = {A, B, C};
        
        // Step 4: Sort
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};