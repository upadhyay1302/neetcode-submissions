class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<string>st;

        for(int i = 0; i < s.length(); i++){

            if(s[i] != ']'){
                st.push(string(1, s[i]));
            }
            else{
                string sub = "";
                while(!st.empty() && st.top() != "["){
                    sub = st.top() + sub;
                    st.pop();
                }
                st.pop();

                string k = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    k = st.top() + k;
                    st.pop();
                }

                int mul = stoi(k);

                string temp = "";
                while(mul != 0){
                    temp += sub;
                    mul--; 
                }
                st.push(temp);
            }
        }

        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};