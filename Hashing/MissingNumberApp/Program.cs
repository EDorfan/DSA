public class Solution {
    public int MissingNumber(int[] nums) {
        int n = nums.Length;
        int Total = n*(n+1)/2;
        
        foreach (int num in nums) {
            Total = Total - num;
        }
        return Total;
    }
}

public class Program {
    static void Main(string[] args) {
        Solution solution = new Solution();
        int[] nums = {9,6,4,2,3,5,7,0,1};
        int result = solution.MissingNumber(nums);
        Console.WriteLine(result);
    }
}