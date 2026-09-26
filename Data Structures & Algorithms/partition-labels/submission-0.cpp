class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]] = i;
        }
        for(auto &p : mp){
            cout << p.first << " " << p.second << endl;
        }
        vector<int>res;

        int size = 0;
        int end = 0;

        for(int i = 0; i < s.size(); i++){
            size++;
            end = max(end, mp[s[i]]);
            if(i == end){
                res.push_back(size);
                size= 0;
            }
        }
        return res;
    }
};

/**

"xyxxyzbzbbisl"

x size = 1, end = 3 i = 0
y size = 2 end = 4 i= 1
x size = 3 end = 4 i = 2
x size = 3 end = 4 i = 3

size = 0, end = 0

s 11
i 10
b 9
z 7
l 12
y 4
x 3


**/


