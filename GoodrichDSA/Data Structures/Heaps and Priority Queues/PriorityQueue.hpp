//
//  PriorityQueue.hpp
//  GoodrichDSA
//
//  Created by Harshavardhan K K on 24/01/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

#include <iostream>
#include <vector>
#include <exception>

class QueueEmptyException: public std::exception {
    const char * what() const throw() {
        return "Queue is empty\n";
    }
    
};


// ================================================================================================

template <typename T>

class HeapNode {
    
public:
    
    T element;
    
    int index;
    int right_index;
    int left_index;
    int parent_index;
    
    HeapNode(T element) {
        
        this->element = element;
        
        right_index = -1;
        parent_index = -1;
        left_index = -1;
        index = -1;
        
    }
    
    void update_index(int index) {
        
        this->index = index;
        compute_left_index();
        compute_right_index();
    }
    
    bool operator < (HeapNode<T>& node) {
        return this->element < node.element;
    }
    
    bool operator > (HeapNode<T>& node) {
        return this->element > node.element;
    }
    
    bool operator == (HeapNode<T>& node) {
        return this->element == node.element;
    }
    
    
private:
    
    const void compute_right_index() const {
        
        right_index = 2 * index + 2;
    }
    
    const void compute_left_index() const {
        
        left_index = 2 * index + 1;
    }
    
    const void compute_parent_index() const {
        
        parent_index = (index - 1) / 2;
        
    }
    
};

template <typename T>
class Heap {
    
private:
    
    std::vector<HeapNode<T>> list;
    int capacity;
    int heap_size;
    
    bool check_violation(int index) const;
    
public:
    
    Heap(int capacity) {
        
        heap_size = 0;
        this->capacity = capacity;
    }
    
    void min_heapify(int) const;
    void insert(HeapNode<T>& heap_node) const;
    const HeapNode<T>& extract_min();
    
    HeapNode<T> get_min() const {
        return list[0];
    }
    
    int get_heap_size() const {
        return list.size();
    }
    
    void print_heap_list() const {
        for(auto &ele: list)
            std::cout << ele.element << " ";
        
        std::cout << std::endl;
    }
    
    void add_to_list(HeapNode<T>& node) {
        this->list.push_back(node);
    }
    
};

//====== DATA GEENERATORS (HELPERS) ===========

#endif /* PriorityQueue_hpp */
