#include "Rogue.h"

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist(0, 100);

void Rogue::attack(Character& target) {
	cout << name << "��(��) ������ " << target.getName() << "��(��) ����!" << endl;
	target.takeDamage(attackPower);
}
void Rogue::specialAttack(Character& target) {
	int chance = dist(gen);

	//  ���� ���� �� 70% �̻��̸� ���ݷ��� 3�踦 ��������!
	if (chance < 30) {
		cout << name << "��(��) �޽��� ���� �Ф�" << endl;
	}
	else {
		cout << name << "��(��) " << target.getName() << "�޽��� ����!" << endl;
		target.takeDamage(attackPower * 3);
	}
}