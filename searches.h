//
//  searches.h
//  graphpractice
//
//  Created by Eugene Sumaryev on 4/11/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef searches_h
#define searches_h

#include <string>
#include "graph.h"

namespace classProgram
{
    typedef size_t SizeType;
    const int MAXIMUM = 20;
    
    void DfsHelper(graph& g, SizeType v, bool marked[]);
    
    void DepthFirst(graph& g, SizeType start);
    
    void BreadthFirst(graph& g, SizeType start);
    
    void print(string label);
}

#endif /* searches_h */
