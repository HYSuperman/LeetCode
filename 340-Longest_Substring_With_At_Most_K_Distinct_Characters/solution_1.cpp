// this is a concise solution than solution.cpp


class Solution {
public:

    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0) return 0;

        int charSet[128];
        fill_n(charSet, sizeof(charSet)/sizeof(int), -1);
        
        int p1 = 0;
        int p2 = 0;
        
        int maxLength = 0;
        int ss = 0;
        
        for(;p1 < s.length();p1++){
            if(charSet[s[p1]] == -1){
                ss++;
                if(ss > k){
                    char charToDelete;
                    int minPos = s.length();
                    /* 
                        this is the most important part in the whole solution
                        when we meet the k+1 distinct char, we have to drop one
                        from before. we go through the map to find the char which 
                        has the minimal position to drop
                    */
                    for(int i = 0;i < sizeof(charSet)/sizeof(int);i++){
                        if(charSet[i] != -1 && charSet[i] + 1 < minPos){
                            minPos = charSet[i] + 1;
                            charToDelete = i;
                        }
                    }
                    p2 = minPos;
                    charSet[charToDelete] = -1;
                    ss--;
                }
            }
            charSet[s[p1]] = p1;
            maxLength = max(maxLength, p1 - p2 + 1);
        }
        
        return maxLength;
    }
};