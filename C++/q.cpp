#include <iostream>
#include <vector>

template<typename T>
class MinHeap {
private:
    std::vector<T> heap;

    void heapifyUp(int index) {
        int parentIndex = (index - 1) / 2;
        while (index > 0 && heap[index] < heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int smallestIndex = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[index])
            smallestIndex = leftChildIndex;
        if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallestIndex])
            smallestIndex = rightChildIndex;

        if (smallestIndex != index) {
            std::swap(heap[index], heap[smallestIndex]);
            heapifyDown(smallestIndex);
        }
    }

public:
    MinHeap() {}

    void insert(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T extractMin() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        T min = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return min;
    }

    const T& peekMin() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap.front();
    }

    bool isEmpty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }

    

};

int main() {
    MinHeap<int> minHeap;

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(30);

    std::cout << "Min element: " << minHeap.peekMin() << std::endl;

    minHeap.display();
    std::cout << std::endl;

    return 0;
}
