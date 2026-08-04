class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.empty()) return {};
        
        int n = s.size();
        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();
        if (totalLen > n) return {};
        
        unordered_map<string, int> targetFreq;
        for (string& w : words) {
            targetFreq[w]++;
        }
        
        vector<int> res;
        
        for (int start = 0; start < wordLen; start++) {
            unordered_map<string, int> windowFreq;
            int left = start;
            int count = 0;
            
            for (int right = start; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);
                
                if (targetFreq.count(word)) {
                    windowFreq[word]++;
                    if (windowFreq[word] <= targetFreq[word]) {
                        count++;
                    } else {
                        while (windowFreq[word] > targetFreq[word]) {
                            string leftWord = s.substr(left, wordLen);
                            windowFreq[leftWord]--;
                            if (windowFreq[leftWord] < targetFreq[leftWord]) {
                                count--;
                            }
                            left += wordLen;
                        }
                    }
                    
                    if (count == words.size()) {
                        res.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    windowFreq.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        
        return res;
    }
};
