// build a hashTable which saves the indexes of each number (this is done on the fly)
// and check if target-num is in the hash table.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> res;
        for(int i = 0;i < nums.size();i++){
            // check hashtable
            if(hashMap.find(target - nums[i]) != hashMap.end()){
                res.push_back(i);
                res.push_back(hashMap[target - nums[i]]);
                return res;
            }
            // build hashtable on the fly
            hashMap[nums[i]] = i;
        }
    }
};