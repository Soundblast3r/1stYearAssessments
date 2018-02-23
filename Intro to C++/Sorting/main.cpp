#include <iostream> 
#include <chrono> 
#include "main.h"

using namespace std;
using namespace std::chrono;

void bubbleSort(int * const values, int size)
{
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (int index = 0; index < size - 1; index++)
		{
			if (values[index] < values[index + 1])
			{
				int swapHolder;
				swapHolder = values[index];
				values[index] = values[index + 1];
				values[index + 1] = swapHolder;
				swapped = true;
			}
		}
	}
}

int main()
{
	const int size = 100; 
	
	// create a large array 
	int* values = new int[size]; 
	
	
	srand(time(nullptr)); 
	// and fill it with some ordered data 
	for (int i = 0; i < size; i++)
	{
		values[i] = rand() % size;
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << values[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << "sorting..." << std::endl;
	high_resolution_clock::time_point t1, t2;
	
	t1 = high_resolution_clock::now();
	
	bubbleSort(values, size);
	t2 = high_resolution_clock::now();

	for (int i = 0; i < size; i++)
	{
		std::cout << values[i] << ", ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "bubble sort took " << (t2 - t1).count() << " nanoseconds" << std::endl;
	delete[] values;
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get(); 
	return 0;
}

main::~main()
{
}


