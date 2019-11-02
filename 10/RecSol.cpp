class Solution {
public:
    
    bool dfs(string& s,string& p,int i,int j,vector<vector<int>>& memo){
        if(memo[i][j] != -1){
            return memo[i][j] == 1;
        }
        int pOffset = p.size()-j;
        int sOffset = s.size()-i;
        bool flag = false;
        if(pOffset == 0){
            flag = sOffset==0;

        }else{
            bool headMatch = !(sOffset==0) && (p[j] == s[i] || p[j] == '.');
                
            if(pOffset>=2 && p[j+1] == '*'){
                flag= (dfs(s,p,i,j+2,memo) ||
                        (headMatch && dfs(s,p,i+1,j,memo))
                        );
            }else{
                flag= headMatch && dfs(s,p,i+1,j+1,memo);
            }
        }
        memo[i][j] = flag? 1:0;
        return flag;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> memo = vector<vector<int>>(s.size()+1,vector<int>(p.size()+1,-1));
        return dfs(s,p,0,0,memo);
    }
};