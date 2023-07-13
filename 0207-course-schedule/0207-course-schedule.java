class Solution {
    public boolean canFinish(int courseNum, int[][] prerequisites) {
        List<Integer>[] nextCourses = new List[courseNum];
        for(int i=0; i<courseNum; ++i){
            nextCourses[i] = new ArrayList<Integer>();
        }
    
        int[] prerequisiteNum = new int[courseNum];

        Arrays.stream(prerequisites).forEach((int[] prerequisite) ->{
            int nextCourse = prerequisite[0];
            int preCourse = prerequisite[1];
            
            nextCourses[preCourse].add(nextCourse);
            prerequisiteNum[nextCourse] += 1;
        });

        Queue<Integer> queue = new LinkedList<Integer>();
        for(int course=0; course<courseNum; ++course){
            if(prerequisiteNum[course] == 0){
                queue.add(course);
            }
        }

        int takenCourseNum = 0;
        while(!queue.isEmpty()){
            int course = queue.element(); queue.remove();
            takenCourseNum += 1;
            for(int nextCourse: nextCourses[course]){
                prerequisiteNum[nextCourse] -= 1;
                if(prerequisiteNum[nextCourse] == 0){
                    queue.add(nextCourse);
                }
            }
        }

        return (takenCourseNum == courseNum);
    }
}