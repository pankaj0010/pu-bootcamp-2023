
#include <iostream>

#include "consumer.cpp"
#include "producer.cpp"
#include "queue_holder.cpp"

using namespace std;

int main() {
    int holder_size = 1;
    queue_holder<string> pcQueue = queue_holder<string>(holder_size);
    producer<string> prod = producer<string>(&pcQueue);
    consumer<string> cons = consumer<string>(&pcQueue);
    
    prod.produce("hello");
    prod.produce("hi");

    for (int i = 0; i <= holder_size; i++) {
        string* consumed_val = cons.consume();
        if (consumed_val != nullptr) {
            cout << *consumed_val << endl;
        }
    }
    return 0;
}