class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                cout << temperatures[i] << ">" << st.top() << endl;
                st.pop();
            }

            if(!st.empty()){
                cout << st.top() - i << endl;
                ans[i] = st.top() - i;
            }

            st.push(i);
        }
        return ans;
    }
};
