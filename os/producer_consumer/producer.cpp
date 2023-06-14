#include <string>

#include "data_holder.cpp"

using namespace std;

template <typename T>
class producer {
    private:
        data_holder<T>* dh;
    public:
        producer(data_holder<T>* dh) {
            this->dh = dh;
        }
        void produce(T item) {
            dh->insert(item);
        }
};