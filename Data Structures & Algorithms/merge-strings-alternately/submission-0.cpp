class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int i = 0;
        int j = 0; 
        while(i < word1.length() && j < word2.length()){
            s.push_back(word1[i]);
            s.push_back(word2[j]);
            i++;
            j++;
        }
        while(i < word1.length()){
            s.push_back(word1[i]);
            i++;
        }
        while(j < word2.length()){
            s.push_back(word2[j]);
            j++;
        }
        return s;
    }
};