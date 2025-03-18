#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Character {
protected:
	string name;
	int level;
	int health;
	int maxhealth;
	int attackPower;

public:
	// ������
	Character(string n, int l,  int h, int a);

	// ���� ���� �Լ� ������ ��� ���Ͽ�����.
	virtual void attack(Character& target) = 0;
	virtual void specialAttack(Character& target) = 0;

	string getName();
	void takeDamage(int damage);
	bool isAlive();
	virtual void showStatus();
	void resetHealth();
	void levelUp();

	virtual ~Character() = default;
};
