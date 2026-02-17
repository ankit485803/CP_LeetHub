class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {  //tc=O(1) sc=O(dependOn outputSize)
        vector<string> result;
        
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                
                // count total 1-bits in hour and minute
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    
                    // format time correctly
                    string time = to_string(h) + ":";
                    
                    if (m < 10)
                        time += "0";   // ensure 2-digit minute
                    
                    time += to_string(m);
                    
                    result.push_back(time);
                }
            }
        }
        
        return result;
    }
};
