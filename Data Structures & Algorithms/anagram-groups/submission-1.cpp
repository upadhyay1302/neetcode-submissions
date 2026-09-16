class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>>mp;

        for(auto& s: strs){
            string currS = s;
            sort(s.begin(), s.end());
            mp[s].push_back(currS);
        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;


    }
};
