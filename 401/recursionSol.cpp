//n个数中取k个数
//参考：原文链接：https://blog.csdn.net/hf19931101/article/details/79452799  

class Solution {
public:
  
    vector<string> results;
    int minMap[10] = {8,4,2,1,32,16,8,4,2,1};  
    void dfs(int pos, int cnt, int n, int k,bool visited[]) {
        //已标记了k个数，输出结果
        if (cnt == k) {
            int tmpMin = 0;
            int tmpHour =0;
            for (int i = 0; i < 4; i++){
                if (visited[i]){
                    tmpHour+=minMap[i];
                     if(tmpHour> 11){
                         return;
                     }
                };
            }
            for (int i = 4; i < 10; i++){
                if (visited[i]){
                    tmpMin+=minMap[i];
                     if(tmpMin> 59){
                         return;
                     }
                };
            }
            

            if(tmpMin<10){
                results.push_back(to_string(tmpHour)+":0"+to_string(tmpMin));    
            }else{
                results.push_back(to_string(tmpHour)+":"+to_string(tmpMin));    
            }
            return;
        }

        //处理到最后一个数，直接返回
        if (pos == n) return;

        //如果a[pos]没有被选中
        if (!visited[pos]) {
            //选中a[pos]
            visited[pos] = true;
            //处理在子串a[pos+1, n-1]中取出k-1个数的子问题
            dfs(pos + 1, cnt + 1, n, k,visited);
            //回溯
            visited[pos] = false;   
        }
        //处理在子串a[pos+1, n-1]中取出k个数的问题
        dfs(pos + 1, cnt, n, k, visited);
    }

    vector<string> readBinaryWatch(int num) {
        if(num == 0){
            return vector<string>(1,"0:00");
        }
         int i, n, k;
        n=10;
        k=num;
        
       
        bool *visited = new bool[n];
        for (i = 0; i < n; i++)
        {
            
            visited[i] = false;
        }
        dfs(0, 0, n, k, visited);
       
        delete[] visited;
            
        return results;
    }
};