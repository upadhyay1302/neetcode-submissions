class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){
            string ch = tokens[i];

            if(ch != "+" && ch != "-" && ch != "*" && ch != "/"){
                int num = stoi(ch);
                st.push(num);
            }
            else{
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                if(ch == "+") st.push(first + second);
                else if(ch == "-") st.push(first - second);
                else if(ch == "*") st.push(first * second);
                else if(ch == "/") st.push(first / second);
            }
        }
        return st.top();
    }
};