class Solution {
public:
    bool solve(int i, int open, string s, vector<vector<int>>&DP){
        if(open < 0) return false;

        if(DP[i][open] != -1){
            return DP[i][open] ;
        }

        if(i == s.length()) return open == 0;

        if(s[i] == '('){
            DP[i][open] = solve(i + 1, open + 1, s, DP);
        }
        else if(s[i] == ')'){
            DP[i][open] = solve(i + 1, open - 1, s, DP);
        }
        else{
            DP[i][open] = solve(i + 1, open, s, DP) ||
                   solve(i + 1, open + 1, s, DP)||
                   solve(i + 1, open - 1, s, DP);
        }
        return DP[i][open];
    }
    bool checkValidString(string s) {
        vector<vector<int>>DP(s.length()+1, vector<int>(s.length()+1, -1));
        return solve(0, 0, s, DP);
    }
};
