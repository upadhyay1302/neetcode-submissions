class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int> st(nums.begin(), nums.end());
        int i = 0;
        for(int num : st){
            nums[i] = num;
            i++;
        }
        return st.size();
    }
};