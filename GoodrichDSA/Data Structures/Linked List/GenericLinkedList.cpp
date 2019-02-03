//
//  GenericLinkedList.cpp
//  GoodrichDSA
//
//  Created by Harshavardhan K K on 23/01/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#include "GenericLinkedList.hpp"

template <typename T>
GenericLinkedList<T>::GenericLinkedList() : head(NULL) {}

template <typename T>
bool GenericLinkedList<T>::empty() const {
    return head == NULL;
}

template <typename T>
const T& GenericLinkedList<T>::front() const {
    return head->element;
}

template <typename T>
GenericLinkedList<T>::~GenericLinkedList<T>() {
    
    while (!empty())
        remove_beginning();
}

template <typename T>
void GenericLinkedList<T>::append_beginning(const T& element) {
    
    GenericLinkedListNode<T>* new_node = new GenericLinkedListNode<T>;
    new_node->element = element;
    new_node->next = head;
}

template <typename T>
void GenericLinkedList<T>::remove_beginning() {
    
    GenericLinkedListNode<T>* front = head;
    head = front->next;
    delete front;
}
