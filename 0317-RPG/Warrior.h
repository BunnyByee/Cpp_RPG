#pragma once
#include "Character.h"

class Warrior : public Character{
public:
	// 생성자
	Warrior(string name) : Character(name, 1, 100, 15) {}

	// 오버라이딩
	void attack(Character& target) override;
	void specialAttack(Character& target) override;
};
