//贪心法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 1){
            return 0;
        }
        int currSum = nums[0];
        int maxSum = nums[0];
        for(int i = 1;i<n;i++){
            currSum = max(nums[i],currSum+nums[i]);
            maxSum = max(currSum,maxSum);
        }
        return maxSum;
    }
};