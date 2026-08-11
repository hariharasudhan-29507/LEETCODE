class Solution {
public:
    int n;
    vector<int> t;
    int solve(vector<int>& stones , int i){

        if(i>=n){ return 0;}

        if(t[i] != -1){
            return t[i];
        }
        int res = stones[i] - solve(stones, i+1);
        if(i+1 < n){
            res = max(res , stones[i]+stones[i+1] - solve(stones ,i+2));
        }
        if(i+2 < n){
            res = max(res , stones[i]+stones[i+1]+stones[i+2]- solve(stones ,i+3));
        }

        return t[i] =res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        t.resize(n+1, -1);
        int diff = solve(stoneValue,0);
        if(diff < 0) return "Bob";
        else if (diff > 0) return "Alice";
        else return "Tie";
    }
};
