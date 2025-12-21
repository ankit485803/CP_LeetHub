class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        
        // Step1: Convert hr to min
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));
            times.push_back(hours * 60 + minutes);
        }
        
        // Step2: sort
        sort(times.begin(), times.end());
        
        // Step3: calculate mintDiff
        int minDiff = INT_MAX;
        for (int i = 1; i < times.size(); ++i) {
            minDiff = min(minDiff, times[i] - times[i - 1]);
        }
        
        // Check the diff b/w first and the last time point, considering 1440-minute wraparound
        minDiff = min(minDiff, 1440 + times[0] - times.back());
        
        return minDiff;
    }
};
