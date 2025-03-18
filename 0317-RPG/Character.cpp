#include "Character.h"

Character::Character(string n, int l, int h, int a)
	: name(n), level(l), health(h), maxhealth(h), attackPower(a) {}

string Character::getName() {
	return name;
}

void Character::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

bool Character::isAlive() {
	// 살아있다면 true, 아니면 false;
	return health > 0;
}

void Character::showStatus() {
	cout << name << " (Lv." << level << ") - HP: " << health << endl;
}

void Character::levelUp() {
	cout << name << "가(이) 레벨업!" << endl;
	level++;
}

void Character::resetHealth() {
	health = maxhealth;
}