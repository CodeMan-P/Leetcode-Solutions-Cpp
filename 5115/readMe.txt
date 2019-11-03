//Referer  https://leetcode-cn.com/circle/discuss/oWdw06/  @小白二号
动态规划

令 dp[left][right]
表示区间 [left,right] 删除完的最少操作
那么我们考察 arr[left] 这个元素，这个元素要么自己删除，要么跟另一个等于 arr[left] 的元素一起删除

假设 arr[left]=arr[i]

那么 left 可以跟 i 一起删除

这时候的操作数就是 max(dp[left+1][i−1],1)+dp[i+1][right]

第二项好理解，第一项为啥是 max(dp[left+1][i−1],1)

因为 left 和 i 可以跟 [left+1,i−1] 里面某个回文数一起删除，
如果 [left+1,i−1] 本身是个空集，那么 left 跟 i 一起删除，就是一次操作

ok，dp[left][right]就是枚举所有的跟 arr[left] 相等的 arr[i]，对每个i计算一个操作数，求最小即可

作者：小白二号
链接：https://leetcode-cn.com/circle/discuss/oWdw06/view/MbwH9G/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。