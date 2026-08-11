class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 == 0 || len2 == 0 || n1 == 0 || n2 == 0) return 0;
        
        vector<int> repeatCnt(n1 + 1, 0);
        vector<int> nextIdx(n1 + 1, 0);
        unordered_map<int, int> posMap; 
        
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; k++) {
            for (int i = 0; i < len1; i++) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == len2) {
                        j = 0;
                        cnt++;
                    }
                }
            }
            repeatCnt[k] = cnt;
            nextIdx[k] = j;
            
            if (posMap.count(j)) {
                int start = posMap[j];
                int interval = k - start;
                int repeats = (n1 - start) / interval;
                int patternCnt = (repeatCnt[k] - repeatCnt[start]) * repeats;
                int remainCnt = repeatCnt[start + (n1 - start) % interval];
                return (patternCnt + remainCnt) / n2;
            } else {
                posMap[j] = k;
            }
        }
        
        return repeatCnt[n1] / n2;
    }
};
