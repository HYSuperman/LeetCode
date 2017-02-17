// this is a concise solution than solution.cpp

/*
*  keep two pointers:
*  a b c a b c
*      ^   ^
*      s   e
*  s and e are two pointers, s represents the start of the substring ending at b (longest one), e represents the end.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashSet[128];
        fill_n(hashSet, sizeof(hashSet)/sizeof(int), -1);

        int i = 0;// pointer one
        int subStart = 0;// pointer two

        int maxLength = 0;
        
        for(;i < s.length();i++){
            if(hashSet[s[i]] != -1){
                // update the start pointer if needed
                subStart = max(subStart, hashSet[s[i]] + 1);
            }
            hashSet[s[i]] = i;
            maxLength = max(maxLength, i - subStart + 1);
        }
        return maxLength;
    }
};


/* Note:
    1.if fill an c++ int array with NULL, it will be automatic converted to 0:
                array[0] = NULL ==== array[0] = 0
    
    2.sizeof() opertion returns the byte size of the objects i.e. how many byte it has

*/