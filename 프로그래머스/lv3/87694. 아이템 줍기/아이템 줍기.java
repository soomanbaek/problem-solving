class Solution {
    final int ROUTE = 1;
    final int NO_ROUTE = -1;
    int[] dy = {-1, 0, 0, 1};
    int[] dx = {0, -1, 1, 0};
    boolean[][] visited = new boolean[101][101];
    int[][] map = new int[101][101];
    
    void showMap(){
        for(int r = 1; r  <= 100; ++r){
            for(int c = 1; c<= 100; ++c){
                System.out.print(map[r][c] + " ");
            }
            System.out.println();
        }
    }
    
    void updateMap(int[][] rectangles){
        for(int[] rectangle: rectangles){
            int cStart = rectangle[0]*2;
            int rStart = rectangle[1]*2;
            int cEnd = rectangle[2]*2;
            int rEnd = rectangle[3]*2;
            
            for(int r = rStart; r <= rEnd; ++r){
                for(int c = cStart; c <= cEnd; ++c){
                    if(map[r][c] == NO_ROUTE) continue;
                    if(r == rStart || r == rEnd || c == cStart || c == cEnd){
                        map[r][c] = ROUTE;
                    }else{
                        map[r][c] = NO_ROUTE;
                    }
                }
            }
        }
    }
    
    int routing(int y, int x, int itemY, int itemX, int cnt){        
        if(y == itemY && x == itemX)    return cnt;
        
        visited[y][x] = true;
        int routeCnt = 0;
        for(int d=0; d<4; ++d){
            int ny = y + dy[d];
            int nx = x + dx[d];
            
            if(ny <= 0 || ny > 100 || nx <= 0 || nx > 100)    continue;
            if(map[ny][nx] != ROUTE) continue;
            if(visited[ny][nx] == true) continue;
            
            routeCnt = routing(ny, nx, itemY, itemX, cnt+1);
        }
        return routeCnt;
        
    }
    
    int getRouteCnt(int characterY, int characterX, int itemY, int itemX){
        int routeCnt = Integer.MAX_VALUE;
        visited[characterY][characterX] = true;
        
        for(int d=0; d<4; ++d){
            int ny = characterY + dy[d];
            int nx = characterX + dx[d];
            if(ny <= 0 || ny > 100 || nx <= 0 || nx > 100)    continue;
            if(map[ny][nx] != ROUTE) continue;
            if(visited[ny][nx] == true) continue;
            routeCnt = Math.min(routeCnt, routing(ny, nx, itemY, itemX, 1));
        }
        
        return routeCnt/2;
    }
    
    public int solution(int[][] rectangles, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;
        updateMap(rectangles);
        
        answer = getRouteCnt(characterY*2, characterX*2, itemY*2, itemX*2);
        
        return answer;
    }
}