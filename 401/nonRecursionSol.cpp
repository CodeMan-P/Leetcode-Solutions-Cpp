class Solution {
public:
    
    int minMap[10]{8,4,2,1,32,16,8,4,2,1};
    void convertStr(vector<string>& result,vector<bool>& visited){
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
            result.push_back(to_string(tmpHour)+":0"+to_string(tmpMin));    
        }else{
            result.push_back(to_string(tmpHour)+":"+to_string(tmpMin));    
        }
    }
    vector<string> dfs(int* arr,int n,int k){
        vector<string> result;
        if(k==0){
            result.push_back("0:00");
            return result;
        }
        vector<bool> visited(n,0);
        stack<int> stack;
        stack.push(0);
        int cnt = 0;
        while(!stack.empty()){
            int tmpIndex = stack.top();
            bool popFlag = false;
            if(visited[tmpIndex]){
               popFlag = 1; 
            }else{
                cnt++;
                visited[tmpIndex]=1;
                if(cnt == k){
                    convertStr(result,visited);
                    popFlag = 1;
                }
            }

            if(popFlag){
                cnt--;
                visited[tmpIndex]=0;
                stack.pop();
            }
            if(tmpIndex+1 < n){
                stack.push(tmpIndex+1);
            }
        }
        return result;

    }
    vector<string> readBinaryWatch(int num) {
        return dfs(minMap,10,num);
    }
};