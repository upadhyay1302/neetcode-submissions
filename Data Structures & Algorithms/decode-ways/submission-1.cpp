class Solution {
public:
    int solve(int i, string& s, int n, vector<int>&DP){
        cout << i << endl;
        if(i == n) return 1;
        cout << i << endl;

        if(s[i] == '0') return 0;

        if(DP[i] != -1) return DP[i];

        int result = solve(i + 1, s, n, DP);

        if(i + 1 < n){
            if((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6')){
                result += solve(i + 2, s, n, DP);
            }
        }

        DP[i] = result;
        return DP[i];  
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int>DP(n, -1);
        return solve(0, s, n, DP);
    }
};