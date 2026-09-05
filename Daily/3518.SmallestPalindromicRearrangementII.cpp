class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        vector<int> half(26, 0);
        string mid = "";
        int m = 0;
        
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid += (char)(i + 'a');
            }
            half[i] = freq[i] / 2;
            m += half[i];
        }
        
        auto get_ways = [&](const vector<int>& f, long long target_k) {
            long long ways = 1;
            int curr_len = 0;
            for (int count : f) {
                if (count > 0) {
                    curr_len += count;
                    long long n = curr_len;
                    long long r = count;
                    
                    if (r > n - r) r = n - r;
                    long long cur_nCr = 1;
                    
                    for (int i = 1; i <= r; ++i) {
                        cur_nCr = cur_nCr * (n - i + 1) / i;
                        if (cur_nCr > target_k) {
                            cur_nCr = target_k + 1;
                            break;
                        }
                    }
                    ways *= cur_nCr;
                    if (ways > target_k) return target_k + 1;
                }
            }
            return ways;
        };
        
        if (get_ways(half, k) < k) {
            return "";
        }
        
        string first_half = "";
        for (int i = 0; i < m; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half[c] > 0) {
                    half[c]--;
                    long long ways = get_ways(half, k);
                    
                    if (ways >= k) {
                        first_half += (char)(c + 'a');
                        break; 
                    } else {
                        k -= ways;
                        half[c]++;
                    }
                }
            }
        }
        
        string res = first_half + mid;
        for (int i = m - 1; i >= 0; --i) {
            res += first_half[i];
        }
        return res;
    }
};
