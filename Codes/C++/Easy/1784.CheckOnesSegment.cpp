class Solution {
public:
    bool checkOnesSegment(string s) {
        return strstr(s.c_str(), "01") == NULL;
    }
};
