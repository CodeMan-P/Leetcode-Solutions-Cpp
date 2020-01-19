//分治法
class Solution {
public:

    int crossSum(vector<int>& nums,int left,int right,int midIndex){
        if(left == right){
            return nums[left];
        }
        int leftSubsum = INT_MIN;
        int currSum = 0;
        for(int i = midIndex;i>=left;i--){
            currSum+= nums[i];
            leftSubsum = max(leftSubsum,currSum);
        }
        int rightSubsum = INT_MIN;
        currSum = 0;
        for(int i = midIndex+1;i<=right;i++){
            currSum+= nums[i];
            rightSubsum = max(rightSubsum,currSum);
        }
        return leftSubsum + rightSubsum;
    }
    int maxSubArray(vector<int>& nums,int left,int right){
        if(left == right){
            return nums[left];
        }
        int midIndex = (left+right)/2;
        int lSum = maxSubArray(nums,left,midIndex);
        int rSum = maxSubArray(nums,midIndex+1,right);
        int cSum = crossSum(nums,left,right,midIndex);
        cout <<left<<","<<right<<":"<<lSum<<" "<<cSum<<" " <<rSum <<endl;
        return max(max(lSum,rSum),cSum);
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums,0,nums.size()-1);
    }
};