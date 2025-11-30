class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();

        sort(salary.begin(), salary.end());

        double sum = 0;

        // Only add salaries from index 1 to n-2
        // This automatically excludes:
        // salary[0]  -> minimum salary
        // salary[n-1] -> maximum salary
        for (int i = 1; i < n - 1; i++) {
            sum += salary[i]; 
        }

        return sum / (n - 2);
    }
};
