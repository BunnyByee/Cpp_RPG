#pragma once
#include "Character.h"
#include <random>

class Rogue : public Character {
public:
	// ������
	Rogue(string name) :
		Character(name, 1, 90, 15) {
	}

	// �������̵�
	void attack(Character& target) override;
	void specialAttack(Character& target) override;
};
