class Solution {
public:
    bool solve(int i, int j, string&s1, string&s2, string&s3, vector<vector<int>>&DP){
        int k = i + j;

        if(k == s3.size()){
            return i == s1.size() && j == s2.size();
        }

        if(DP[i][j] != -1) return DP[i][j];

        bool ans1 = false;
        bool ans2 = false;

        if(i < s1.size() && s1[i] == s3[k]){
            ans1 = solve(i + 1, j, s1, s2, s3, DP); 
        }
        if(j < s2.size() && s2[j] == s3[k]){
            ans2 = solve(i, j + 1, s1,s2,s3, DP);
        }

        DP[i][j] = ans1 || ans2;
        return DP[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> DP(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solve(0, 0, s1, s2, s3, DP);
    }
};
