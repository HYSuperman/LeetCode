class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int len = nums.size();
        
        if(len < 3) return res;
        // first sort
        sort(nums.begin(), nums.end());
        
        for(int i = 0;i < len - 2;i++){
            int l = i + 1, r = len - 1;
            // degenerade to a 2-sum problem(sorted)
            while(l < r){
                int suum = nums[i] + nums[l] + nums[r];
                if(suum == 0){
                    int tmp[] = {nums[i], nums[l], nums[r]};
                    res.push_back(vector<int>(tmp, tmp + sizeof(tmp)/sizeof(int)));
                    // jump over the duplicate ones
                    while(l < r && nums[l] == nums[l + 1]){l++;}
                    while(l < r && nums[r] == nums[r - 1]){r--;}
                    l++;r--;
                }
                if(suum > 0){r--;}
                if(suum < 0){l++;}
            }
            // jump over the duplicate ones
            while(i + 1 < len && nums[i] == nums[i + 1]){i++;}
        }
        return res;
    }
};