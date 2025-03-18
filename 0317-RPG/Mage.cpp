#include "Mage.h"

void Mage::showStatus() {
	cout << name << " (Lv." << level << ") - HP: " << health << " MP: " << mana << endl;
}

void Mage::resetMana() {
	mana = maxMana;
}

void Mage::attack(Character& target) {
	cout << name << "��(��) " << target.getName() << "��(��) ����!" << endl;
	target.takeDamage(attackPower);
}

void Mage::specialAttack(Character& target) {
	// ������ �������� �ʴٸ�, 20�� �Ҹ��ϰ� 1.5�� ����
	if (mana < 20) throw runtime_error("������ �����մϴ�!");
	else {
		cout << name << "��(��) " << target.getName() << "���� ���̾�� �����ϴ�!" << endl;
		mana -= 20;
		target.takeDamage(attackPower * 1.5);
	}
}

