class Solution {
private:
    vector<bool> visited;

public:
    void dfs(vector<vector<int>> rooms, int room) {
        if (visited[room]) return;
        visited[room] = true;
        for (int x:rooms[room]) {
            dfs(rooms,x);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.assign(rooms.size(),false);

        dfs(rooms,0);

        for (bool v:visited) {
            if (!v) return false;
        }

        return true;
    }
};