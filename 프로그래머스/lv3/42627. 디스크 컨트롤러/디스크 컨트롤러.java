import java.util.*;
import java.util.stream.*;

class Job implements Comparable<Job>{
    int requestTime;
    int duration;
    Job(int requestTime, int duration){
        this.requestTime = requestTime;
        this.duration = duration;
    }
    @Override
    public int compareTo(Job job){
        return this.duration - job.duration;
    }
}

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        // jobs 정렬
        Arrays.sort(jobs, (a, b)-> a[0] - b[0]);
        
        PriorityQueue<Job> pq = new PriorityQueue<>();
        
        int idx = 0;
        for(int t=0; t <= 1000000; ++t){
            while(idx < jobs.length && jobs[idx][0] <= t){
                pq.add(new Job(jobs[idx][0], jobs[idx][1]));
                idx += 1;
            }
            if(!pq.isEmpty()){
                Job cur = pq.peek(); pq.remove();
                t += cur.duration;
                answer += (t - cur.requestTime);
                t -= 1;
            }
        }
        answer /= jobs.length;
        
        return answer;
    }
}