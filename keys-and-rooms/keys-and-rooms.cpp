class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        dfs(rooms,0,visited);
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                return false;
            }
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms,int src,vector<int>& visited){
        visited[src] = 1;
        for(int i=0; i<rooms[src].size(); i++){
            if(visited[rooms[src][i]] == 0){
                dfs(rooms, rooms[src][i], visited);
            }            
        }
    }    
};