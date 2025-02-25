#include "myincludes.h"

bool checkTargetInt(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else {
            return true;
        }
    }
    return false;
}


int main() {
    
    vector<int> arr = {};
    int input;
    int target;
    cout << "Please continue entering values in ascending order (type -1 to break, select integers only): ";
    while (cin >> input) {
        if (input == -1) {
            break;
        } else if ((!arr.empty()) && (input < arr.back())) {
            cout << "Enter a different value (values must be in ascending order): " << endl;
        } else {
            arr.push_back(input);
        }
    }

    cout << "Please enter the target value (integers only): ";
    cin >> target;
    cout << endl;

    bool check = checkTargetInt(arr, target);
    
    if (check == true) {
        cout << "Two values in the array sum to equal the target value" << endl;
    } else {
        cout << "No values sum to equal the target value" << endl;
    }

    return 0;
}