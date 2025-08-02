#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include "main.h"

template <typename T>
class DoublyLinkedList
{
    // TODO: may provide some attributes
private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;
        Node() : prev(nullptr), next(nullptr) {}
        Node(const T &val, Node *prev = nullptr, Node *next = nullptr) : data(val), prev(prev), next(next) {}
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    int length = 0;

public:

    DoublyLinkedList();
    ~DoublyLinkedList(){
        
        while(head != nullptr){
            Node* temp = head->next;
            delete head;
            head = temp;

        }
        head = nullptr;
    };

    void insertAtHead(const T& data) {
    Node* newNode = new Node(data);

    newNode->next = head->next;
    newNode->prev = head;

    head->next->prev = newNode;
    head->next = newNode;

    length++;
}

    void insertAtTail(const T& data) {
    Node* newNode = new Node(data);

    newNode->next = tail;
    newNode->prev = tail->prev;

    tail->prev->next = newNode;
    tail->prev = newNode;

    length++;
}

    void insertAt(int index, T data){
        Node* temp = head;
        if(index > length){
            cout<<"khong the duoc roi";
            return;
        }
        Node* newNode = new Node(data);
        int count = 0;
        while(count != index){
            count++;
            temp = temp->next;

        }
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    };
    void deleteAt(int index) {
    if (index < 0 || index >= length) return;

    Node* temp = head->next;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    length--;
}
T& get(int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }

    Node* temp = head->next;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    return temp->data;
}


    int indexOf(T item) const{
        Node* temp = head;
        int count = 0;
        while(temp->data != item && temp != nullptr){
            temp = temp->next;
            count++;
        }
        if(temp == nullptr){
            return -1;

        }
        return count;

    };
    bool contains(T item) const{
        Node* temp = head;
        
        while(temp != nullptr){
            if(temp->data == item){
                return 1;
            }
            temp = temp->next;
            
        }
        return 0;
    };
    int size() const{
        return length;
    };
    void reverse() {
    Node* current = head;
    while (current != nullptr) {
        std::swap(current->next, current->prev);
        current = current->prev; // vì next và prev đã bị swap
    }

    // Hoán đổi dummy head và tail
    std::swap(head, tail);
}

    std::string toString(std::string (*convert2str)(T&) = nullptr) const {
    if (convert2str == nullptr) {
        return "[no conversion function provided]";
    }

    std::string result;
    
    Node* current = head->next; // bỏ dummy node
    result+='[';
    while (current != tail) {
        result += convert2str(current->data);
        if(current->next != tail) result+= ", ";
        
        current = current->next;
    }
    
    result+=']';
    return result;
}

    class Iterator
    {
    private:
        Node *current;
        const DoublyLinkedList<T> *list;

    public:
        Iterator(Node *node, const DoublyLinkedList<T> *list) : current(node), list(list) {}

        // TODO implement Iterator
        Iterator& operator++(){
            if(current) current = current->next;
            return *this;

        }
        bool  operator!=( const Iterator& other) const{
            return current!= other.current;
        }
        bool  operator==( const Iterator& other) const{
            return current == other.current;
        }
        
        
        T& operator*() { return current->data; }

       
        
    }; 

    Iterator begin() const
    {
        return Iterator(head->next, this);
    }

    Iterator end() const
    {
        return Iterator(tail, this);
    }
};

#endif // __DOUBLY_LINKED_LIST_H__
