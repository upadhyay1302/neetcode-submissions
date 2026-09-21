class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;


        for(int i = 0; i < asteroids.size(); i++){
            int a = asteroids[i];
            
            while(!st.empty() && a < 0 && st.top() > 0){
                int sum = a + st.top();
                cout << sum << endl;

                if(sum < 0){
                    st.pop();
                }
                else if(sum > 0){
                    a = 0;
                }
                else{ // same
                    a = 0;
                    st.pop();
                }
            }
            if(a != 0) st.push(a);
        }
        vector<int>ans(st.size());
        int i = st.size()-1;
        while(!st.empty()){
            ans[i] = st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};

// [2,5,-4,-1]
// stack = 2,4