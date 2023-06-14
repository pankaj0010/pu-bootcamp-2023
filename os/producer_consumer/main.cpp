
#include <iostream>
#include <thread>

#include "consumer.cpp"
#include "producer.cpp"
#include "queue_holder.cpp"

using namespace std;

void producer_thread_fn(queue_holder<string>* pcQueue, int holder_size) {
    producer<string> prod = producer<string>(pcQueue);
    for (int i = 0; i < holder_size + 5; i++) {
        cout << "Producing hello" << i << endl;
        prod.produce("hello" + i);
    }
}

void consumer_thread_fn(queue_holder<string>* pcQueue, int holder_size) {
    consumer<string> cons = consumer<string>(pcQueue);
    for (int i = 0; i <= holder_size; i++) {
        string* consumed_val = cons.consume();
        if (consumed_val != nullptr) {
            cout << "Consumed " << *consumed_val << " in thread " << this_thread::get_id() << endl;
        }
    }
}

int main() {
    int holder_size = 10;
    queue_holder<string> pcQueue = queue_holder<string>(holder_size);
    thread prod_thread(producer_thread_fn, &pcQueue, holder_size);
    thread cons_thread_1(consumer_thread_fn, &pcQueue, holder_size);
    thread cons_thread_2(consumer_thread_fn, &pcQueue, holder_size);
    prod_thread.join();
    cons_thread_1.join();
    cons_thread_2.join();
    return 0;
}