//
//  graph.h
//  graphpractice
//
//  Created on 3/29/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <cstdlib>  //
#include <set>      //
#include <string>
#include <iostream>

using namespace std;

namespace classProgram
{
    class graph
    {
    public:
        // MEMBER CONSTANTS
        typedef string valueType;
        graph(){};
        graph(size_t arraySize);
        ~graph();
        
        // MODIFICATION MEMBER FUNCTIONS
        void addVertex(valueType label);
        void addEdge(size_t source, size_t target);
        void removeEdge(size_t source, size_t target);
        valueType& operator [] (size_t vertex);
        
        // CONSTANT MEMBER FUNCTIONS
        size_t size() const { return vertices; }
        valueType getVertex(int vertexNumber) const {return labels[vertexNumber];}
        bool isEdge(size_t source, size_t target) const;
        set<size_t> neighbors(size_t vertex) const;

        void listEdges();
    private:
        
        bool** edges;
        valueType* labels;
        size_t vertices;
    };
}


#endif /* graph_h */
