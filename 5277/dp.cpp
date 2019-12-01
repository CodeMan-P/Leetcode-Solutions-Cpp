// refer:
// https://leetcode-cn.com/circle/discuss/qFIvLJ/
// @jiangyanerpang
// @小白二号

class Solution {
public:
    //记录（i，j）为右下角的最大正方形边长
    int dp[305][305];
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        memset(dp,0,sizeof(dp));
        
        int result = 0;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0){
                    continue;
                }
                dp[i][j] = 1;
                //i ==0 or j==0 最大边长只能是1
                if(i!=0 && j!=0){
                    int tmpWidth = min(dp[i-1][j],dp[i][j-1]);
                    
                    if(tmpWidth != 0){
                        if(matrix[i-tmpWidth][j-tmpWidth] == 1){
                            dp[i][j] = tmpWidth + 1;
                        }else{
                            dp[i][j] = tmpWidth;
                        }
                    }
                }
                result += dp[i][j];
            }
        }
        return result;
    }
};