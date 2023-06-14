#include <string>
#include <iostream>
#include <mutex>
#include <condition_variable>

#include "data_holder.cpp"

using namespace std;

template <typename T>
class producer {
    private:
        data_holder<T>* dh;
        mutex* dh_mu;
        condition_variable* full_data_holder;
        condition_variable* empty_data_holder;
    public:
        producer(data_holder<T>* dh, mutex* dh_mu, condition_variable* full_data_holder, condition_variable* empty_data_holder) {
            this->dh = dh;
            this->dh_mu = dh_mu;
            this->full_data_holder = full_data_holder;
            this->empty_data_holder = empty_data_holder;
        }
        void produce(T item) {
            unique_lock<mutex> lck(*dh_mu);
            if (dh->isFull()) {
                full_data_holder->wait(lck);
            }
            dh->insert(item);
            empty_data_holder->notify_all();
        }
};