#include "../myincludes.h"

int main() {
    unordered_map<int, int> myHashMap;
    // myHashMap has integers for both keys and values
    
    myHashMap[4] = 83;
    cout << myHashMap[4] << endl; // Prints 83
    
    // These two lines check if a key is in the map
    cout << (myHashMap.find(4) != myHashMap.end()) << endl; // Prints true (1)
    cout << (myHashMap.find(854) != myHashMap.end()) << endl; // Prints false (0)
    
    myHashMap[8] = 327;
    myHashMap[45] = 82523;
    
    for (auto [key, val]: myHashMap) {
        cout << key << ": " << val << endl;
    }
}