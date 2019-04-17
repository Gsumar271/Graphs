//
//  WeightGraph.cpp
//  graphpractice
//
//  Created by Eugene Sumaryev on 4/13/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//


#include <stdio.h>
#include <cassert>    //
#include <cstdlib>    //
#include <set>        //
#include "WeightGraph.h"

namespace classProgram
{
    
    WeightGraph::WeightGraph(size_t arraySize){
        vertices = 0;
        labels = new valueType [arraySize];
        
        //to dynamically initialze a double array
        edges = new int*[arraySize];
        for(int i = 0; i < arraySize; i++) {
            edges[i] = new int[arraySize];
        }
    }
    
    //clean up code
    WeightGraph::~WeightGraph(){
        
        //deallocate labels pointer
        delete[] labels;
        
        //deallocate edges
        for(int i = 0; i < vertices; i++) {
            delete [] edges[i];
        }
        delete [] edges;
    }
    
    void WeightGraph::addEdge(size_t source, size_t target, int weight)
    //
    {
        //to add an edge, initialize int array entry to the weight
        edges[source][target] = weight;
    }
    
    
    //to add a vertex to the graph
    void WeightGraph::addVertex(const valueType label)
    //
    {
        size_t newVertexIndex;
        size_t otherIndex;
        
        //initialize entries in boolean matrix for the following vertex to false
        newVertexIndex = vertices;
        vertices++;
        for (otherIndex = 0; otherIndex < vertices; ++otherIndex)
        {
            edges[otherIndex][newVertexIndex] = 0;
            edges[newVertexIndex][otherIndex] = 0;
        }
        //add vertex to the labels array
        labels[newVertexIndex] = label;
    }
    
    //check if the edge exists
    bool WeightGraph::isEdge(size_t source, size_t target) const
    //
    {
        if(edges[source][target] != 0)
            return true;
        else
            return false;
    }
    
    int WeightGraph::getWeight(size_t source, size_t target) const
    {
        return edges[source][target];
    }
    
    
    //Method to print all the edges in the graph
    void WeightGraph::listEdges(){
        for (int i=0; i<size(); i++ ){
            for(int j=i; j< size(); j++){
                if(isEdge(i,j))
                    cout<<getVertex(i)<<" to "<<getVertex(j)<<endl;
            }
        }
    }
    
    
    //remove an edge
    void WeightGraph::removeEdge(size_t source, size_t target)
    //
    {
        edges[source][target] = 0;
    }
    
    //get the neighbors of a vertex
    set<size_t> WeightGraph::neighbors(size_t vertex) const
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
    
    WeightGraph::valueType& WeightGraph::operator[] (size_t vertex)
    {
        
        return labels[vertex];     // Returns a reference to the label
    }
}


