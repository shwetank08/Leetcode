class Solution {
public:
    
    bool dfs(vector<int>&matchsticks, vector<bool>&visited,int target,int cursum, int i,int k){
        if(k==1){
            return true;
        }
        
        if(cursum==target){
            return dfs(matchsticks,visited,target,0,0,k-1);
        }
        for(int j=i;j<matchsticks.size();j++){
            if(visited[j] || cursum+matchsticks[j]>target){
                continue;
            }
            visited[j] = true;
            if(dfs(matchsticks,visited,target,cursum+matchsticks[j],j+1,k)){return true;}
            visited[j] = false;
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        
        int sum = 0;
        for(auto i:matchsticks){
            sum+=i;
        }
        if(matchsticks.size()<4 || sum%4!=0){
            return false;
        }
        int targetsum = sum/4;
        vector<bool>visited(matchsticks.size(),false);
        return dfs(matchsticks,visited,targetsum,0,0,4);
        
        
    }
};