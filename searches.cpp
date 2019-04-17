//
//  searches.cpp
//  graphpractice
//
//  Created by Eugene Sumaryev on 4/11/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <set>
#include "graph.h"
#include "searches.h"

using namespace std;

namespace classProgram
{
    void DfsHelper(graph& g, SizeType v, bool marked[])
    // Precondition: g is a labeled graph that is being traversed by a
    // depth-first search. For each vertex x, marked[x] is true if x has
    // already been visited by this search, otherwise marked[x] is false.
    // The vertex v is an unmakred vertex that the search has just arrived at.
    // Postcondition: the depth-first search of g has been continued
    // through vertex v and beyond to all the vertices that can be reached
    // from v via a path of unmarked vertices.  The function f has been
    // applied to the labe of each vertex visited by the search, and each
    // such vertex x has also been marked by setting marked[x] to true.
    // Library facilities used: cstdlib, graph.h, set
    {
        set<size_t> connections = g.neighbors(v);
        set<size_t>::iterator it;
        
        marked[v] = true;  // Mark vertex v
        print(g[v]);           // Process the label of vertex v with the function f
        
        // Traverse all the neighbors, looking for unmarked vertices:
        for (it = connections.begin(); it != connections.end(); ++it)
        {
            if (!marked[*it])
                DfsHelper(g, *it, marked);
        }
    }
    
    void DepthFirst(graph& g, SizeType start)
    // Precondion: start is a vertex number of the labeled graph g.
    // Postcondition: A depth-first search of g has been executed,
    // starting at the start vertex.  The function f has been applied to the
    // label of each vertex visited by the search.
    {
        bool marked[MAXIMUM];
        
        fill_n(marked, g.size(), false);
        DfsHelper(g, start, marked);
    }
    

    void BreadthFirst(graph& g, SizeType start)
    // Precondition: start is a vertex number of the labeled graph g.
    // Postcondition: A breadth-first search of g has been executed,
    // starting at the start vertex. The function f has been applied to the
    // label of each vertex visited by the search
    {
        bool marked[MAXIMUM];
        set<size_t> connections;
        set<size_t>::iterator it;
        queue<size_t> vertexQueue;

        fill_n(marked, g.size(), false);
        marked[start] = true;
        print(g[start]);
        vertexQueue.push(start);
        do
        {
            connections = g.neighbors(vertexQueue.front());
            vertexQueue.pop();
            // Mark and process the unmarked neighbors,
            // and place them in the queue.
            for (it = connections.begin(); it != connections.end(); ++it)
            {
                if (!marked[*it])
                {
                    marked[*it] = true;
                    print(g[*it]);
                    vertexQueue.push(*it);
                }
            }
        }   
        while (!vertexQueue.empty());
    }
    
    void print(string label){
        cout<<" "<< label <<" ";
    }
}
