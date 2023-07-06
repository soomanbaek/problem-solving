class Solution {
    int[] makeSumArray(int[] nums){
        int sum = 0;
        int[] sums = new int[nums.length + 1];
        sums[0] = 0; // 모든 값을 더할 경우 처리하기 위해 맨 앞에 0을 넣어줌
        for(int i=0; i<nums.length; ++i){
            sum += nums[i];
            sums[i+1] = sum;
        }

        return sums;
    }

    int findIndexToMeetCriteria(int target, int[] sums, int firstIdx){
        int left = firstIdx;
        int right = sums.length - 1;
        int secondIdx = -1;
        int firstNum = sums[firstIdx];
        while(left <= right){
            int mid = (left + right)/2;
            int secondNum = sums[mid];

            if(secondNum - firstNum >= target){
                secondIdx = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return secondIdx;
    }
    public int minSubArrayLen(int target, int[] nums) {
        int answer = Integer.MAX_VALUE;
        // 누적합
        int[] sums = makeSumArray(nums);
        
        // 이진탐색을 활용하여 조건에 만족하는 subArray 최소 길이 찾기
        for(int firstIdx=0; firstIdx<sums.length; ++firstIdx){
            
            int secondIdx = findIndexToMeetCriteria(target, sums, firstIdx);
            
            if(secondIdx == -1) break;
            int subArraySize =  secondIdx - firstIdx;
            answer = Math.min(answer, subArraySize);
        }
        
        if(answer == Integer.MAX_VALUE){
            return 0;
        }
        
        return answer;
    }
}