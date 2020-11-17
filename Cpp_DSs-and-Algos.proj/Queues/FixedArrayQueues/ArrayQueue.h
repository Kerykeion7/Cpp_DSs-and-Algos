template<class T>
class ArrayQueue {
private:
    int length = 0;
    int maxCap = 6;

public:
    T* data = new T[maxCap];

    T& operator[](int index);
    bool IsEmpty();
    bool IsFull();
    int Length();
    void Enqueue(T value);
    T Dequeue();
};
