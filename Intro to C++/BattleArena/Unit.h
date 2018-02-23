#pragma once

class Unit
{
public:
	Unit();
	~Unit();

	void SetHealth(int value);
	int GetHealth();

	void SetAttack(int value);
	int GetAttack();

	void SetDefence(int value);
	int GetDefence();

	void SetIsAlive(bool status);
	int GetIsAlive();

	void SetOriginal(int value);
	int GetOriginal();

private:
	int Health;
	int Attack; 
	int Defence; 
	bool isAlive;
	int Original;
};

