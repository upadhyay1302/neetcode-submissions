class Solution {
public:
    bool solve(string s, vector<string>&wordDict, int i, vector<int>&DP){
        if(i == s.length()) return true;

        if(DP[i] != -1) return DP[i];
        
        for(string word : wordDict){
            if(i + word.length() <= s.length() 
            && s.substr(i, word.length()) == word){
                if(solve(s, wordDict, i + word.length(), DP)){
                    DP[i] = true;
                    return true;
                }
            }
        }
        DP[i] = false;
        return DP[i];

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>DP(s.length(), -1);
        return solve(s, wordDict, 0, DP);
    }
};
