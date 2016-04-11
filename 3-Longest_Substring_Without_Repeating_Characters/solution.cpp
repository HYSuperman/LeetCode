// Given a string, find the length of the longest substring without repeating characters. 
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
// For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // routine null check
        if(s.empty()){
            return 0;
        }
        // hash table to store the last place a character emerged
        int h[128] = {0};
        // max length of the substring
        int maxx = 0;
        // temp stores the local length of substring
        int temp = 0;

        for(int i = 0;i < s.length();i++){
            // if this character has never emerged
            // just record its position and add one to the length
            if(!h[s[i]]){
                h[s[i]] = i + 1;
                temp++;
            }
            // if this character has emerged before...
            // then we must cut the substring from the last time it has
            // emerged
            else{
                // first update max value if needed
                if(temp >= maxx){
                    maxx = temp;
                }
                // if this character's appearence is in the substring
                // cut the substring from this point
                if(i- h[s[i]] + 1 <= temp){
                    temp = i - h[s[i]] + 1;
                }
                // of just add one to length
                else{
                    temp++;
                }
                // update position info
                h[s[i]] = i + 1;
            }
        }
        // don't forget
        if(temp >= maxx){
            maxx = temp;
        }
        return maxx;
    }
};