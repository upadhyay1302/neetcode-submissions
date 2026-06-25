class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> countS1(26, 0);
        vector<int> countS2(26, 0);

        if(s1.length() > s2.length()) return true;

        for(int i = 0; i < s1.length(); i++){
            char ch1 = s1[i];
            char ch2 = s2[i];

            countS1[ch1 - 97]++;
            countS2[ch2 - 97]++;
        }

        if(countS1 == countS2) return true;

        for(int i = s1.length(); i < s2.length(); i++){
            char ch1 = s2[i];
            char ch2 = s2[i - s1.length()];
            countS2[ch1 - 97]++;
            countS2[ch2 - 97]--;
            if(countS1 == countS2) return true;
        }
        return false;
    }
};
