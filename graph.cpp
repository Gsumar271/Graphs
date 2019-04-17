//
//  graph.cpp
//  graphpractice
//
//  Created on 3/29/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//



#include <stdio.h>
#include <cassert>    //
#include <cstdlib>    //
#include <set>        //
#include "graph.h"

namespace classProgram
{
    
    graph::graph(size_t arraySize){
        vertices = 0;
        labels = new valueType [arraySize];

        //to dynamically initialze a double array
        edges = new bool*[arraySize];
        for(int i = 0; i < arraySize; i++) {
            edges[i] = new bool[arraySize];
            }
    }
    
    //clean up code
    graph::~graph(){
        
        //deallocate labels pointer
        delete[] labels;
    
        //deallocate edges
        for(int i = 0; i < vertices; i++) {
            delete [] edges[i];
        }
        delete [] edges;
    }
    
    void graph::addEdge(size_t source, size_t target)
    //
    {
        //to add an edge, initialize boolean array entry to true
        edges[source][target] = true;
    }

    
    //to add a vertex to the graph
    void graph::addVertex(const valueType label)
    //
    {
        size_t newVertexIndex;
        size_t otherIndex;

    //initialize entries in boolean matrix for the following vertex to false
        newVertexIndex = vertices;
        vertices++;
        for (otherIndex = 0; otherIndex < vertices; ++otherIndex)
        {
            edges[otherIndex][newVertexIndex] = false;
            edges[newVertexIndex][otherIndex] = false;
        }
        //add vertex to the labels array
        labels[newVertexIndex] = label;
    }

    //check if the edge exists
    bool graph::isEdge(size_t source, size_t target) const
    //
    {

        return edges[source][target];
    }
    
    //Method to print all the edges in the graph
    void graph::listEdges(){
        for (int i=0; i<size(); i++ ){
            for(int j=i; j< size(); j++){
                if(isEdge(i,j))
                   cout<<getVertex(i)<<" to "<<getVertex(j)<<endl;
            }
        }
    }
    
    
    //remove an edge
    void graph::removeEdge(size_t source, size_t target)
    //
    {
        edges[source][target] = false;
    }
    
    //get the neighbors of a vertex
    set<size_t> graph::neighbors(size_t vertex) const
    {
        set<size_t> answer;
        size_t i;
        
        
        for (i = 0; i < size(); ++i)
        {
            if (edges[vertex][i])
                answer.insert(i);
        }
        return answer;
    }
    
    graph::valueType& graph::operator[] (size_t vertex)
    {

        return labels[vertex];     // Returns a reference to the label
    }
}
















