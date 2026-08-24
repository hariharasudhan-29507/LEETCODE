class Solution {
public:
    string smallestNumber(string num, long long t) {
        int n = num.size();
        vector<int> digits(n);
        for (int i = 0; i < n; i++) digits[i] = num[i] - '0';

        long long primes[4] = {2, 3, 5, 7};
        vector<int> max_exp, primeIdx;
        long long x = t;
        for (int p = 0; p < 4; p++) {
            int e = 0;
            while (x % primes[p] == 0) { e++; x /= primes[p]; }
            if (e > 0) { max_exp.push_back(e); primeIdx.push_back(p); }
        }
        if (x != 1) return "-1";

        int k = max_exp.size();
        vector<array<int,4>> digit_exp(10);
        for (int d = 1; d <= 9; d++) {
            int val = d;
            array<int,4> e{0,0,0,0};
            for (int p = 0; p < 4; p++)
                while (val % (int)primes[p] == 0) { e[p]++; val /= (int)primes[p]; }
            for (int i = 0; i < k; i++) digit_exp[d][i] = e[primeIdx[i]];
        }

        vector<int> mods(k + 1, 1);
        for (int i = k - 1; i >= 0; i--) mods[i] = mods[i + 1] * (max_exp[i] + 1);
        int total_states = mods[0];

        auto encode = [&](const vector<int>& e) {
            int code = 0;
            for (int i = 0; i < k; i++) code += e[i] * mods[i + 1];
            return code;
        };
        auto decode = [&](int code, vector<int>& e) {
            e.resize(k);
            for (int i = 0; i < k; i++) { e[i] = code / mods[i + 1]; code %= mods[i + 1]; }
        };
        auto transition = [&](int state, int d) {
            vector<int> e;
            decode(state, e);
            for (int i = 0; i < k; i++) e[i] = min(e[i] + digit_exp[d][i], max_exp[i]);
            return encode(e);
        };

        int full_state = total_states - 1;

        vector<int> deficit(total_states);
        for (int s = 0; s < total_states; s++) {
            vector<int> e;
            decode(s, e);
            int def = 0;
            for (int i = 0; i < k; i++) def += max_exp[i] - e[i];
            deficit[s] = def;
        }
        vector<int> order(total_states);
        for (int s = 0; s < total_states; s++) order[s] = s;
        sort(order.begin(), order.end(), [&](int a, int b) { return deficit[a] < deficit[b]; });

        const int INF = INT_MAX / 2;
        vector<int> minDigits(total_states, INF);
        minDigits[full_state] = 0;
        for (int s : order) {
            if (deficit[s] == 0) continue;
            int best = INF;
            for (int d = 1; d <= 9; d++) {
                int ns = transition(s, d);
                if (ns == s) continue;
                if (minDigits[ns] + 1 < best) best = minDigits[ns] + 1;
            }
            minDigits[s] = best;
        }

        auto free_suffix = [&](int r, int state) {
            int m = minDigits[state];
            string pad(r - m, '1');
            string tail;
            int cur = state;
            for (int i = 0; i < m; i++) {
                int rem = m - i - 1;
                for (int d = 1; d <= 9; d++) {
                    int ns = transition(cur, d);
                    if (minDigits[ns] <= rem) {
                        tail += char('0' + d);
                        cur = ns;
                        break;
                    }
                }
            }
            return pad + tail;
        };

        vector<int> prefix_state(n + 1, 0);
        int zeroPos = n;
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) {
                if (zeroPos == n) zeroPos = i;
                prefix_state[i + 1] = prefix_state[i];
            } else {
                prefix_state[i + 1] = transition(prefix_state[i], digits[i]);
            }
        }

        if (zeroPos == n && prefix_state[n] == full_state) return num;

        int posLimit = (zeroPos < n) ? zeroPos : n - 1;
        for (int pos = posLimit; pos >= 0; pos--) {
            for (int d = digits[pos] + 1; d <= 9; d++) {
                int ns = transition(prefix_state[pos], d);
                int rem = n - 1 - pos;
                if (rem >= minDigits[ns])
                    return num.substr(0, pos) + char('0' + d) + free_suffix(rem, ns);
            }
        }

        long long L = max((long long)n + 1, (long long)minDigits[0]);
        return free_suffix((int)L, 0);
    }
};
