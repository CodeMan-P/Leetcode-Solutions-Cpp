class Solution {
public:
    int s =0,mx= 0;
   
    // void dfs(int u,int f,int dis){
    //     if(dis > mx){
    //         mx = dis;
    //         s = u;
    //     }

    //     for(int v : G[u]){
    //         if(v==f) continue;
    //         dfs(v,u,dis+1);
    //     }
    // };
    void bfs(int start,vector<vector<int>>& G){
        queue<int> q;
        q.push(start);
        vector<int> dis(G.size(),-1);
        dis[start] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            mx = dis[u] ;
            s = u;
              
            for(auto& iter : G[u]){
                if(dis[iter] == -1){
                    dis[iter] = dis[u] + 1;
                    q.push(iter);
                }
            }
        }
    }
    int treeDiameter(vector<vector<int>>& edges) {
         vector<vector<int>> G=vector<vector<int>>(edges.size()+1,vector<int>());
        for(auto iter : edges){
            G[iter[0]].push_back(iter[1]);
            G[iter[1]].push_back(iter[0]);
        }
        bfs(0,G);
        bfs(s,G);
        return mx;
    }
};