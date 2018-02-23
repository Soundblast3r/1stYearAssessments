#include "Graph.h"
#include <iostream>
#include <list>

GraphNode* NodeArray;

Graph::Graph()
{
	m_texture = new aie::Texture("./textures/NodeCircle2.png");
}


Graph::~Graph()
{
}

GraphNode * Graph::AddNode(Vector2 & a_data)
{
	GraphNode* NewNode = new GraphNode;
	NewNode->data = a_data;
	m_nodes.push_back(NewNode);
	return NewNode;
	
}

GraphEdge * Graph::AddEdge(GraphNode & a_start, GraphNode & a_end, float a_cost)
{
	//create a New graph edge
	GraphEdge* NewEdge = new GraphEdge;
	NewEdge->start = &a_start;
	NewEdge->end = &a_end;
	NewEdge->cost = a_cost;
	a_start.edges.push_back(NewEdge);
	return NewEdge;
}

void Graph::BreadthFirstSearch(GraphNode & a_start)
{
	int i = 0;
	//push first node onto queue
	std::list<GraphNode*> queue;

	queue.push_back(&a_start);
	a_start.isInQueue = true;

	//while queue not empty
	while (!queue.empty())
	{
		//get the end off the queue
		GraphNode* currNode = queue.front();

		//remove it (pop_front)
		queue.pop_front();
		currNode->isInQueue = false;

		//process it (set its order)
		currNode->order = i;
		i++;
		
		//mark it as traversed
		currNode->traversed = true;
		
		//loop through its edges
		for (int j = 0; j < currNode->edges.size(); j++)
		{
			GraphEdge* currEdge = currNode->edges[j];

			//if end node of edge not traversed or in the queue
			if (currEdge->end->traversed != true && currEdge->end->isInQueue != true)
			{
				//push end node onto the queue (push_back)
				queue.push_back(currEdge->end);
				currEdge->end->isInQueue = true;
			}
		}
	}
}

void Graph::SetRendererAddress(aie::Renderer2D* a_renderer)
{
	m_2dRenderer = a_renderer;
}



GraphNode * Graph::GetNodeAtPosition(const Vector2 & a_pos)
{
	for (int i = 0; i < m_nodes.size(); i++)
	{
		for (int j = 0; j < m_nodes.size(); j++)
		{
			//if it's the same node, move to next node
			if (i == j)
				continue;
			//add an edge between the nodes that need edges added
			int dist = (m_nodes[i]->data - a_pos).Magnitude();
			if (dist < 50)
			{
				return m_nodes[i];
			}
			else if (dist > 50)
			{
				continue;
			}
		}

	}

	//return the first node if we aren't close to any other nodes
	return m_nodes[0];
}

void Graph::DrawGraph(aie::Renderer2D & renderer)
{

	//inside Graph ALL of your graph nodes are in the m_nodes array
	//AND all of your graph nodes have data which represents their x and y location
	for (int i = 0; i < m_nodes.size(); i++)
	{
		for (int j = 0; j < m_nodes[i]->edges.size(); j++)
		{
			//loop over m_nodes[i]'s edges
			//use renderer to draw a line between edge start and edge end

			m_2dRenderer->drawLine(m_nodes[i]->edges[j]->start->data.x, m_nodes[i]->edges[j]->start->data.y, m_nodes[i]->edges[j]->end->data.x, m_nodes[i]->edges[j]->end->data.y, 1.0f);
		}


	}
	//loop over every node using i (m_nodes.size())
		//draw a circle at that node's data
	for (int i = 0; i < m_nodes.size(); i++)
	{


		float colorValue = (float)m_nodes[i]->order / (float)m_nodes.size();

		m_2dRenderer->setRenderColour(colorValue, 1.0f, colorValue, 1.0f);
		m_2dRenderer->drawSprite(m_texture, m_nodes[i]->data.x, m_nodes[i]->data.y, 10, 10);
		m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

		
	}



}

//https://sites.google.com/aie.edu.au/aiean2017/artificial-intelligence-for-games/dijkstras
std::vector<Vector2> Graph::CalculatePath(GraphNode * startNode, GraphNode * endNode)
{
	//reset all nodes back to default values
	for (int i = 0; i < m_nodes.size(); i++)
	{
		//set traversed and isInQueue to false
		m_nodes[i]->isInQueue = false;
		m_nodes[i]->traversed = false;

		//set prevNode to nullptr
		m_nodes[i]->prevNode = nullptr;

		//set GScore to max number for a float
		m_nodes[i]->gScore = std::numeric_limits<float>::max();
	}
	///create a list of GraphNode* as your queue (see below)
	///create a CompareGScore comparison object (see below)





		//push first node onto queue
	std::list<GraphNode*> queue;
	queue.push_back(startNode);

	//set startNode's isInQueue to true
	startNode->isInQueue = true;

	//set startNode's prevNode to itself
	startNode->prevNode = startNode;

	//set startNode's GScore to 0
	startNode->gScore = 0;

	//loop while queue is not empty
	while (!queue.empty())
	{
		//sort our queue by GScore (see below) USE Extra Knowledge on Dijkstra's Page.
		CompareGScore comparison;
		queue.sort(comparison);
		//remove the first node from the queue (back)
		GraphNode* currNode = queue.front();
		queue.pop_front();
		//set isInQueue to false
		currNode->isInQueue = false;
		//set traversed to true
		currNode->traversed = true;

		//loop over all of the currNode's edges
		for (int j = 0; j < currNode->edges.size(); j++)
		{
			GraphEdge* currEdge = currNode->edges[j];

			//if edges endNode is not traversed
			if (currEdge->end->traversed != true && currEdge->end->isInQueue != true)
			{
				//calculate the newGScore based on currNode.GScore + currEdge's cost
				float newGScore = currNode->gScore + currEdge->cost;
				//if the newGScore is less than endNode's current GScore
				if (newGScore < endNode->gScore)
				{
					//set edge.endNode.prevNode to currNode (update the node it came from)
					currEdge->end->prevNode = currNode;
					//set edge.endNode.GScore to newScore (update it)
					currEdge->end->gScore = newGScore;

					//if edge.endNode is not in the queue
					if (currEdge->end->isInQueue != true)
					{
						//add edge.endNode to the queue
						queue.push_back(currEdge->end);
						//set edge.endNode.IsInQueue to true  
						currEdge->end->isInQueue = true;
					}
				}
			}
		}
	}

	//create an std::vector of Vector2s to store our pathPoints
	std::vector<Vector2> PathPoints;
	//create a GraphNode* to keep track of the node we are looking at (currNode)
	GraphNode* currNode;
	//set currNode to point at the endNode
	currNode = endNode;
	//while currNode is not null AND currNode is not the startNode
	while (currNode != NULL && startNode != currNode)
	{
		//add currNode's data (point) to our pathPoints array
		PathPoints.push_back(currNode->data);
		//set currNode = currNode.prevNode (this should remind you of the list code)   
		currNode = currNode->prevNode;
	}
	//add the startNode's data to our pathPoints 
	PathPoints.push_back(startNode->data);
	
	//reverse the pathPoints dynamic array (as Dijkstra's gives us the path backwards)
	std::reverse(PathPoints.begin(), PathPoints.end());
	//return the finalPath
	return PathPoints;
}

