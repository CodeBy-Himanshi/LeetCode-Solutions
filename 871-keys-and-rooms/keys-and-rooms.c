void dfs(int** rooms, int roomsSize, int* roomsColSize, int room, bool* visited){
    visited[room]=true;
    for(int i=0;i<roomsColSize[room];i++){
        int nextroom=rooms[room][i];
        if(!visited[nextroom])
            dfs(rooms, roomsSize, roomsColSize, nextroom, visited);
    }
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[1000]={false};
    dfs(rooms, roomsSize, roomsColSize, 0, visited);
    for(int i=0;i<roomsSize;i++)
        if(!visited[i])
            return false;
    return true;
}