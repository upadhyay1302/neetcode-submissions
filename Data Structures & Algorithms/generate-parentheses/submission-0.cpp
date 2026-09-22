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
    void solve(int n, vector<string>&ans, string curr){
        if(curr.size() == 2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(n, ans, curr);
        curr.pop_back();

        curr.push_back(')');
        solve(n, ans, curr);
        curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(n, ans, "");

        return ans;
    }
};
