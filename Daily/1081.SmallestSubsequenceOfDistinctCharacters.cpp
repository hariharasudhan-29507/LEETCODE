class Solution {
public:
    std::string smallestSubsequence(std::string s) {
        int n = s.size();
        if (n == 0) return "";

    
        std::vector<int> last_occurrence(26, -1);
        for (int i = 0; i < n; i++) {
            last_occurrence[s[i] - 'a'] = i;
        }


        std::vector<char> stack;
        std::unordered_set<char> in_stack;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (in_stack.count(ch)) {
                continue;
            }

            while (!stack.empty() && stack.back() > ch &&
                   last_occurrence[stack.back() - 'a'] > i) {
                in_stack.erase(stack.back());
                stack.pop_back();
            }

            stack.push_back(ch);
            in_stack.insert(ch);
        }

        return std::string(stack.begin(), stack.end());
    }
};
