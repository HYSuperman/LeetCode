// this problem is very similar to "without repeative character series"


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int p1 = 0;
        int p2 = 0;
        int lastZero = 0;
        int maxLength = 0;
        int zeronum = 0;
        
        for(;p1 < nums.size();p1++){
            if(!nums[p1]){
                zeronum++;
                if(zeronum > 1){
                    p2 = lastZero + 1;
                    zeronum--;
                }
                lastZero = p1;
            }
            maxLength = max(maxLength, p1 - p2 + 1);
        }
        return maxLength;
        
    }
};