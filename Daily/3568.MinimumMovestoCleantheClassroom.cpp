class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sr = -1, sc = -1;
        int Lcnt = 0;
        vector<vector<int>> lid(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    lid[i][j] = Lcnt++;
                }
            }
        }
        int fullMask = (1 << Lcnt) - 1;
        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(1 << Lcnt, -1)));
        queue<tuple<int, int, int, int, int>> q;
        best[sr][sc][0] = energy;
        q.emplace(sr, sc, 0, energy, 0);
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto [r, c, mask, e, d] = q.front();
            q.pop();
            if (mask == fullMask) return d;
            if (e == 0) continue;
            for (auto &dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (classroom[nr][nc] == 'X') continue;
                int nmask = mask;
                if (classroom[nr][nc] == 'L') {
                    nmask |= (1 << lid[nr][nc]);
                }
                int ne = e - 1;
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }
                if (ne > best[nr][nc][nmask]) {
                    best[nr][nc][nmask] = ne;
                    q.emplace(nr, nc, nmask, ne, d + 1);
                }
            }
        }
        return -1;
    }
};
