//
//  PriorityQueue.cpp
//  GoodrichDSA
//
//  Created by Harshavardhan K K on 24/01/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#include "PriorityQueue.hpp"


//==============
template <typename T>
bool Heap<T>::check_violation(int index) const {
    
    bool violation = false;
    int i = index;
    
    
    while(index != 0 && list[list[i].parent_index] > list[i]) {
        violation = true;
        
        list[i].update_index(list[i].parent_index);
        list[list[i].parent_index].update_index(i);
        
        std::swap(&list[list[i].parent_index], &list[i]);
        i = list[i].parent_index;
    }
    
    return violation;
}

template <typename T>
void Heap<T>::min_heapify(int index) const {
    
    int right_child_index = list[index].right_index;
    int left_child_index = list[index].left_index;
    int smallest = index;
    
    if(left_child_index < list.size() && list[left_child_index] < list[index]) {
        smallest = left_child_index;
    }
    
    if(right_child_index < list.size() && list[right_child_index] < list[index]) {
        smallest = right_child_index;
    }
    
    if(left_child_index < list.size() && list[left_child_index] < list[index]) {
        smallest = left_child_index;
    }
    
    if(smallest != index) {
        
        list[smallest].update_index(index);
        list[index].update_index(smallest);
        
        std::swap(&list[smallest], &list[index]);
    }
    
}

template <typename T>
void Heap<T>::insert(HeapNode<T> &heap_node) const {
    
    int insert_index = heap_size;
    list[insert_index] = heap_node;
    list[insert_index].update_index(insert_index);
    
    while(insert_index != 0 && list[heap_node.parent_index] > list[insert_index]) {
        
        list[insert_index].update_index(heap_node.parent_index);
        std::swap(list[heap_node.parent_index], list[insert_index]);
        insert_index = heap_node.parent_index;
    }
    
}

template <typename T>
const HeapNode<T>& Heap<T>::extract_min() {
    
    get_heap_size();
    
    if(heap_size == 1) {
        HeapNode<T> root = list[0];
        list.erase(list.begin());
        return root;
    }
    
    HeapNode<T> root = list[0];
    list[0] = list[heap_size - 1];
    list.erase(list.end());
    
    min_heapify(0);
    
    return root;
}


