
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "consumer.cpp"
#include "producer.cpp"
#include "queue_holder.cpp"

using namespace std;

void producer_thread_fn(
    queue_holder<int>* pcQueue, mutex* dh_mu,
    condition_variable* full_data_holder, condition_variable* empty_data_holder, int holder_size) {
    producer<int> prod = producer<int>(pcQueue, dh_mu, full_data_holder, empty_data_holder);
    for (int i = 0; i < holder_size + 5; i++) {
        cout << "Producing " << i << endl;
        prod.produce(i);
    }
}

void consumer_thread_fn(
    queue_holder<int>* pcQueue, mutex* dh_mu,
    condition_variable* full_data_holder, condition_variable* empty_data_holder, int holder_size) {
    consumer<int> cons = consumer<int>(pcQueue, dh_mu, full_data_holder, empty_data_holder);
    for (int i = 0; i <= holder_size; i++) {
        int* consumed_val = cons.consume();
        if (consumed_val != nullptr) {
            cout << "Consumed " << *consumed_val << " in thread " << this_thread::get_id() << endl;
        }
    }
}

int main() {
    int holder_size = 10;
    queue_holder<int> pcQueue = queue_holder<int>(holder_size);
    mutex dh_mu;
    condition_variable full_data_holder;
    condition_variable empty_data_holder;
    thread prod_thread(producer_thread_fn, &pcQueue, &dh_mu, &full_data_holder, &empty_data_holder, holder_size);
    thread cons_thread_1(consumer_thread_fn, &pcQueue, &dh_mu, &full_data_holder, &empty_data_holder, holder_size);
    thread cons_thread_2(consumer_thread_fn, &pcQueue, &dh_mu, &full_data_holder, &empty_data_holder, holder_size);
    prod_thread.join();
    cons_thread_1.join();
    cons_thread_2.join();
    return 0;
}