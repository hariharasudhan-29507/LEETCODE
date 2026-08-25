#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int totalOnes = 0;
        for (char c : s) if (c == '1') totalOnes++;

        vector<int> groupStart, groupLen;
        vector<int> groupId(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    groupLen[groupLen.size() - 1]++;
                } else {
                    groupStart.push_back(i);
                    groupLen.push_back(1);
                }
            }
            groupId[i] = groupStart.size() - 1;
        }

        int numGroups = groupStart.size();
        vector<int> result;
        if (numGroups == 0) {
            result.assign(queries.size(), totalOnes);
            return result;
        }

        vector<int> pairSum(numGroups > 1 ? numGroups - 1 : 0);
        for (int i = 0; i + 1 < numGroups; i++) {
            pairSum[i] = groupLen[i] + groupLen[i + 1];
        }

        int maxPower = 1;
        while ((1 << maxPower) <= (int)pairSum.size()) maxPower++;

        vector<vector<int>> table;
        if (!pairSum.empty()) {
            table.assign(maxPower + 1, vector<int>(pairSum.size()));
            table[0] = pairSum;
            for (int power = 1; power <= maxPower; power++) {
                for (int i = 0; i + (1 << power) <= (int)pairSum.size(); i++) {
                    table[power][i] = max(table[power - 1][i], table[power - 1][i + (1 << (power - 1))]);
                }
            }
        }

        auto rangeMax = [&](int left, int right) -> int {
            int length = right - left + 1;
            int power = 31 - __builtin_clz(length);
            return max(table[power][left], table[power][right - (1 << power) + 1]);
        };

        for (auto& query : queries) {
            int l = query[0], r = query[1];

            int leftRemain = (groupId[l] == -1) ? -1 : (groupLen[groupId[l]] - (l - groupStart[groupId[l]]));
            int rightRemain = (groupId[r] == -1) ? -1 : (r - groupStart[groupId[r]] + 1);

            int rightGroupOrBefore = (s[r] == '1') ? groupId[r] : groupId[r] - 1;
            int firstMiddleGroup = groupId[l] + 1;
            int lastMiddleGroup = rightGroupOrBefore - 1;

            int best = totalOnes;

            if (s[l] == '0' && s[r] == '0' && groupId[l] + 1 == groupId[r]) {
                best = max(best, totalOnes + leftRemain + rightRemain);
            } else if (firstMiddleGroup <= lastMiddleGroup) {
                best = max(best, totalOnes + rangeMax(firstMiddleGroup, lastMiddleGroup));
            }

            if (s[l] == '0' && groupId[l] + 1 <= rightGroupOrBefore) {
                best = max(best, totalOnes + leftRemain + groupLen[groupId[l] + 1]);
            }

            if (s[r] == '0' && groupId[l] < groupId[r] - 1) {
                best = max(best, totalOnes + rightRemain + groupLen[groupId[r] - 1]);
            }

            result.push_back(best);
        }

        return result;
    }
};
