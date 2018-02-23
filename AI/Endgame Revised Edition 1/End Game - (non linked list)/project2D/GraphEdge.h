#pragma once
#include "GraphNode.h"

class GraphEdge
{
public:
	GraphEdge();
	~GraphEdge();

	GraphNode* start;  //start node
	GraphNode* end;    //end node
	float cost;        //cost 
};