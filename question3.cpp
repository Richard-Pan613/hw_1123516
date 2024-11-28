#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Element {
    int value;    
    int arrayIndex; 
    int elementIndex; 

   
    Element(int v, int aIdx, int eIdx) : value(v), arrayIndex(aIdx), elementIndex(eIdx) {} //initialize Elment Struct
};

    
struct Compare {  // Compare Struct to compare lement values
    bool operator()(Element& e1, Element& e2) {
        return e1.value > e2.value; //true if e1 is greater than e2
    }
};

 
vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) { // function to merge k sorted arrays using a min priority queue
    
     
    priority_queue<Element, vector<Element>, Compare> minHeap; // priority queue to store the elements of the arrays

     
    vector<int> mergedArray; // vector to store the final merged array

    
    for (int i = 0; i < arrays.size(); ++i) { 
        if (!arrays[i].empty()) { 
            minHeap.push(Element(arrays[i][0], i, 0)); //insert the first element of each array into the heap
        }
    }

     
    while (!minHeap.empty()) {  // process the heap until it's empty
        Element current = minHeap.top(); // get the smallest element
        minHeap.pop(); // remove the smallest element from the heap

        mergedArray.push_back(current.value); //put the smallest element to the result array

 
        int nextElementIndex = current.elementIndex + 1; //if there is a next element in the same array, insert it into the heap
        if (nextElementIndex < arrays[current.arrayIndex].size()) { 
            minHeap.push(Element(arrays[current.arrayIndex][nextElementIndex], current.arrayIndex, nextElementIndex)); // insert the next element from the same array
        }
    }

    return mergedArray; // return the merged sorted array
}

int main() {
    vector<vector<int>> arrays = { //using vector to store input
        {2, 5, 8},
        {1, 3, 7},
        {4, 6, 9}
    };

     
    vector<int> mergedArray = mergeKSortedArrays(arrays); // call function to merge arrays 

    cout << "Merged Array: [";
    for (int i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i];
        if (i != mergedArray.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
