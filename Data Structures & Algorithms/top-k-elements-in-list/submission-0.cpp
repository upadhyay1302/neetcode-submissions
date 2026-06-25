class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;

        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }

        vector<pair<int,int>> arr;

        for(auto i : map){
            arr.push_back({i.second, i.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> ans;

        for(int i = 0; i < k ; i++){
            ans.push_back(arr[i].second);
        }

        return ans;
        
    }
};
