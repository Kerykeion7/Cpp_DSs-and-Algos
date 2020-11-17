template<class T>
class DynamicArray {
private:
    int _minCapacity = 4;
    int _capacity;
    T* items;
    void Resize();
    void AllocateNewCapacity(int newCapacity);
    void ExitIfIndexOutOfBounds(int index);
    void ExitIfArrayIsEmpty();

public:
    DynamicArray();
    DynamicArray(int capacity);

    ~DynamicArray();
    T& operator[](int index);
    void operator=(T temp);

    int Count = 0;
    void Push(T item);
    T Pop();
    int Length();
    int Capacity();
    bool IsEmpty();
    T GetAt(int index);
    void InsertAt(T item, int index);
    void Prepend(T item);
    void RemoveAt(int index);
    void Remove(T item);
    int IndexOf(T item);
    void Clear();
};
