#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

void showlist(list<int> g) {
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main() {
    list<int> list;
    cout << "List Operations:" << endl;
    cout << "1. Push an element in the front." << endl;
    cout << "2. Push an element in the back." << endl;
    cout << "3. Pop an element in the front." << endl;
    cout << "4. Pop an element at the back." << endl;
    cout << "5. Find the frontmost element." << endl;
    cout << "6. Find the last element." << endl;
    cout << "7. Find size of list." << endl;
    cout << "8. Insert an element." << endl;
    cout << "9. Search for an element." << endl;
	cout << "10. Display the list." << endl;
    cout << "11. Exit." << endl;

    int flag = 1;

    while (flag) {
        cout << "Enter your choice: ";
        int choice, n, pos;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to be pushed: ";
                cin >> n;
                list.push_front(n);
                break;
            case 2:
                cout << "Enter element to be pushed: ";
                cin >> n;
                list.push_back(n);
                break;
            case 3:
                list.pop_front();
                break;
            case 4:
                list.pop_back();
                break;
            case 5:
                if (!list.empty())
                    cout << list.front() << endl;
                else
                    cout << "List is empty." << endl;
                break;
            case 6:
                if (!list.empty())
                    cout << list.back() << endl;
                else
                    cout << "List is empty." << endl;
                break;
            case 7:
                cout << list.size() << endl;
                break;
            case 8:
                cout << "Enter the position to insert the element: ";
                cin >> pos;
                cout << "Enter element to be inserted: ";
                cin >> n;
                if (pos >= 1 && pos <= list.size() + 1) {
                    auto it = list.begin();
                    advance(it, pos - 1);
                    list.insert(it, n);
                } else {
                    cout << "Invalid position!" << endl;
                }
                break;
            case 9:
                cout << "Enter element to search: ";
                cin >> n;
                if (find(list.begin(), list.end(), n) != list.end())
                    cout << "Element " << n << " is found in the list." << endl;
                else
                    cout << "Element " << n << " is not found in the list." << endl;
                break;
			case 10:
				showlist(list);
				break;
            default:
                flag = 0;
                break;
        }
    }

    return 0;
}
