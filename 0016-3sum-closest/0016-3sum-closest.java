class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int answer = 0;
        int minDifference = 100000;
        for(int i=0; i<nums.length-2; ++i){
            if(i > 0 && nums[i] == nums[i-1])   continue;
            for(int j=i+1, k=nums.length-1; j<k;){
                int sum = nums[i] + nums[j] + nums[k];
                int difference = target - sum;

                if(difference == 0){
                    return sum;
                }else if(difference > 0){
                    if(difference < minDifference){
                        minDifference = difference;
                        answer = sum;
                    }
                    j += 1;
                }else{
                    if(difference*(-1) < minDifference){
                        minDifference = difference*(-1);
                        answer = sum;
                    }
                    k -= 1;
                }
            }
        }
        return answer;
    }
}