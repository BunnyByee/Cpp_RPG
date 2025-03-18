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
	// 생성자
	Character(string n, int l,  int h, int a);

	// 순수 가상 함수 선언은 헤더 파일에서만.
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
