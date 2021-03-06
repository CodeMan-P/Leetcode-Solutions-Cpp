//dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 1){
            return 0;
        }
        
        int maxSum = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i-1] > 0){
                nums[i]+=nums[i-1];
            }
            maxSum = max(nums[i],maxSum);
        }
        return maxSum;
    }
};