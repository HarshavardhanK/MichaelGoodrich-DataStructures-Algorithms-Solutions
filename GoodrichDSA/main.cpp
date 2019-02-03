//
//  main.cpp
//  GoodrichDSA
//
//  Created by Harshavardhan K K on 23/01/19.
//  Copyright © 2019 Harshavardhan K. All rights reserved.
//

#include <iostream>
#include "PriorityQueue.hpp"

using namespace std;

void test_heap() {
    HeapNode<int> *n1 = new HeapNode<int>(1);
    HeapNode<int> *n2 = new HeapNode<int>(2);
    HeapNode<int> n3(6);
    HeapNode<int> n4(5);
    HeapNode<int> n5(9);
    HeapNode<int> n6(8);
    
   Heap<int>* heap = new Heap<int>(8);
    
    heap->insert(n3);
    heap->insert(n4);
    heap->insert(n5);
    heap->insert(n6);
    
    heap->print_heap_list();
    
    //heap->add_to_list(n4);
   // heap->print_heap_list();
    
    //vector<HeapNode<int>> list;
    //list.push_back(*n1); //list.push_back(n2); list.push_back(n3); list.push_back(n4); list.push_back(n5); list.push_back(n6);
    
    //for(auto& ele: list) {
    //    cout << ele.element << " ";
    //}
    
    //cout << endl;
    
    cout << n1->element << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test_heap();
    std::cout << "Hello, World!\n";
    return 0;
}
