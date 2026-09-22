class Solution {
public:
    bool isValid(string curr){
        int count = 0;
        for(char ch : curr){
            if(ch == '(') count++;
            else count--;
            if(count < 0) return false;
        }
        if(count == 0) return true;
        else return false;
    }
    void solve(int n, vector<string>&ans, string curr, int open, int close){
        if(curr.size() == 2*n){

                ans.push_back(curr);
        
            return;
        }

        if(open < n){
              curr.push_back('(');
        solve(n, ans, curr, open +1, close);
        curr.pop_back();
        }
      
        if(close < open){
            curr.push_back(')');
        solve(n, ans, curr, open, close+1);
        curr.pop_back();
        }


    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(n, ans, "", 0, 0);

        return ans;
    }
};
