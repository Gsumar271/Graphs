//
//  graphlist.h
//  graphpractice
//
//  Created on 4/2/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef graphlist_h
#define graphlist_h

#include <cstdlib>  //
#include <set>      //
#include <string>
#include <iostream>

using namespace std;

namespace classProgram
{
    class GraphNode
    {
    public:
        // MEMBER CONSTANTS
        typedef string valueType;
        
        // CONSTRUCTORS
        GraphNode(){};
        GraphNode(valueType& initTarget, size_t initWeight);
        ~GraphNode();
        
        // MODIFICATION MEMBER FUNCTIONS
        void setLink(GraphNode* node){ link = node;}
        
        // CONSTANT MEMBER FUNCTIONS
        const valueType getVertex(){ return label; }
        const size_t getWeight(){ return weight; }
        GraphNode* getLink() { return link; }
        
    private:
        valueType label;
        size_t weight;
        GraphNode* link;
    };
}


#endif /* graphlist_h */
