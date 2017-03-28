// if it is sorted we can use two pointers.
// the first pointer points to the lower value and increase
// the second pointer points to the upper value and decrease


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int len = numbers.size();
        
        int l = 0, r  = len - 1;

        while(l < r){
            int suum = numbers[l] + numbers[r];
            // if sum of two value is smaller than target
            if(suum < target){l++;}
            // if sum of two value is bigger than target
            else if(suum > target){r--;}
            // equal
            else{
                res.push_back(l + 1);
                res.push_back(r + 1);
                return res;
            }
        }
    }
};