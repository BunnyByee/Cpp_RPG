#include "Warrior.h"

void Warrior::attack(Character& target) {
	// 상대방에게 공격력만큼 공격
	cout << name << "가(이) " << target.getName() << "를(을) 공격!" << endl;
	target.takeDamage(attackPower);
}

void Warrior::specialAttack(Character& target) {
	// 상대방에게 공격력 두배 공격
	cout << name << "가(이) " << target.getName() << "에게 강력한 일격을 날립니다!" << endl;
	target.takeDamage(attackPower * 2);
	takeDamage(5);
}