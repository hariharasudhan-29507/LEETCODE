class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (auto& b : buildings) {
            int left = b[0], right = b[1], height = b[2];
            events.push_back({left, -height});
            events.push_back({right, height});
        }
        
        sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        
        priority_queue<pair<int, int>> pq;
        pq.push({0, INT_MAX});
        
        vector<vector<int>> res;
        int prevMax = 0;
        
        for (auto& e : events) {
            int x = e.first;
            int h = e.second;
            
            if (h < 0) {
                h = -h;
                int right = -1;
                for (auto& b : buildings) {
                    if (b[0] == x && b[2] == h) {
                        right = b[1];
                        break;
                    }
                }
                pq.push({h, right});
            }
            
            while (!pq.empty() && pq.top().second <= x) {
                pq.pop();
            }
            
            int currMax = pq.top().first;
            if (currMax != prevMax) {
                res.push_back({x, currMax});
                prevMax = currMax;
            }
        }
        
        return res;
    }
};
