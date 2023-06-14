#ifndef DATA_HOLDER
#define DATA_HOLDER

template <typename T>
class data_holder {
    public:
        virtual bool isEmpty() = 0;
        virtual bool isFull() = 0;
        virtual void insert(T item) = 0;
        virtual T* getNextItem() = 0;
        virtual void deleteNextItem() = 0;
};

#endif