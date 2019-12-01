class Solution {
public:
 
    bool isLegalBox(vector<vector<int>>& matrix,int tx,int ty,int bx,int by){
        for(int i = bx;i>=tx;i--){
            for(int j = by;j>=ty;j--){
                if(matrix[i][j] == 0){
                    return false;    
                }
            }
        }
        return true;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int w = min(m,n);
        int result = 0;
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
               for(int a = 0;a<w;a++){
                   if(i-a >=0 && j-a >=0){
                       if(isLegalBox(matrix,i-a,j-a,i,j)){
                           result++;
                       }else{
                            //跳过边长更大的矩形
                            break;  
                       }   
                    }
               }
            }    
        }
        return result;
    }
};