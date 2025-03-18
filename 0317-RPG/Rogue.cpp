#include "Rogue.h"

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist(0, 100);

void Rogue::attack(Character& target) {
	cout << name << "가(이) 빠르게 " << target.getName() << "를(을) 공격!" << endl;
	target.takeDamage(attackPower);
}
void Rogue::specialAttack(Character& target) {
	int chance = dist(gen);

	//  난수 생성 후 70% 이상이면 공격력의 3배를 데미지로!
	if (chance < 30) {
		cout << name << "가(이) 급습에 실패 ㅠㅠ" << endl;
	}
	else {
		cout << name << "가(이) " << target.getName() << "급습에 성공!" << endl;
		target.takeDamage(attackPower * 3);
	}
}