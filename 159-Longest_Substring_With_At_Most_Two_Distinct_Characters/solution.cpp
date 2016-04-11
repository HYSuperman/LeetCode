// Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
// For example, Given s = “eceba”,
// T is "ece" which its length is 3.

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // routine null check
        if(s.empty()){
            return 0;
        }
        // hashtable to record character's last appearence position
        int h[128] = {0};
        // first character
        int first = -1;
        // second character
        int second = -1;

        int maxx = 0;
        int temp = 0;
        
        for(int i = 0;i < s.length();i++){
            // if the new character is one of two
            if(s[i] == first || s[i] == second){
                h[s[i]] = i + 1;
                temp++;
            }
            // if it is note one of two
            // we must abandon one of two
            else{
                // first update max value
                if(temp > maxx){
                    maxx = temp;
                }
                // if first and second both exists
                if(first != -1 && second != -1){
                    int cutPos;
                    // decide which one we shall abandon
                    // we drop the one whose last position is smaller
                    // thus preserve the large temp value
                    if(h[first] < h[second]){
                        cutPos = h[first];
                        first = s[i];
                    }
                    else{
                        cutPos = h[second];
                        second = s[i];
                    }
                    // calculate temp value
                    temp = i - cutPos + 1;
                }
                // if first and second value has not yet been assigned
                else{
                    if(first == -1){
                        first = s[i];
                    }
                    else{
                        second = s[i];
                    }
                    temp++;
                }
                // update postion info
                h[s[i]] = i + 1;
            }
        }
        // don't forget
        if(temp > maxx){
            maxx = temp;
        }
        return maxx;
    }
};