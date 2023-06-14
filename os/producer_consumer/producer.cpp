#include <string>
#include <iostream>

#include "data_holder.cpp"

using namespace std;

template <typename T>
class producer {
    private:
        data_holder<T>* dh;
    public:
        producer(data_holder<T>* dh) {
            this->dh = dh;
        }
        void produce(T item) {
            if (dh->isFull()) {
                cout << "Data holder is full" << endl;
                return;
            }
            dh->insert(item);
        }
};