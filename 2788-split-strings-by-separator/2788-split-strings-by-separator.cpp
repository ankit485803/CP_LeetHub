class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;

        for (int i = 0; i < words.size(); i++) {  //tc=sc=O(totalChar)
            string curr = "";

            for (char c : words[i]) {
                if (c == separator) {
                    if (!curr.empty()) {
                        result.push_back(curr);
                        curr.clear();
                    }
                } else {
                    curr.push_back(c);
                }
            }

            // add last part if non-empty
            if (!curr.empty()) {
                result.push_back(curr);
            }
        }

        return result;
    }
};
