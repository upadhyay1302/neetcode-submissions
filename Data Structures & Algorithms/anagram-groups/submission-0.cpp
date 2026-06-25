class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;

        for(auto i : strs){
            string s = i;
            sort(s.begin(),s.end());
            map[s].push_back(i);
        }
        vector<vector<string>> ans;

        for(auto it = map.begin(); it != map.end(); it++){
            // vector<string> ans1;
            // cout << i << endl;
            ans.push_back(it->second);
        }

        return ans;
    }
};
