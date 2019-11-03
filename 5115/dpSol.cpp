//Referer  https://leetcode-cn.com/circle/discuss/oWdw06/  @小白二号
class Solution {
public:
    
    int memo[102][102];
    int dp(vector<int>& arr,int lt,int rt){
        if(lt==rt){
            return 1;
        }
        if(lt>rt){
            return 0;
        }
        if(lt+1 == rt){
            if(arr[lt] == arr[rt]){
                return 1;
            }else if(arr[lt] != arr[rt]){
                return 2;
            }
        }
        if(memo[lt][rt] != -1){
            return memo[lt][rt];
        }
        int ret = 0x3fffffff;
        
        for(int i = rt;i>=lt;i--){
            if(arr[i] != arr[lt]){
                continue;
            }
            //max(dp[left+1][i−1],1)+dp[i+1][right]
            //1 -> (arr[lt],arr[i]) ->()
            int ldp = max(dp(arr,lt+1,i-1),1);
            int rdp = dp(arr,i+1,rt);
            ret = min(ret,ldp+rdp);
        }
        memo[lt][rt]=ret;
        return ret;
    }
    int minimumMoves(vector<int>& arr) {
        memset(memo,-1,sizeof(memo));
        return dp(arr,0,arr.size()-1);
        
    }
};