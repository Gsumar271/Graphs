//
//  grapharray.cpp
//  graphpractice
//
//  Created on 4/2/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#include <stdio.h>
#include <cassert>    //
#include <cstdlib>    //
#include <set>        //
#include "grapharray.h"

namespace classProgram

{
    
    GraphArray::GraphArray(size_t arraySize){
        array = new GraphList [arraySize];
        size = arraySize;
    }
    
    
    
    void GraphArray::addEdge(size_t source, size_t target, size_t weight){
        
        
        //extract the label from the target node
        valueType label = array[target].head->getVertex();
        //create new node
        GraphNode* newNode = new GraphNode(label, weight);
        
        //set tail's link to new node
        array[source].tail->setLink(newNode);
        //make it the new tail
        array[source].tail = newNode;
        
        //perform the same operation to connect source node to target node
        label = array[source].head->getVertex();
        newNode = new GraphNode(label, weight);
        
        array[target].tail->setLink(newNode);
        
        //make it the new tail
        array[target].tail = newNode;
        
    }
    
    
    //to add a vertex to the array
    void GraphArray::addVertex(valueType label, size_t index){
        
        //create a node and intitialize it
        GraphNode *newHeadNode = new GraphNode(label, 0);
        newHeadNode->setLink(NULL);
        array[index].head = newHeadNode;
        array[index].tail = newHeadNode;
    }
    
    
    void GraphArray::print(){
        
        GraphNode* cursor;
       
        //step through each array entry
        for (int i = 0; i<size; i++){
            
            cursor = array[i].head;
            //step through all the links
            cursor = cursor->getLink();
            cout<< "\n The following are the links for the node with label "<<array[i].head->getVertex()<<" : \n";
            while (cursor != NULL) {
                cout<< array[i].head->getVertex() << " to "<<cursor->getVertex() <<
                " weight: " << cursor->getWeight()<<"; ";
                cursor = cursor->getLink();
            }
            
        }
     
    }
    
    
    
    
}
