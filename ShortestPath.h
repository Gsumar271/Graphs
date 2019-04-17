//
//  ShortestPath.h
//  graphpractice
//
//  Created by Eugene Sumaryev on 4/11/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef ShortestPath_h
#define ShortestPath_h

#include <string>
#include "WeightGraph.h"

namespace classProgram
{
    const int MAXIMUM = 20;
    int distance[MAXIMUM];
    set<size_t> allowedVertices;
    
    void ShortestDistancePath(WeightGraph wg);

}

#endif /* ShortestPath_h */
