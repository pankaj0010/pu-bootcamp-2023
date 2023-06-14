
#include <iostream>

#include "consumer.cpp"
#include "producer.cpp"
#include "queue_holder.cpp"

using namespace std;

int main() {
    queue_holder<string> pcQueue = queue_holder<string>(10);
    producer<string> prod = producer<string>(&pcQueue);
    consumer<string> cons = consumer<string>(&pcQueue);
    
    prod.produce("hello");
    cout << cons.consume() << endl;
    return 0;
}