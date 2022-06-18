#ifndef TAXES_EXAM_LIST_H
#define TAXES_EXAM_LIST_H
#include <stdexcept>

template <typename data_type>
struct LinkedList {

private:
    struct Node {
        data_type data;
        Node* next;
        explicit Node( data_type d, Node* n = nullptr ) {
            data = d;
            next = n;
        }
    };

    Node* head = nullptr;

public:
    int counter = 0;
    LinkedList() = default;
    ~LinkedList();
    void push(data_type data);
    data_type pop();
};

template <typename data_type>
LinkedList<data_type>::~LinkedList() {
    while ( head != nullptr ) {
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
    }

    counter = 0;
}

template <typename data_type>
void LinkedList<data_type>::push(data_type data) {
    Node* new_node = new Node(data);
    if ( head == nullptr ) {
        new_node->next = head;
        head = new_node;
    }
    else {
        Node* curr = head;
        while ( curr->next != nullptr ) {
            curr = curr->next;
        }
        curr->next = new_node;
    }

    ++counter;
}

template <typename data_type>
data_type LinkedList<data_type>::pop() {
    if ( head == nullptr ) {
        throw std::runtime_error("Empty List");
    }
    else {
        Node* pre_curr;
        Node* curr = head;
        data_type result;
        while ( curr->next != nullptr ) {
            pre_curr = curr;
            curr = curr->next;
        }
        pre_curr->next = nullptr;
        result = curr->data;
        delete curr;
        --counter;

        return result;
    }
}

#endif
