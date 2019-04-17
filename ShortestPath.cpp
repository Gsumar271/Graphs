//
//  ShortestPath.cpp
//  graphpractice
//
//  Created by Eugene Sumaryev on 4/11/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <set>
#include "ShortestPath.h"
#include "graph.h"

using namespace std;

namespace classProgram
{
    
    int closest(int array[]){
        int smallest = array[0];
        
        for (int i = 1; i < MAXIMUM; i++){
            if (array[i] != -1 && array[i] < smallest)
                smallest = array[i];
        }
        
        return smallest;
    }
 
    void ShortestDistancePath(WeightGraph wg){
        int vertex;
        int allowedSize;
        int sum;
        int start = 0;
        int next;
        
        //Step 1
        fill_n(distance, MAXIMUM, -1);
        
        
        //Step 2
        distance[start] = 0;
        
        //Step 3
        for(allowedSize = 1; allowedSize < MAXIMUM; allowedSize++) {
            next = closest(distance);
            allowedVertices.insert(next);
            
            for (vertex = 0; vertex < MAXIMUM; vertex++ ){
                if(allowedVertices.find(vertex) != allowedVertices.end() && (wg.isEdge(next, vertex)))
                   {
                       sum = distance[next] + (wg.getWeight(next, vertex));
                       if (sum < distance[vertex])
                           distance[vertex] = sum;
                   }
                   
                }
        }
        
        //step 4
        //print
        
    }

}
