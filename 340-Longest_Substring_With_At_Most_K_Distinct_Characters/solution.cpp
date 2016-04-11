// Given a string, find the length of the longest substring T that contains at most k distinct characters.
// For example, Given s = “eceba” and k = 2,
// T is "ece" which its length is 3.

// This proble is similar to problem 3, 159.
// For detailed comments check them 
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {

        // routine null check
        if(s.empty() || k == 0){
            return 0;
        }
        
        // hashtable to store last appearence position
        // -1 represents the character is not in the substring
        int h[128];
        // initialize to -1
        for(int i = 0;i < 128;i++){
            h[i] = -1;
        }

        int maxx = 0;
        int temp = 0;
        // how many distinct characters we already have
        int numOfDis = 0;

        for(int i = 0;i < s.length();i++){
            // if this character is not in the substring
            // add it and add number of distinct characters
            if(h[s[i]] == -1 && numOfDis < k){
                
                numOfDis++;
                temp++;
            }
            // if it is in the substring
            // just add the length
            else if(h[s[i]] != -1){
                temp++;
            }
            // if it is not in the substring
            // and exceeds k
            // we need to drop a character to take in this one
            else if(numOfDis >= k){
                // first update maxx if needed
                if(temp > maxx){
                    maxx = temp;
                }
                // compute where to cut the substring
                // we cut it from the minimun last appearence position
                // from all the characters which have appeared in the substring
                int cutPos = 2147483644;
                int cutJ;
                for(int j = 0;j < 128;j++){
                    if(h[j] != -1 && h[j] < cutPos){
                        cutPos = h[j];
                        cutJ = j;
                    }
                }
                // drop it
                h[cutJ] = -1;
                // update temp value
                temp = i - cutPos;
            }
            h[s[i]] = i;

        }

        if(temp > maxx){
            maxx = temp;
        }

        return maxx;
    }
};