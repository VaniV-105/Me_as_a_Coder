#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class Heap {
private:
    vector<int> heapArray;

    // Helper function to heapify up (used after insertion)
    void heapifyUp(int index) {
        while (index > 0 && heapArray[parent(index)] > heapArray[index]) {
            swap(heapArray[parent(index)], heapArray[index]);
            index = parent(index);
        }
    }

    // Helper function to heapify down (used after deletion)
    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;

        if (left < heapArray.size() && heapArray[left] < heapArray[index])
            smallest = left;
        if (right < heapArray.size() && heapArray[right] < heapArray[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heapArray[index], heapArray[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Constructor
    Heap() {}

    // Get parent index
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Get left child index
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // Get right child index
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // Insert element into the heap
    void insert(int value) {
        heapArray.push_back(value);
        heapifyUp(heapArray.size() - 1);
    }

    // Delete element from the heap
    void remove(int value) {
        int index = -1;
        for (int i = 0; i < heapArray.size(); i++) {
            if (heapArray[i] == value) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Element not found in the heap." << endl;
            return;
        }

        heapArray[index] = heapArray.back();
        heapArray.pop_back();
        heapifyDown(index);
    }

    // Find minimum element in the heap
    int findMin() {
        if (heapArray.empty()) {
            cout << "Heap is empty." << endl;
            return INT_MAX;
        }
        return heapArray[0];
    }

    // Print heap elements
    void printHeap() {
        if (heapArray.empty()) {
            cout << "Heap is empty." << endl;
            return;
        }
        cout << "Heap elements: ";
        for (int num : heapArray) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heap;
    int choice, value;

    while (true) {
        cout << "----- Heap Operations Menu -----" << endl;
        cout << "1. Insert element into the heap" << endl;
        cout << "2. Delete element from the heap" << endl;
        cout << "3. Find minimum element in the heap" << endl;
        cout << "4. Print all elements in the heap" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                heap.insert(value);
                cout << "Element inserted into the heap." << endl;
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                heap.remove(value);
                break;
            case 3:
                cout << "Minimum element in the heap: " << heap.findMin() << endl;
                break;
            case 4:
                heap.printHeap();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
