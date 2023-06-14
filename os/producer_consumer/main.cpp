
#include <iostream>
#include <queue>

#include "consumer.cpp"
#include "producer.cpp"

using namespace std;

int main() {
    queue<string> pcQueue;
    producer<string> prod = producer<string>(&pcQueue);
    consumer<string> cons = consumer<string>(&pcQueue);
    
    prod.produce("hello");
    cout << cons.consume() << endl;
    return 0;
}