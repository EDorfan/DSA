// Given an integer array arr, count how many elements x there are, such that x + 1 is also in arr. If there are duplicates in arr, count them separately.

public class Solution {
    public int CountElements(int[] arr) {
        int count = 0;
        
        foreach (int num in arr) {
            if (arr.Contains(num + 1)) {
                count++;
            }
        }
        return count;
    }
}

public class Program {
    static void Main(string[] args) {
        Solution solution = new Solution();
        int[] arr = {1,2,3};
        int result = solution.CountElements(arr);
        Console.WriteLine(result);
    }
}