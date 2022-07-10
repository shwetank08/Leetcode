class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int c1 = 0, c2 = 0;
        for(int i=cost.size()-1;i>=0;i--){
            int cur = cost[i] + min(c1,c2);
            c1 = c2;
            c2 = cur;
        }
        return min(c1,c2);
        
    }
};