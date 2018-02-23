#pragma once
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include <vector>
class GraphEdge;

class GraphNode
{
public:
	GraphNode();
	~GraphNode();

	//data stored in the node
	Vector2 data;
	//list of edges this node has
	std::vector<GraphEdge*> edges;
	//has the node been processed
	bool traversed;
	//is the node currently in our queue (used by 
	//the Breadth First Search function
	bool isInQueue;
	//order we processed this node
	int order;

	float gScore;
	GraphNode* prevNode;
};