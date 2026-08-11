class Solution {
public:
    vector<int> pickMaxDigits(vector<int>& numbers, int k) {
        vector<int> select;
        int removeCount = numbers.size() - k;
        for (int i = 0; i < numbers.size(); i++) {
            while (removeCount > 0 && !select.empty() && select.back() < numbers[i]) {
                select.pop_back();
                removeCount--;
            }
            select.push_back(numbers[i]);
        }
        select.resize(k);
        return select;
    }
    bool isFirstBigger(vector<int>& first, int i, vector<int>& second, int j) {
        while (i < first.size() && j < second.size()) {
            if (first[i] != second[j]) {
                return first[i] > second[j];
            }
            i++;
            j++;
        }
        return i < first.size();
    }
    vector<int> mergeTwoLists(vector<int>& first, vector<int>& second) {
        vector<int> res;
        int i = 0;
        int j = 0;
        while (i < first.size() || j < second.size()) {
            if (isFirstBigger(first, i, second, j)) {
                res.push_back(first[i]);
                i++;
            } else {
                res.push_back(second[j]);
                j++;
            }
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> res(k, 0);
        int start = max(0, k - size2);
        int end = min(k, size1);
        for (int take1 = start; take1 <= end; take1++) {
            int take2 = k - take1;
            vector<int> part1 = pickMaxDigits(nums1, take1);
            vector<int> part2 = pickMaxDigits(nums2, take2);
            vector<int> candidate = mergeTwoLists(part1, part2);
            if (candidate > res) {
                res = candidate;
            }
        }
        return res;
    }
};
