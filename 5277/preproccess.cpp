//https://leetcode.com/neal_wu/
class Solution {
public:
    int sum[305][305];
    int getSum(int x1,int x2,int y1,int y2){
        return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
    }
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        //sum -> 0,0 ~ i,j 矩阵求和
        memset(sum,0,sizeof(sum));
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
            }
        }
        int w = min(n,m);
        int result = 0;
        
        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                for(int a = 1;a<=w;a++){
                    if(i+a <=m && j+a <=n){
                        if(getSum(i,i+a,j,j+a) == a*a){   
                            result++;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};