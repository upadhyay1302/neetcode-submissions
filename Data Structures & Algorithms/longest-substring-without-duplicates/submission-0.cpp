class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        for(int i = 0; i < s.length(); i ++){
            unordered_map<char,int>mp;

            for(int j =i; j < s.length(); j++){
                char ch = s[j];

                if(mp[ch] != 0){
                    break;
                }
                mp[ch]++;
                ans = max(ans, j - i + 1);
            }
        }


        return ans;
    }
};
