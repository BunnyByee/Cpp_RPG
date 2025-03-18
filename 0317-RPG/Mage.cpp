#include "Mage.h"

void Mage::showStatus() {
	cout << name << " (Lv." << level << ") - HP: " << health << " MP: " << mana << endl;
}

void Mage::resetMana() {
	mana = maxMana;
}

void Mage::attack(Character& target) {
	cout << name << "가(이) " << target.getName() << "를(을) 공격!" << endl;
	target.takeDamage(attackPower);
}

void Mage::specialAttack(Character& target) {
	// 마나가 부족하지 않다면, 20을 소모하고 1.5배 공격
	if (mana < 20) throw runtime_error("마나가 부족합니다!");
	else {
		cout << name << "가(이) " << target.getName() << "에게 파이어볼을 날립니다!" << endl;
		mana -= 20;
		target.takeDamage(attackPower * 1.5);
	}
}

