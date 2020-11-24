template<class T>
class SinglyLinkedNode {
public:
    T value;
    SinglyLinkedNode<T>* Next = NULL;

    SinglyLinkedNode<T>() {};
    SinglyLinkedNode<T>(T val) {
        value = val;
    }
    SinglyLinkedNode<T>(T val, SinglyLinkedNode<T>* next) {
        value = val;
        Next = next;
    }
};