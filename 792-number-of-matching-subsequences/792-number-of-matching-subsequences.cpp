class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>>m;
        int i=0;
        for(auto c:s){
            m[c].push_back(i++);
        }
        
        int cnt = 0;
        for(int i=0;i<words.size();i++){
            string cur = words[i];
            int latest = -1;
            for(int j=0;j<cur.size();j++){
                auto it = upper_bound(m[cur[j]].begin(),m[cur[j]].end(),latest);
                if(it == m[cur[j]].end()){
                    break;
                }
                latest = *it;
                if(j==cur.size()-1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};