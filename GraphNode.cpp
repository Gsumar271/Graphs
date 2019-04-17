//
//  graphlist.cpp
//  graphpractice
//
//  Created on 4/2/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#include <stdio.h>
#include <cassert>    //
#include <cstdlib>    //
#include <set>        //
#include "graphnode.h"

namespace classProgram
{
    
    GraphNode::GraphNode(valueType& initTarget, size_t initWeight){
        label = initTarget;
        weight = initWeight;
        link = NULL;
        
    }
    
    //clean up code
    GraphNode::~GraphNode(){
    }
    
}
