#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define vi vector<int>

void printarr(const vi& arr){
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void vector_reference_demo() {
    vi vec;                     // Create empty vector
    vec = {5, 3, 1, 4, 2};      // Initializing with list

    vec.push_back(10);          // Add element to end
    vec.pop_back();             // Remove last element

    int front = vec.front();    // First element
    int back = vec.back();      // Last element
    int at2 = vec.at(2);        // Element at index 2 (with bounds check)
    int size = vec.size();      // Current number of elements
    int cap = vec.capacity();   // Capacity of vector
    bool isEmpty = vec.empty(); // Check if empty

    vec.insert(vec.begin() + 1, 99);        // Insert at position
    vec.erase(vec.begin() + 2);             // Erase single element
    vec.erase(vec.begin(), vec.begin() + 2); // Erase a range

    vec.resize(7);             // Resize (new elements default-initialized to 0)
    vec.reserve(20);           // Reserve capacity
    vec.shrink_to_fit();       // Reduce capacity to fit size exactly

    sort(all(vec));            // Sort in ascending
    reverse(all(vec));         // Reverse the vector

    vi copy_vec = vec;         // Copy constructor
    vec.clear();               // Clear all elements

    printarr(copy_vec);        // Print copied vector
	
	int target = 30;

    auto it = find(nums.begin(), nums.end(), target);

    if (it != nums.end()) {
        cout << "Element found at index: " << (it - nums.begin()) << endl;
    } else {
        cout << "Element not found." << endl;
    }
}

int main() {
    vector_reference_demo();
    return 0;
}
