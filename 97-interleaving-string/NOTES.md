class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()){return false;}
        
        vector<vector<bool>>dp(s1.length()+1,vector<bool>(s2.length()+1));
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(i==0 && j==0){
                    dp[i][j]=true;
                }else if(i==0){
                    dp[i][j] = s3[i+j-1] == s2[j-1]?dp[i][j-1]:false;  
                }else if(j==0){
                    dp[i][j] = s3[i+j-1] == s1[i-1]?dp[i-1][j]:false;
                }else{
                    if(s1[i-1]==s3[i+j-1]){
                        dp[i][j] = dp[i-1][j];
                    }if(!dp[i][j] && s2[j-1]==s3[i+j-1]){
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};
