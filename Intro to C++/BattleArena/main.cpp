#include <iostream>
#include "Unit.h"
#include <time.h>
#include <chrono>
#include <windows.h>

void pause(int dur)
{
	int temp = time(NULL) + dur;

	while (temp > time(NULL));
}

//void bubbleSort(Unit values, int size)
//{
//	bool swapped = true;
//	while (swapped)
//	{
//		swapped = false;
//		for (int index = 0; index < size - 1; index++)
//		{
//			if (values.GetHealth() < values.GetHealth())
//			{
//				Unit swapHolder;
//				swapHolder = values[index];
//				values[index] = values[index + 1];
//				values[index + 1] = swapHolder;
//				swapped = true;
//			}
//		}
//	}
//};

int main()
{
	//seed the random number generator
	srand( time(NULL) );

	int TeamA_Set;
	int TeamB_Set;
	int teamTurn = 1;
	
	
	Unit person;

	std::cout << "how many units are there on team A?" << std::endl;
	std::cin >> TeamA_Set;
	int TeamA_Size = TeamA_Set;
	std::cout << "there are: " << TeamA_Set << " Units on team A"<< std::endl;
	system("PAUSE");

	std::cout << "how many units are there on team B?" << std::endl;
	std::cin >> TeamB_Set;
	int TeamB_Size = TeamB_Set;
	std::cout << "there are: " << TeamB_Set << " Units on team A" << std::endl;
	std::cout << "initialising battle" << std::endl;
	std::cout << "["; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "|"; Sleep(100);
	std::cout << "]" << std::endl;
	pause(3);
	std::cout << "battle loaded" << std::endl;
	system("PAUSE");
	//create two teams of Units (two arrays of Units) new Unit[10] and store them on the heap;
	Unit* teamA = new Unit[TeamA_Size];
	int TeamA_DeathCount = 0;

	Unit* teamB = new Unit[TeamB_Size];
	int TeamB_DeathCount = 0;

	time_t start, end;
	time(&start);
	
	while (TeamA_DeathCount < TeamA_Size && TeamB_DeathCount < TeamB_Size)
	{
		
			//TODO select unit of that team randomly use rand() % unitNumber
			if (teamTurn == 1)//COMMENT teamA commands
			{
				int RandIndex = rand() % TeamA_Size;
				teamA[RandIndex];
				std::cout << "the attacking team (A) unit chosen was unit number:" << RandIndex << std::endl;
				//TODO select unit of other team randomly to attack
				if (teamA[RandIndex].GetIsAlive() == true) //COMMENT attacking unit
				{
					int RandIndex2 = rand() % TeamB_Size;
					teamB[RandIndex2];
					std::cout << "the Defending team (B) unit chosen was unit number:" << RandIndex2 << std::endl;

					if (teamB[RandIndex2].GetIsAlive() == true) //COMMENT Defending unit
					{
						//COMMENT reduce other unit's health by your unit's attack (and also adjust defense)
						std::cout << "the defending Unit on Team B's health is currently:" << teamB[RandIndex2].GetHealth() << std::endl;
						std::cout << "the defending unit on Team B's defence is currently:" << teamB[RandIndex2].GetDefence() << std::endl;
						int NewHealth = teamB[RandIndex2].GetHealth() - (teamA[RandIndex].GetAttack() - teamB[RandIndex2].GetDefence());
						teamB[RandIndex2].SetHealth(NewHealth);
						teamB[RandIndex2].SetDefence(teamB[RandIndex2].GetDefence() - 1);
						std::cout << "the defending unit on Team B's health is now:" << teamB[RandIndex2].GetHealth() << std::endl;
						std::cout << "the defending unit on Team B's defence is now:" << teamB[RandIndex2].GetDefence() << std::endl;
						if (teamB[RandIndex2].GetHealth() <= 0)
						{
							teamB[RandIndex2].SetHealth(0);
							teamB[RandIndex2].SetIsAlive(false);
							TeamB_DeathCount = TeamB_DeathCount + 1;
							std::cout << "deaths on Team B:" << TeamB_DeathCount << std::endl;
						}
						// COMMENT once turn has finnished, switch attacking and defending teams over.
						if (teamTurn == 1)
						{
							std::cout << "DEBUG: TEAM A TURN OVER" << std::endl;
							teamTurn = 2;
							std::cout << "DEBUG: TEAM B TURN BEGIN" << std::endl;
						}
						else if (teamTurn == 2)
						{
							std::cout << "DEBUG: TEAM B TURN OVER" << std::endl;
							teamTurn = 1;
							std::cout << "DEBUG: TEAM A TURN BEGIN" << std::endl;
						}
					}

					else if (teamB[RandIndex].GetIsAlive() == false) //COMMENT defending unit is dead
					{
						std::cout << "the defending unit, number:" << RandIndex << " on team B is dead, picking another unit" << std::endl;
					}
					if (teamB[RandIndex2].GetHealth() <= 0)
					{
						teamB[RandIndex2].SetHealth(0);
						teamB[RandIndex2].SetIsAlive(false);

					}
				}
				else if (teamA[RandIndex].GetIsAlive() == false)		//COMMENT is false, pick another unit on team
				{
					std::cout << "the attacking unit, number:" << RandIndex << " on team A is dead, picking another unit" << std::endl;
				}
			}
			else if (teamTurn == 2)//COMMENT teamB commands
			{
				int RandIndex = rand() % TeamB_Size;
				teamB[RandIndex];
				std::cout << "the attacking team (B) unit chosen was unit number:" << RandIndex << std::endl;
				//TODO select unit of other team randomly to attack
				if (teamB[RandIndex].GetIsAlive() == true) //COMMENT attacking unit
				{
					int RandIndex2 = rand() % TeamA_Size;
					teamA[RandIndex2];
					std::cout << "the Defending team (A) unit chosen was unit number:" << RandIndex2 << std::endl;

					if (teamA[RandIndex2].GetIsAlive() == true) //COMMENT Defending unit
					{
						std::cout << "the defending unit on Team A's health is Currently:" << teamA[RandIndex2].GetHealth() << std::endl;//COMMENT reduce other unit's health by your unit's attack (and also adjust defense)
						std::cout << "the defending unit on Team A's defence is currently:" << teamA[RandIndex2].GetDefence() << std::endl;
						int NewHealth2 = teamA[RandIndex2].GetHealth() - (teamB[RandIndex].GetAttack() - teamA[RandIndex2].GetDefence());
						teamA[RandIndex2].SetHealth(NewHealth2);
						teamA[RandIndex2].SetDefence(teamA[RandIndex2].GetDefence() - 1);
						std::cout << "the defending unit on Team A's health is now:" << teamA[RandIndex2].GetHealth() << std::endl;
						std::cout << "the defending unit on Team A's defence is now:" << teamA[RandIndex2].GetDefence() << std::endl;
						if (teamA[RandIndex2].GetHealth() <= 0)
						{
							teamA[RandIndex2].SetHealth(0);
							teamA[RandIndex2].SetIsAlive(false);
							TeamA_DeathCount = TeamA_DeathCount + 1;
							std::cout << "deaths on Team A:" << TeamA_DeathCount << std::endl;
						}
						// COMMENT once turn has finnished, switch attacking and defending teams over.
						if (teamTurn == 1)
						{
							std::cout << "DEBUG TEAM A TURN OVER" << std::endl;
							teamTurn = 2;
							std::cout << "DEBUG TEAM B TURN BEGIN" << std::endl;
						}
						else if (teamTurn == 2)
						{
							std::cout << "DEBUG TEAM B TURN OVER" << std::endl;
							teamTurn = 1;
							std::cout << "DEBUG TEAM A TURN BEGIN" << std::endl;
						}
					}

					else if (teamA[RandIndex].GetIsAlive() == false) //COMMENT defending unit is dead
					{
						std::cout << "the defending unit, number:" << RandIndex << " on team A is dead, picking another unit" << std::endl;
					}
				if (teamA[RandIndex2].GetHealth() <= 0)
				{
					teamA[RandIndex2].SetHealth(0);
					teamA[RandIndex2].SetIsAlive(false);
				}
			}
			else if (teamB[RandIndex].GetIsAlive() == false)		//COMMENT is false, pick another unit on team
			{
				std::cout << "the attacking unit, number:" << RandIndex << " on tean B is dead, picking another unit" << std::endl;
			}
		}
	}	//TODO sort through all team members and display them in order of highest health
	
	if (TeamA_DeathCount == TeamA_Size)
	{
		time(&end);
		double dif = difftime(end, start);
		printf("Battle Took %.2lf seconds.", dif);
		std::cout << std::endl;
		//colapse for win code
		{ 
			std::cout << "team B wins" << std::endl;
			system("PAUSE");
			std::cout << "displaying results" << std::endl;
			//int* values = new int[size];
			//Unit* teamB = new Unit[10];
			for (int i = 0; i < TeamB_Size; i++)
			{
				teamB[i].SetOriginal(i);
				//Unit 1 in array position 0
				std::cout << "Unit " << i << "'s health is: " << teamB[i].GetHealth();
				if (teamB[i].GetHealth() <= 0)
				{
					std::cout << " , " << "Unit " << i << " is Dead" << std::endl;
				}
				else if (teamB[i].GetHealth() > 0)
				{
					std::cout << std::endl;
				}
			}
			std::cout << "Press any button to sort in order of health" << std::endl;
			std::cout << "sorting";
			pause(1);
			std::cout << ".";
			pause(1);
			std::cout << ".";
			pause(1);
			std::cout << "." << std::endl;
			pause(1);
		}
	
		//bubble sort
		bool swapped = true;
		while (swapped)
		{
			swapped = false;
			for (int index = 0; index < TeamB_Size - 1; index++)
			{
				if (teamB[index].GetHealth() < teamB[index + 1].GetHealth())
				{
					Unit swapHolder;
					swapHolder = teamB[index];
					teamB[index] = teamB[index + 1];
					teamB[index + 1] = swapHolder;
					swapped = true;
				}
			}
		}
		for (int i = 0; i < TeamB_Size; i++)
		{
			std::cout << "Unit health is: " << teamB[i].GetHealth() << " , " << ". Units original placement was: " << teamB[i].GetOriginal() << std::endl;
		}

		
				//std::cout << "an error occured whilst sorting..." << std::endl;
				system("PAUSE");
		delete[] teamA;
		delete[] teamB;
};
	if (TeamB_DeathCount == TeamB_Size)
	{
		time(&end);
		double dif = difftime(end, start);
		printf("Battle took %.2lf seconds.", dif);
		std::cout << std::endl;
		std::cout << "team A wins" << std::endl;
		system("PAUSE");
		std::cout << "displaying results" << std::endl;
		//int* values = new int[size];
		//Unit* teamB = new Unit[10];

		for (int i = 0; i < TeamA_Size; i++)
		{
			teamA[i].SetOriginal(i);
			//Unit 1 in array position 0
			std::cout << "Unit " << i << "'s health is: " << teamA[i].GetHealth();
			if (teamA[i].GetHealth() <= 0)
			{
				std::cout << " , " << "Unit " << i << " is Dead" << std::endl;
			}
			else if (teamA[i].GetHealth() > 0)
			{
				std::cout << std::endl;
			}
		}
		std::cout << "Press any button to sort in order of health" << std::endl;
		std::cout << "sorting";
		pause(1);
		std::cout << ".";
		pause(1);
		std::cout << ".";
		pause(1);
		std::cout << "." << std::endl;
		pause(1);

		bool swapped = true;
		while (swapped)
		{
			swapped = false;
			for (int index = 0; index < TeamA_Size - 1; index++)
			{
				if (teamA[index].GetHealth() < teamA[index + 1].GetHealth())
				{
					Unit swapHolder;
					swapHolder = teamA[index];
					teamA[index] = teamA[index + 1];
					teamA[index + 1] = swapHolder;
					swapped = true;
				}
			}
		}
		for (int i = 0; i < TeamA_Size; i++)
		{
			std::cout << "Unit health is: " << teamA[i].GetHealth() << " , " << ". Units original placement was: " << teamA[i].GetOriginal() << std::endl;
		}
		system("PAUSE");
		delete[] teamA;
		delete[] teamB;
	}

}


