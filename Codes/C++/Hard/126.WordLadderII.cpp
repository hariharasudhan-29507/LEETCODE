class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        dict.insert(beginWord);
        
        unordered_map<string, int> dist;
        queue<string> q;
        q.push(endWord);
        dist[endWord] = 0;
        
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            for (int i = 0; i < word.syize(); i++) {
                string pattern = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == word[i]) continue;
                    pattern[i] = c;
                    if (dict.count(pattern) && !dist.count(pattern)) {
                        dist[pattern] = dist[word] + 1;
                        q.push(pattern);
                    }
                }
            }
        }
        
        if (!dist.count(beginWord)) return {};
        
        vector<vector<string>> res;
        vector<string> path{beginWord};
        dfs(beginWord, endWord, dict, dist, path, res);
        return res;
    }
    
    void dfs(string& cur, string& endWord, unordered_set<string>& dict,
             unordered_map<string, int>& dist, vector<string>& path,
             vector<vector<string>>& res) {
        if (cur == endWord) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < cur.size(); i++) {
            string next = cur;
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == cur[i]) continue;
                next[i] = c;
                if (dict.count(next) && dist.count(next) && dist[next] == dist[cur] - 1) {
                    path.push_back(next);
                    dfs(next, endWord, dict, dist, path, res);
                    path.pop_back();
                }
            }
        }
    }
};
