#include "AI_Graph.h"
#include <iostream>



AI_Graph::AI_Graph()
{
}


AI_Graph::~AI_Graph()
{
}

int main()
{
	int size;
	std::cout << "Size: ";
	std::cin >> size;
	char *value;
	value = new char[size];
	std::cout << "Enter vertices: ";
	for (int i = 0; i < size; ++i)
	{
		std::cin >> value[i];
	}
	Graph <char>g1(value, size);
	Graph <char>g2(value, size);
	int choice = 1;
	char vertA, vertB, searchElement;
	while (1)
	{
		std::cout << "Do you want to set an edge?(1/0): ";
		std::cin >> choice;
		if (choice)
		{
			std::cin >> vertA >> vertB;
			g1.setEdge(vertA, vertB);
			g2.setEdge(vertA, vertB);
		}
		else
			break;
	}
	std::cout << std::endl;
	std::cout << "Search element: ";
	std::cin >> searchElement;
	std::cout << std::endl;
	g1.display();
	g1.setSearchElement(searchElement);
	g2.setSearchElement(searchElement);
	std::cout << "BFS: ";
	g2.search('b');
	std::cout << std::endl;
	std::cout << "DFS: ";
	g1.search('d');
	std::cout << std::endl;
}