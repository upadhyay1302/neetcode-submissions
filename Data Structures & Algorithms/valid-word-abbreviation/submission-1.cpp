class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;

        while(i < word.length() && j < abbr.length()){
            if(abbr[j] == '0') return false;

            if(isalpha(abbr[j])){
                if(word[i] == abbr[j]){
                    i++;
                    j++;
                }
                else{
                    return false;
                }
            }
            else{
                int subLen = 0;
                while(j < abbr.length() && isdigit(abbr[j])){
                    subLen = subLen * 10 + (abbr[j] - '0');
                    j++;
                }
                i += subLen;
            }
        }
        return i == word.length() && j == abbr.length();
    }
};