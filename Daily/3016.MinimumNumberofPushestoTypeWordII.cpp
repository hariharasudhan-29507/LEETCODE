class Solution {
public:
    int minimumPushes(string word) {
        int count[26] = {0};
        for (char c : word) {
            count[c - 'a']++;
        }
        sort(count, count + 26, greater<int>());
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) break;
            int presses = i / 8 + 1;
            total += presses * count[i];
        }
        return total;
    }
};
