class Event implements Comparable<Event>{
    int startDay;
    int endDay;
    Event(int[] event){
        this.startDay = event[0];
        this.endDay = event[1];
    }
    @Override
    public int compareTo(Event event){
        return this.startDay - event.startDay;
    }
}

class Solution {
    public int maxEvents(int[][] events) {
        PriorityQueue<Event> remainedTask = new PriorityQueue<>();

        Arrays.stream(events).forEach(event->{remainedTask.add(new Event(event));});
        int maxDay = Arrays.stream(events).mapToInt(event -> event[1]).max().orElse(Integer.MIN_VALUE);
        
        int attendedDay = 0;
        PriorityQueue<Integer> processTask = new PriorityQueue<>();
        for(int day=1; day<=maxDay; ++day){
            // 해당 날짜에 시작하는 task 넣어주기
            while(!remainedTask.isEmpty()){
                Event event = remainedTask.element();
                if(event.startDay > day)    break;

                processTask.add(event.endDay);
                remainedTask.remove();
            }
            // 진행중인 task중 하나 수행
            while(!processTask.isEmpty()){
                int endDay = processTask.element();
                processTask.remove();
                if(endDay < day)    continue;

                attendedDay += 1;
                break;
            }
        }
        return attendedDay;
    }
}