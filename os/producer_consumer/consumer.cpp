#include <string>
#include <iostream>
#include <mutex>

#include "data_holder.cpp"

using namespace std;

template <typename T>
class consumer {
    private:
        data_holder<T>* dh;
        mutex* dh_mu;
    public:
        consumer(data_holder<T>* dh, mutex* dh_mu) {
            this->dh = dh;
            this->dh_mu = dh_mu;
        }
        T* consume() {
            dh_mu->lock();
            if (dh->isEmpty()) {
                cout << "Data holder is empty" << endl;
                dh_mu->unlock();
                return nullptr;
            }
            T* item = dh->getNextItem();
            dh->deleteNextItem();
            dh_mu->unlock();
            return item;
        }
};