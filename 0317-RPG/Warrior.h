#pragma once
#include "Character.h"

class Warrior : public Character{
public:
	// ������
	Warrior(string name) : Character(name, 1, 100, 15) {}

	// �������̵�
	void attack(Character& target) override;
	void specialAttack(Character& target) override;
};
