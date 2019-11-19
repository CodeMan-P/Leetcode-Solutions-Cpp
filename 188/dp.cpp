//refer:
// dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
//               max(   选择 rest  ,           选择 sell      )

// 解释：今天我没有持有股票，有两种可能：
// 要么是我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有；
// 要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。

// dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
//               max(   选择 rest  ,           选择 buy         )

// 解释：今天我持有着股票，有两种可能：
// 要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票；
// 要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。

// 作者：labuladong
// 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    //k +oo 贪心
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for(int i = 1;i<prices.size();i++){
            if(prices[i] > prices[i-1]){
                ret +=prices[i] - prices[i-1];
            }
        }
        return ret;
    }
    int maxProfitByDp(int k, vector<int>& prices){
        int days = prices.size();
        // int dp[days][k+1][2];
        
        // for(int i = 0;i<=k;i++){
        //     dp[0][i][0] = 0;
        //     dp[0][i][1] = -prices[0];
        // }

        // for(int i = 1;i<days;i++){
        //     for(int j = 1;j<=k;j++){
        //         //休息，卖出
        //         dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
        //         //休息，买
        //         //j-1==0表示无法交易
        //         dp[i][j][1] = max(dp[i-1][j][1],j==1? -prices[i]:(dp[i-1][j-1][0] - prices[i]));
        //     }
        // }
        // return dp[days-1][k][0];
        int dp[k+1][2];
        for(int i = 0;i<=k;i++){
            dp[i][0] = 0;
            dp[i][1] = INT_MIN;
        }
        for(int i = 0;i<days;i++){
            for(int j = 1;j<=k;j++){
                
                //休息，卖出
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                //休息，买
                //j-1==0表示无法交易
                dp[j][1] = max(dp[j][1],dp[j-1][0] - prices[i]);
            }
        }
        return dp[k][0];
    }
    int maxProfit(int k, vector<int>& prices) {
        
        int days = prices.size();
        if(k<=0 || days == 0){
            return 0;
        }
        k = min(k,days);
        if(k>= days/2){
            return maxProfit(prices);
        }else{
            return maxProfitByDp(k,prices);
        }
        
    }
};