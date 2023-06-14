#ifndef QUEUE_HOLDER
#define QUEUE_HOLDER

#include <queue>

#include "data_holder.cpp"

using namespace std;

template <typename T>
class queue_holder : public data_holder<T> {
    queue<T> q;
    int size = 0;

    public:
        queue_holder(int size) {
            this->size = size;
        }
        
        bool isEmpty() {
            return q.size() == 0;
        }

        bool isFull() {
            return q.size() == size;
        }

        void insert(T item) {
            q.push(item);
        }

        T* getNextItem() {
            T* item = new T(q.front());
            return item;
        }

        void deleteNextItem() {
            q.pop();
        }
};
#endif