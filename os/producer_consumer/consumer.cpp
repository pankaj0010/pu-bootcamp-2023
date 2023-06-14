#include <string>
#include <queue>
using namespace std;

template <typename T>
class consumer {
    private:
        queue<T>* q;
    public:
        consumer(queue<T>* q) {
            this->q = q;
        }
        T consume() {
            T item = q->front();
            q->pop();
            return item;
        }
};