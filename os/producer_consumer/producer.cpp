#include <string>
#include <iostream>
#include <mutex>

#include "data_holder.cpp"

using namespace std;

template <typename T>
class producer {
    private:
        data_holder<T>* dh;
        mutex* dh_mu;
    public:
        producer(data_holder<T>* dh, mutex* dh_mu) {
            this->dh = dh;
            this->dh_mu = dh_mu;
        }
        void produce(T item) {
            dh_mu->lock();
            if (dh->isFull()) {
                cout << "Data holder is full" << endl;
                dh_mu->unlock();
                return;
            }
            dh->insert(item);
            dh_mu->unlock();
        }
};