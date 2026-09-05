class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n), rg(n);
        for (auto& e : invocations) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            rg[b].push_back(a);
        }

        vector<bool> suspicious(n, false);
        function<void(int)> dfs_mark = [&](int u) {
            suspicious[u] = true;
            for (int v : g[u]) {
                if (!suspicious[v]) {
                    dfs_mark(v);
                }
            }
        };
        dfs_mark(k);

        for (int u = 0; u < n; ++u) {
            if (!suspicious[u]) {
                for (int v : g[u]) {
                    if (suspicious[v]) {
                        vector<int> all(n);
                        for (int i = 0; i < n; ++i) all[i] = i;
                        return all;
                    }
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};
