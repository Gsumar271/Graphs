//
//  WeightGraph.h
//  graphpractice
//
//  Created by Eugene Sumaryev on 4/13/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef WeightGraph_h
#define WeightGraph_h


#include <cstdlib>  //
#include <set>      //
#include <string>
#include <iostream>

using namespace std;

namespace classProgram
{
    class WeightGraph
    {
    public:
        // MEMBER CONSTANTS
        typedef string valueType;
        WeightGraph(){};
        WeightGraph(size_t arraySize);
        ~WeightGraph();
        
        // MODIFICATION MEMBER FUNCTIONS
        void addVertex(valueType label);
        void addEdge(size_t source, size_t target, int weight);
        void removeEdge(size_t source, size_t target);
        valueType& operator [] (size_t vertex);
        
        // CONSTANT MEMBER FUNCTIONS
        size_t size() const { return vertices; }
        valueType getVertex(int vertexNumber) const {return labels[vertexNumber];}
        bool isEdge(size_t source, size_t target) const;
        int getWeight(size_t source, size_t target) const;
        set<size_t> neighbors(size_t vertex) const;
        
        void listEdges();
    private:
        
        int** edges;
        valueType* labels;
        size_t vertices;
    };
}

#endif /* WeightGraph_h */
