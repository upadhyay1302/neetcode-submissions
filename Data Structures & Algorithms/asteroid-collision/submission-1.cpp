class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++){
            int a = asteroids[i];

            while(!st.empty() && st.top() > 0 && a < 0){
                int sum = st.top() + a;

                cout << sum << endl;

                if(sum > 0){
                    a = 0;
                }
                else if(sum < 0){
                    st.pop();
                }
                else{ //same
                    st.pop();
                    a = 0;
                }
            }

            if(a != 0) st.push(a);
        }

        vector<int> ans(st.size());
        int i = st.size() -1 ;
        while(!st.empty()){
            ans[i] = st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};