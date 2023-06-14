#include <string>
#include <iostream>
#include <mutex>
#include <condition_variable>

#include "data_holder.cpp"

using namespace std;

template <typename T>
class consumer {
    private:
        data_holder<T>* dh;
        mutex* dh_mu;
        condition_variable* full_data_holder;
        condition_variable* empty_data_holder;
    public:
        consumer(data_holder<T>* dh, mutex* dh_mu, condition_variable* full_data_holder, condition_variable* empty_data_holder) {
            this->dh = dh;
            this->dh_mu = dh_mu;
            this->full_data_holder = full_data_holder;
            this->empty_data_holder = empty_data_holder;
        }
        T* consume() {
            unique_lock<mutex> lck(*dh_mu);
            if (dh->isEmpty()) {
                empty_data_holder->wait(lck);
            }
            T* item = dh->getNextItem();
            dh->deleteNextItem();
            full_data_holder->notify_all();
            return item;
        }
};