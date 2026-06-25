class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int word_length = word.length();
        int word_ptr = 0;

        int abbr_length = abbr.length();
        int abbr_ptr = 0;

        while(word_ptr < word_length && abbr_ptr < abbr_length){

            if(isdigit(abbr[abbr_ptr])){
                if(abbr[abbr_ptr] == '0'){
                    return false;
                }
                else{
                    int number = 0;
                    while(abbr_ptr < abbr_length && isdigit(abbr[abbr_ptr])){
                        number = (number * 10) + (abbr[abbr_ptr] - '0');
                        abbr_ptr++;
                    }
                    word_ptr += number;
                }

            }
            else{
                if (word[word_ptr] == abbr[abbr_ptr]) {
                    word_ptr++; abbr_ptr++;
                } else {
                    return false;
                }
            }
        }
        return word_ptr == word_length && abbr_ptr == abbr_length;
    }
};