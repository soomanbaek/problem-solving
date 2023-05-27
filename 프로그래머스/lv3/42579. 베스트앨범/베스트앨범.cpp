#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Music{
public:
    int num;
    int play_time;
    
    Music(int num, int play_time){
        this->num = num;
        this->play_time = play_time;
    }
};

struct compareMusic{
    bool operator()(const Music &l, const Music &r) const{
        if(l.play_time == r.play_time){
            return l.num > r.num;
        }
        return l.play_time < r.play_time;
    }
};

class MusicPlayer{
public:
    int genre_play_time;
    priority_queue<Music, vector<Music>, compareMusic> musics;
    
    MusicPlayer(){
        this->genre_play_time = 0;
    }
    
    void insertMusic(int num, int play_time){
        genre_play_time += play_time;
        musics.push({num, play_time});
    }
    
    vector<int> popMusics(){
        vector<int> ret;
        
        ret.push_back(musics.top().num);    musics.pop();
        
        if(!musics.empty())
            ret.push_back(musics.top().num);
        
        return ret;
    }
};

struct compareMusicPlayer{
    bool operator()(const MusicPlayer &l, const MusicPlayer &r) const {
        return l.genre_play_time > r.genre_play_time;
    }
};

unordered_map<string, int> music_player_index;

vector<int> solution(vector<string> genres, vector<int> plays) {
    int N = genres.size();
    
    vector<int> answer;
    
    int index = 0;
    for(int i=0; i<N; ++i){
        string genre = genres[i];
        if(music_player_index.find(genre) == music_player_index.end()){
    music_player_index[genre] = index++;
        }
    }
    vector<MusicPlayer> music_players(index);
    for(int i=0; i<N; ++i){
        string genre = genres[i];
        int index = music_player_index[genre];
        int play_time = plays[i];
        
        music_players[index].insertMusic(i, play_time);
    }
    
    sort(music_players.begin(), music_players.end(), compareMusicPlayer());
    
    for(int i=0; i<music_players.size(); ++i){
        vector<int> music_list = music_players[i].popMusics();
        
        answer.insert(answer.end(), music_list.begin(), music_list.end());
    }
    
    return answer;
}