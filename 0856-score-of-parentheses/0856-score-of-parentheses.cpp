class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        
        for (char c : s) {
            if (c == '(') {
                stk.push(0); 
            } else {
                int score = 0;
                if (stk.top() == 0) {
                    score = 1;  // Base case: "()" has score 1
                } else {
                    while (!stk.empty() && stk.top() != 0) {
                        score += stk.top();  // Add previous scores for nested parentheses
                        stk.pop();
                    }
                    score *= 2;  
                }
                stk.pop();  
                stk.push(score);  // Push the calculated score back to the stack
            }
        }
        
        int totalScore = 0;
        while (!stk.empty()) {
            totalScore += stk.top();
            stk.pop();
        }
        
        return totalScore;
    }
};
