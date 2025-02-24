#include <iostream>
using namespace std;

// Recursively increments a number and prints up until 10
void Add_Recursion(int i) {
    // base case to break out of Recursion loop so it doesn't run indefinitely
    if(i > 10) {
        return;
    }

    cout << i << endl;
    Add_Recursion(i+1);

    // this line only runs after the base case returns through all the functions. Therefore the order of the prints is as follows
    // 1,2,3, End of call where i = 3, End of call where i = 2, End of call where i = 1
    // Every function call exists until it returns, the old one waits until the new one returns, the order is remembered
    cout << "End of call where i = " << i << endl;
    return;
}

// function returns the nth fibonacci number in the sequence
// inefficient because it has O(2^n) - each call branches into two recursive calls

// Fibonacci_Recursion(5)
// = Fibonacci_Recursion(4) + Fibonacci_Recursion(3)
// = (Fibonacci_Recursion(3) + Fibonacci_Recursion(2)) + (Fibonacci_Recursion(2) + Fibonacci_Recursion(1))
// = ((Fibonacci_Recursion(2) + Fibonacci_Recursion(1)) + Fibonacci_Recursion(2)) + (Fibonacci_Recursion(2) + 1)
// = (((Fibonacci_Recursion(1) + Fibonacci_Recursion(0)) + 1) + (1 + 0)) + ((1 + 0) + 1)
// = (((1 + 0) + 1) + (1 + 0)) + ((1 + 0) + 1)
// = (1 + 1 + 1 + 1) + (1 + 1)
// = 5

int Fibonacci_Recursion(int n) {
    // base case breaks out of recursive function when = 0 or 1
    if (n <= 1) {
        return n;
    }

    int oneBack = Fibonacci_Recursion(n-1);
    int twoBack = Fibonacci_Recursion(n-2);
    return oneBack + twoBack;
    
}

int main() {
    // Add_Recursion(1);
    int val = Fibonacci_Recursion(10);
    cout << val << endl;
}