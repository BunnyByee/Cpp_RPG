#pragma once
#include "Character.h"

class Mage : public Character {
private:
	int mana;
	int maxMana;
public:
	// 생성자
	Mage(string name) :
		Character(name, 1, 80, 18), mana(100), maxMana(100) {}

	// 오버로드
	void showStatus() override;

	// 오버라이딩
	void attack(Character& target) override;
	void specialAttack(Character& target) override;

	void resetMana();
}; 
