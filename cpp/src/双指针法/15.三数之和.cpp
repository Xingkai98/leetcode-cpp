class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<=2)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0){  // 因为已经从小到大排序，若i已经大于0，则肯定不会有答案
                return ans;
            }         
            if(i > 0 && nums[i] == nums[i-1]){  //若i相同，其他数都相同，则得到的结果肯定也相同，可以直接跳过
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right]; 
                if(sum < 0){
                    left++;
                }
                else if(sum > 0){
                    right--;
                }
                else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // left right的去重工作
                    while(left < right && nums[left + 1] == nums[left]) left++;
                    while(left < right && nums[right - 1] == nums[right]) right--;
                    // 去重之后，left和right同时向内收缩，寻找新的答案
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};

// -4，-4，0，0，1，3，4，4 一个涉及到所有重复情况的例子