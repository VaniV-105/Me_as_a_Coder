#include <iostream>
 	#include <vector>
using namespace std;
class HeapTree
{
public:
	vector<int> heap;
	void insert(int val)
	{
    	heap.push_back(val);
    	int n = heap.size();
    	for (int i = n / 2 - 1; i >= 0; i--)
        	heapify(n, i);
	}
	void heapify(int n, int i)
	{
    	int smallest = i;
    	int l = 2 * i + 1;
    	int r = 2 * i + 2;
    	if (l < n && heap[l] < heap[smallest])
        	smallest = l;
    	if (r < n && heap[r] < heap[smallest])
        	smallest = r;
    	if (smallest != i) {
        	int x = heap[i];
        	heap[i] = heap[smallest];
        	heap[smallest] = x;
        	heapify(n, smallest);
    	}
	}
	int extractMin()
	{
    	if (heap.size() == 0) {
        	cout << "Empty List ";
        	return int();
    	}
    	int minVal = heap[0];
    	heap[0] = heap.back();
    	heap.pop_back();
    	heapify(heap.size(), 0);
    	return minVal;
	}
};
int main()
{
	HeapTree a;
	int n;
	while(true)
	{
 	cout<<"1.Insert\n2.ExtractMin\n3.Exit\nEnter an Option : ";
 	cin>>n;
 	switch(n)
 	{
	 case 1:
   	 cout<<"Enter a Number : ";
   	 cin>>n;
   	 a.insert(n);
   	 break;
    case 2:
            	cout << "Extracting minimum from heap: ";
        	cout << a.extractMin() << endl;
   	 break;
    case 3:
   	 return 0;   	 
   	 break;
    default:
   	 cout<<"Enter Correct Option ";
 	}
	}
	return 0;
}