#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Min-Heap implementation class.
class minHeapOperation {
private:
    vector<int> heapElements;
    int swapOperationsDuringInsertion;
    int swapOperationsDuringDeletion;

    // Helper functions to calculate heap indices.
    int findParentIndex(int currentIndex){
        int parentIndex = (currentIndex - 1) / 2;       
        return parentIndex;
    }

    int findLeftChildIndex(int currentIndex){
        int leftChildIndex = (2 * currentIndex) + 1;
        return leftChildIndex;
    }

    int findRightChildIndex(int currentIndex){
        int rightChildIndex = (2 * currentIndex) + 2;
        return rightChildIndex;
    }

public:
    // Constructor of MinHeapOperation class. 
    minHeapOperation(){
        // Initialise the min-heap with counters for tracking swap operations.
        swapOperationsDuringInsertion = 0;
        swapOperationsDuringDeletion = 0;
    }

    void heapInsertion(int element){
        heapElements.push_back(element);                                            // Insert a new element to the heap 
        int elementToHeapifyUp = heapElements.size() - 1;                           // Start from the very last element 
        heapifyUpHeapElements(elementToHeapifyUp);                                  // Call heapifyUpHeapElements function to maintain the min-heap property
    }

    int heapDeletion(){
        if (heapElements.size() == 0){
            throw out_of_range("Heap does not have any element to delete.");
        } 

        // When there is element to delete, get the root element, replace with the last element, and remove the last element.
        int rootElement = heapElements[0];
        heapElements[0] = heapElements[heapElements.size() - 1];
        heapElements.pop_back();

        // Heapify down passing the root element index to maintain min-heap property after a deletion. 
        int elementToHeapifyDown = 0;
        heapifyDownHeapElements(elementToHeapifyDown);
        return rootElement;
    }

    // Function to heapify up the elements to maintain the min-heap property after an insertion.
    int heapifyUpHeapElements(int elementToHeapifyUp){
        while (elementToHeapifyUp > 0){                                             // Continue to heapify up only when the element is bigger than 0
            int parentIndex = findParentIndex(elementToHeapifyUp);                  // Find the parent index of the element
            if (heapElements[elementToHeapifyUp] < heapElements[parentIndex]){      // if element is smaller than the parent element, swap is needed
                swap(heapElements[elementToHeapifyUp], heapElements[parentIndex]);  
                swapOperationsDuringInsertion++;                                    // Increase the swap operation count
                elementToHeapifyUp = parentIndex;                                   // Keep heapifying up until the parent index is smaller than the children
            } else {             
                break;                                                              // Break loop since min-heap property is maintained.             
            }
        }
        return swapOperationsDuringInsertion;                                       // Return the number of swap operations during the insertion 
    }

    // Function to heapify down the elements to maintain the min-heap property after a deletion.
    int heapifyDownHeapElements(int elementToHeapifyDown){
        int theSmallestIndex = elementToHeapifyDown;
        int leftChildIndex = findLeftChildIndex(elementToHeapifyDown);
        int rightChildIndex = findRightChildIndex(elementToHeapifyDown);
        
        // Ensure left child is within the heap size and smaller than root, making it the smallest element.
        if (heapElements[leftChildIndex] < heapElements[theSmallestIndex] && leftChildIndex < (int)heapElements.size()){
            theSmallestIndex = leftChildIndex;
        } 

        // Continue find the smallest element index to the right child
        if (heapElements[rightChildIndex] < heapElements[theSmallestIndex] && rightChildIndex < (int)heapElements.size()){
            theSmallestIndex = rightChildIndex;
        }

        // Check if the smallest index is not the root element index (otherwise, no need to swap)
        if (theSmallestIndex != elementToHeapifyDown){
            swap(heapElements[elementToHeapifyDown], heapElements[theSmallestIndex]);   // Swap the smallest element with the root element
            swapOperationsDuringDeletion++;                                             // Increase the swap operation count during the deletion
            heapifyDownHeapElements(theSmallestIndex);                                  // Continue to heapify down until the smallest element is at the root of the heap
        }   
        return swapOperationsDuringDeletion;                                            // Return the number of swap operations during the deletion
    }

    // Getters to get the swap operations during insertion and deletion (the output of the program)
    int getSwapOperationsDuringInsertion(){
        return swapOperationsDuringInsertion;
    }

    int getSwapOperationsDuringDeletion(){
        return swapOperationsDuringDeletion;
    }
};


void sortVectorToAscendingOrder(vector<int>& vectorToSort){
    sort(vectorToSort.begin(), vectorToSort.end());
}

void sortVectorToDescendingOrder(vector<int>& vectorToSort){
    sort(vectorToSort.begin(), vectorToSort.end(), greater<int>());                    
}

// Heap sort operations (pass by reference) in order to modify the vector directly.
void heapSortOperation(vector<int>& vectorToSort){

    // Create an instance of minHeapOperation class to perform heap operations, perform insertions and deletions.
    minHeapOperation heapOperation;
    for (int i = 0; i < (int)vectorToSort.size(); i++){
        heapOperation.heapInsertion(vectorToSort[i]);
    }

    for (int i = 0; i < (int)vectorToSort.size(); i++){
        vectorToSort[i] = heapOperation.heapDeletion();
    }

    // Finally, output the number of swap operations during insertions and deletions (separated by a plus sign)
    cout << heapOperation.getSwapOperationsDuringInsertion() << " + " << heapOperation.getSwapOperationsDuringDeletion() << endl;
}


int main(){
    
    // Test the heap sorting algorithm with vectors in original, ascending, and descending numbers.
    vector<int> originalNumbersVector;
    vector<int> ascendingNumbersVector;
    vector<int> descendingNumbersVector;

    // Start by getting the total number of numbers that will be coming in.
    int totalNumbers;
    cin >> totalNumbers;

    for (int i = 0; i < totalNumbers; i++){

        int number;
        cin >> number;

        // Add the number to each vector.
        originalNumbersVector.push_back(number);
        ascendingNumbersVector.push_back(number);
        descendingNumbersVector.push_back(number);
    }

    sortVectorToAscendingOrder(ascendingNumbersVector);
    sortVectorToDescendingOrder(descendingNumbersVector);

    // Output each vector's heap sort operations (their swap operations during insertions and deletions)
    cout << "original: ";
    heapSortOperation(originalNumbersVector);

    cout << "ascending: ";
    heapSortOperation(ascendingNumbersVector);

    cout << "descending: ";
    heapSortOperation(descendingNumbersVector);

    return 0;
}