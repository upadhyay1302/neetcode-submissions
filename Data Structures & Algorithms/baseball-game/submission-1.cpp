class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+"){
                if(!st.empty()){
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    int insertNum = num1 + num2;
                    st.push(num2);
                    st.push(num1);
                    st.push(insertNum);
                }
            }
            else if(operations[i] == "D"){
                if(!st.empty()){
                    int numTop = st.top();
                    int numToInsert = numTop * 2;
                    st.push(numToInsert);
                }
            }
            else if(operations[i] == "C"){
                st.pop();
            }
            else{
                int num = stoi(operations[i]);
                st.push(num);
            }
        }

        int ans = 0;

        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }

        return ans;
    }
};