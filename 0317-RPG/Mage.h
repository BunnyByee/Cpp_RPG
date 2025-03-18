#pragma once
#include "Character.h"

class Mage : public Character {
private:
	int mana;
	int maxMana;
public:
	// ������
	Mage(string name) :
		Character(name, 1, 80, 18), mana(100), maxMana(100) {}

	// �����ε�
	void showStatus() override;

	// �������̵�
	void attack(Character& target) override;
	void specialAttack(Character& target) override;

	void resetMana();
}; 
