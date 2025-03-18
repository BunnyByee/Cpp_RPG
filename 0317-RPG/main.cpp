#include "BattleManager.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"

// 사용자 선택 함수 구현
unique_ptr<Character> chooseCharacter(const string& prompt) {
	int choice;
	cout << prompt << endl;
	cout << "1. 전사(Warrior)" << endl;
	cout << "2. 마법사(Mage)" << endl;
	cout << "3. 도적(Rogue)" << endl;
	cout << "선택: ";
	cin >> choice;

	switch (choice) {
	case 1:
		return make_unique<Warrior>("전사");
	case 2:
		return make_unique<Mage>("마법사");
	case 3:
		return make_unique<Rogue>("도적");
	default:
		cout << "선택을 잘못하셨습니다. 전사로 진행합니다." << endl;
		return make_unique<Warrior>("전사");
	}
}

int main() {
	cout << "RPG 시작하기!" << endl;
	// 사용자가 자신의 캐릭터 선택
	unique_ptr<Character> player = chooseCharacter("당신의 캐릭터를 선택해주세요: ");

	while (true) {
		// 사용자가 상대 캐릭터 선택
		unique_ptr<Character> enemy = chooseCharacter("상대 캐릭터를 선택해주세요: ");
		BattleManager::startBattle(player, enemy);

		// 패배 시 게임 종료
		if (!player->isAlive()) {
			cout << "게임을 종료합니다" << endl;
			break;
		}

		// 플레이어가 승리하면 새로운 적을 선택하여 전투 진행 가능
		char choice;
		cout << "승리하였습니다! 전투를 계속할까요? (y/n): ";
		cin >> choice;

		if (choice == 'n') {
			cout << "게임을 종료합니다" << endl;
			break;
		}
		
		player->levelUp();
		player->resetHealth();

		// 마법사면 마나 리셋!
		Mage* magePtr = dynamic_cast<Mage*>(player.get());
		if (magePtr) {
			magePtr->resetMana();
		}

	}
}