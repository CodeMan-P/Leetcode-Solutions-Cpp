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
    
    bool backtrack(string& s,string& p){
        int sptr = 0;
        int pptr = 0;
        int sMatchIndex = -1;
        int pMatchIndex = -1;
        while(sptr < s.size()){
            if(s[sptr] == p[pptr] || p[pptr] == '?'){
                ++sptr;
                ++pptr;
                continue;
            }

            if(p[pptr] == '*'){
                //btk point

                //* match n char ->false  
                //n+1 btk
                
                sMatchIndex = sptr;
                
                pMatchIndex = ++pptr;
                continue;
            }

            if(sMatchIndex != -1){
                sptr = ++sMatchIndex;
                pptr = pMatchIndex;
                continue;
            }
            return false;
        }
        while(pptr<p.size()){
            if(p[pptr++]!='*'){
                return false;
            }
        }
        return true;
    }
    bool isMatch(string s, string p) {
        return backtrack(s,p);
    }
};