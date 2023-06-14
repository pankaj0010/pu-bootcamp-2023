#include <string>
#include <iostream>

#include "data_holder.cpp"

using namespace std;

template <typename T>
class consumer {
    private:
        data_holder<T>* dh;
    public:
        consumer(data_holder<T>* dh) {
            this->dh = dh;
        }
        T* consume() {
            if (dh->isEmpty()) {
                cout << "Data holder is empty";
                return nullptr;
            }
            T* item = dh->getNextItem();
            dh->deleteNextItem();
            return item;
        }
};