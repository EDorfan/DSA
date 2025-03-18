public class Solution {
    public bool CheckIfPangram(string sentence) {
        HashSet<char> characters = new HashSet<char>();
        
        foreach (char c in sentence) {
            characters.Add(c);
            if (characters.Count == 26) {
                return true;
            }
        }
        
        return false;
    }
}

public class Program {
    static void Main(string[] args) {
        Solution solution = new Solution();
        string sentence = "thequickbrownfoxjumpsoverthelazydog";
        bool result = solution.CheckIfPangram(sentence);
        Console.WriteLine(result);
    }
}