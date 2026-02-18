class Solution {
public:
    void dfs(int i, vector<vector<int>>& stones, unordered_map<int, vector<int>>&row, unordered_map<int,     vector<int>>&col, vector<bool>&vis) {

        vis[i]=true;

        int r=stones[i][0];
        int c=stones[i][1];

        for(int ngh:row[r]){
            if(!vis[ngh]){
                dfs(ngh,stones,row,col,vis);
            }
        }
        for(int ngh:col[c]){
            if(!vis[ngh]){
                dfs(ngh,stones,row,col,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        unordered_map<int, vector<int>>row;
        unordered_map<int, vector<int>>col;

        for(int i=0;i<n;i++){
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        
        vector<bool>vis(n,false);
        int count=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,stones,row,col,vis);
                count++;
            }

        }
        return n-count;
        
    }
};
