#pragma once
#include "Character.h"
#include <random>

class Rogue : public Character {
public:
	// 생성자
	Rogue(string name) :
		Character(name, 1, 90, 15) {
	}

	// 오버라이딩
	void attack(Character& target) override;
	void specialAttack(Character& target) override;
};
