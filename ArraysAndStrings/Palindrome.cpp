#include "myincludes.h"

bool Palindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}


int main() {
    
    string s;
    cout << "Please enter a line for Palindrome analysis: ";
    getline(cin,s);
    bool val = Palindrome(s);

    if (val == true) {
        cout << "The string entered was a palindrome" << endl;
    } else {
        cout << "The string entered was not a palindrome" << endl;
    }

    return 0;
}



