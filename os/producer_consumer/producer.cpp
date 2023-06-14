#include <string>
#include <queue>
using namespace std;

template <typename T>
class producer {
    private:
        queue<T>* q;
    public:
        producer(queue<T>* q) {
            this->q = q;
        }
        void produce(T item) {
            q->push(item);
        }
};