#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

#define LIMIT 987654321
using namespace std;

int M, N;

int calcMinDistanceWhenBallHitSide(int sx, int sy, int dx, int dy){
    int distance = LIMIT;
    
    if(!(sx == dx && sy > dy)){
        distance = pow(sy+dy, 2) + pow(sx-dx, 2);      // down side
    }
    if(!(sx == dx && sy < dy)){
        distance = min(distance, (int)(pow(2*N-sy-dy, 2) + pow(sx-dx, 2)));   // up side
    }
    if(!(sy == dy && sx > dx)){
        distance = min(distance, (int)(pow(sx+dx, 2) + pow(sy-dy, 2)));     // left side
    }
    if(!(sy == dy && sx < dx)){
        distance = min(distance, (int)(pow(2*M-sx-dx, 2) + pow(sy-dy, 2)));    // right side
    }
    
    return distance;
}

int calcMinDistanceWhenBallHitVertex(int sx, int sy, int dx, int dy){
    int distance = LIMIT;
    
    // left up vertex
    if(((N-dy)*sx == (N-sy)*dx) && dy < sy){
        distance = min(distance, (int)(pow(2*N-sy-dy, 2) + pow(sx+dx,2)));
    }
    // left down vertex
    if((dy*sx == dx*sy) && dy > sy){
        distance = min(distance, (int)(pow(sy+dy, 2) + pow(sx+dx,2)));
    }
    // right up vertex
    if(((N-dy)*(M-sx) == (M-dx)*(N-sy)) && dy < sy){
        distance = min(distance, (int)(pow(2*N-sy-dy,2) + pow(2*M-sx-dx,2)));
    }
    // right down vertex
    if((dy*(M-sx) == (M-dx)*sy) && dy > sy){
        distance = min(distance, (int)(pow(sy+dy,2) + pow(2*M-sx-dx,2)));
    }
    return distance;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    M = m; N = n;
    
    vector<int> answer;
    
    for(auto& ball: balls){
        // side(변)에 맞았을 경우
        int distance = calcMinDistanceWhenBallHitSide(startX, startY, ball[0], ball[1]);
        // vertex(꼭지점)에 맞았을 경우
        distance = min(distance, calcMinDistanceWhenBallHitVertex(startX, startY, ball[0], ball[1]));
        
        answer.push_back(distance);
    }
    return answer;
}