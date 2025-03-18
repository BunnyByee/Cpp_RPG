#include "BattleManager.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"

// ����� ���� �Լ� ����
unique_ptr<Character> chooseCharacter(const string& prompt) {
	int choice;
	cout << prompt << endl;
	cout << "1. ����(Warrior)" << endl;
	cout << "2. ������(Mage)" << endl;
	cout << "3. ����(Rogue)" << endl;
	cout << "����: ";
	cin >> choice;

	switch (choice) {
	case 1:
		return make_unique<Warrior>("����");
	case 2:
		return make_unique<Mage>("������");
	case 3:
		return make_unique<Rogue>("����");
	default:
		cout << "������ �߸��ϼ̽��ϴ�. ����� �����մϴ�." << endl;
		return make_unique<Warrior>("����");
	}
}

int main() {
	cout << "RPG �����ϱ�!" << endl;
	// ����ڰ� �ڽ��� ĳ���� ����
	unique_ptr<Character> player = chooseCharacter("����� ĳ���͸� �������ּ���: ");

	while (true) {
		// ����ڰ� ��� ĳ���� ����
		unique_ptr<Character> enemy = chooseCharacter("��� ĳ���͸� �������ּ���: ");
		BattleManager::startBattle(player, enemy);

		// �й� �� ���� ����
		if (!player->isAlive()) {
			cout << "������ �����մϴ�" << endl;
			break;
		}

		// �÷��̾ �¸��ϸ� ���ο� ���� �����Ͽ� ���� ���� ����
		char choice;
		cout << "�¸��Ͽ����ϴ�! ������ ����ұ��? (y/n): ";
		cin >> choice;

		if (choice == 'n') {
			cout << "������ �����մϴ�" << endl;
			break;
		}
		
		player->levelUp();
		player->resetHealth();

		// ������� ���� ����!
		Mage* magePtr = dynamic_cast<Mage*>(player.get());
		if (magePtr) {
			magePtr->resetMana();
		}

	}
}