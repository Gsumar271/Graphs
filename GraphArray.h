//
//  grapharray.h
//  graphpractice
//
//  Created on 4/2/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef grapharray_h
#define grapharray_h

#include <stdio.h>
#include <cassert>    //
#include <cstdlib>    //
#include <set>        //
#include "graphnode.h"

namespace classProgram

{
    
    //A struct to hold a list of graph nodes
    struct GraphList
    {
        struct GraphNode* head;
        struct GraphNode* tail;
        GraphList(){
            head = NULL;
            tail = NULL;
        }
    };
    
    class GraphArray
    {
    public:
        
        //TYPEDEF
        typedef string valueType;
        
        //CONSTRUCTORS
        GraphArray(size_t arraySize);
        
        
        
        // CONSTANT MEMBER FUNCTIONS
        const valueType getHeadVertex(size_t index){ return array[index].head->getVertex(); }
        
        
        void addVertex(valueType label, size_t index);
        void addEdge(size_t source, size_t target, size_t weight);
        
        
        
        
        void print();
         
        
    private:
        GraphList* array;
        size_t size;
    };
}


#endif /* grapharray_h */
