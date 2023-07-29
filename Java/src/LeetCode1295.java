public class LeetCode1295 {
    public int findNumbers(int[] nums) {
        int count = 0;
        for(int i = 0; i< nums.length; i++){
            int n = 0;
            int result = nums[i];
            while(result != 0){
                n++;
                result /= 10;
            }
            if(n%2==0)
                count++;
        }
        return count;
    }

    public void result1295(){
        int[] nums = {12, 345, 2, 6, 7896};
        System.out.println(findNumbers(nums));
    }
}
