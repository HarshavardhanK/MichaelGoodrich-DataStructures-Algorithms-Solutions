//
//  GenericLinkedList.hpp
//  GoodrichDSA
//
//  Created by Harshavardhan K K on 23/01/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#ifndef GenericLinkedList_hpp
#define GenericLinkedList_hpp

#include <iostream>

template <typename T>

class GenericLinkedListNode {
public:
    
    T element;
    GenericLinkedListNode<T>* next;
    
    //friend class GenericLinkedList<T>;
};

template <typename T>

class GenericLinkedList {
    
public:
    
    GenericLinkedList();
    ~GenericLinkedList();
    
    bool empty() const;
    const T& front() const;
    void append_beginning(const T& element);
    void remove_beginning();
    
private:
    
    GenericLinkedListNode<T>* head;
};





#endif /* GenericLinkedList_hpp */
