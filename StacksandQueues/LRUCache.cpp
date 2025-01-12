/*input
*/
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
  public:
    class DoublyLL {
      public:
        int key;
      	int val;
      	DoublyLL * next;
      	DoublyLL * prev;
      	DoublyLL(int key1, int val1) {
        key = key1;
        val = val1;
      }
    };

  DoublyLL * head = new DoublyLL(-1, -1);
  DoublyLL * tail = new DoublyLL(-1, -1);

  int cap;
  unordered_map < int, DoublyLL * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addDoublyLL(DoublyLL * newDoublyLL) {
    DoublyLL * temp = head -> next;
    newDoublyLL -> next = temp;
    newDoublyLL -> prev = head;
    head -> next = newDoublyLL;
    temp -> prev = newDoublyLL;
  }

  void deleteDoublyLL(DoublyLL * delDoublyLL) {
    DoublyLL * delprev = delDoublyLL -> prev;
    DoublyLL * delnext = delDoublyLL -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key1) {
    if (m.find(key1) != m.end()) {
      DoublyLL * resDoublyLL = m[key1];
      int res = resDoublyLL -> val;
      m.erase(key1);
      deleteDoublyLL(resDoublyLL);
      addDoublyLL(resDoublyLL);
      m[key1] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key1, int value) {
    if (m.find(key1) != m.end()) {
      DoublyLL * existingDoublyLL = m[key1];
      m.erase(key1);
      deleteDoublyLL(existingDoublyLL);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deleteDoublyLL(tail -> prev);
    }

    addDoublyLL(new DoublyLL(key1, value));
    m[key1] = head -> next;
  }
};
int main()
{
	return 0;
}
/*Need to have Double linked list and Hash Map
Capacity is the size of LRU cache
To perform get operation in O(1) time we need to have Map data structure which stores two values
1. The key 
2. The address of the doubly linked list DoublyLL to reach the desired key value pair in O(1)
Put operation to be done in O(1) time , so if element exist we need to find that element and 

*/