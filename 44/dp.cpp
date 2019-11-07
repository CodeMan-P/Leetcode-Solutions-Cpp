static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    
    bool dp(string& s,string& p){
        int sSize = s.size();
        int pSize = p.size();
        vector<vector<bool>> memo = vector<vector<bool>>(s.size()+1,vector<bool>(p.size()+1,0));
        //自底向上
        //memo[sSize][pSize] 对应  “” 匹配 “”
        memo[sSize][pSize] = 1;
        for(int j = pSize-1;j>=0;j--){
            memo[sSize][j]=p[j] =='*' &&  memo[sSize][j+1];
        }
        for(int i = sSize-1;i>=0;i--){
            for(int j = pSize-1;j>=0;j--){
                if(p[j] =='*' ){
                                //* 匹配0个字符(即越过当前*)  ||  *匹配多个字符
                    memo[i][j] = memo[i][j+1] ||  memo[i+1][j];
                }else{
                                    //（同字符匹配 || 任意字符通配）
                    bool headMatch =p[j] == s[i] || p[j] == '?' ;
                                //首字符匹配 && 下一对匹配
                    memo[i][j] =headMatch && memo[i+1][j+1];
                }
            }   
        }
        return memo[0][0];
    }
    bool isMatch(string s, string p) {
        return dp(s,p);
    }
};