#pragma once
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "GraphEdge.h"
#include "GraphNode.h"
#include "Renderer2D.h"
#include "Texture.h"
#include <vector>

class Graph
{
public:
	Graph();
	~Graph();
	


	//adds a GraphNode to our graph with a_data inside it
	GraphNode* AddNode(Vector2& a_data);

	//will add an edge from start to end 
	GraphEdge* AddEdge(GraphNode& a_start, GraphNode& a_end, float a_cost);

	//draw the nodes of the graph and the edges between them
	void DrawGraph(aie::Renderer2D& renderer);

	//which gets the closest node to this position
	GraphNode* GetNodeAtPosition(const Vector2& a_pos);

	//implement a Breadth First Search algorithm that starts at a_start
	//and visits every single node setting its order from 1 - N
	void BreadthFirstSearch(GraphNode& a_start);

	void SetTexture(aie::Texture* a_texture);
	void SetRendererAddress(aie::Renderer2D* a_renderer);
	//dynamic array of all the nodes in our graph
	std::vector< GraphNode* > m_nodes;

	std::vector<Vector2> CalculatePath(GraphNode* startNode, GraphNode* endNode);
private:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
};

class CompareGScore
{
public:
	bool operator()(GraphNode* n1, GraphNode* n2) const
	{
		//return true if first node GScore is GREATER than second node's
		return n1->gScore < n2->gScore;
		
	}
};