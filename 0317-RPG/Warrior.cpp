#include "Warrior.h"

void Warrior::attack(Character& target) {
	// ���濡�� ���ݷ¸�ŭ ����
	cout << name << "��(��) " << target.getName() << "��(��) ����!" << endl;
	target.takeDamage(attackPower);
}

void Warrior::specialAttack(Character& target) {
	// ���濡�� ���ݷ� �ι� ����
	cout << name << "��(��) " << target.getName() << "���� ������ �ϰ��� �����ϴ�!" << endl;
	target.takeDamage(attackPower * 2);
	takeDamage(5);
}