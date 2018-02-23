#include "Unit.h"
#include <time.h>
#include <chrono>

//default constructor
Unit::Unit()
{
	Health = 100;
	Attack = 15;
	Defence = 5;
	isAlive = true;
	Original = 0;
}

Unit::~Unit()
{

}

void Unit::SetHealth(int value)
{
	Health = value;
}

int Unit::GetHealth()
{
	return Health;
}

void Unit::SetAttack(int value)
{
	Attack = value;
}

int Unit::GetAttack()
{
	return Attack;
}


void Unit::SetDefence(int value)
{
	Defence = value;
}

int Unit::GetDefence()
{
	return Defence;
}


void Unit::SetIsAlive(bool status)
{
	isAlive = status;
}

int Unit::GetIsAlive()
{
	return isAlive;
}

void Unit::SetOriginal(int value)
{
	Original = value;
}

int Unit::GetOriginal()
{
	return Original;
}

