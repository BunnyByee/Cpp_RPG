#include "BattleManager.h"
#include <random>
#include <chrono>
#include <thread>

void BattleManager::startBattle(unique_ptr<Character>& p1, unique_ptr<Character>& p2) {
	cout << "전투 시작! " << p1->getName() << " vs " << p2->getName() << endl;

	// 난수 생성을 통해 전투의 선공(첫 번째 공격자)을 랜덤으로 결정
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> firstTurn(0, 1);
	uniform_int_distribution<int> attackType(0, 100);

	bool firstAttack = firstTurn(gen);

	// 둘 중 한 캐릭터가 체력이 0이 되면 -> 둘다 살아 있을때까지 반복
	while (p1->isAlive() && p2->isAlive()) {
		// 캐릭터 상태 출력
		p1->showStatus();
		p2->showStatus();
		
		try {
			if (firstAttack) {
				// 기본공격 or 특수공격 (70%확률)
				if (attackType(gen) < 70) p1->attack(*p2);
				else p1->specialAttack(*p2);

				// 전투 진행시 딜레이 추가
				this_thread::sleep_for(chrono::milliseconds(1000));

				// 두번째 캐릭터가 죽으면 종료
				if (!p2->isAlive()) break;

				// 두번째 캐릭터가 살아있으면 반격
				if (attackType(gen) < 70) p2->attack(*p1);
				else p2->specialAttack(*p1);

				this_thread::sleep_for(chrono::milliseconds(1000));
			}
			else {
				// 기본공격 or 특수공격 (70%확률)
				if (attackType(gen) < 70) p2->attack(*p1);
				else p2->specialAttack(*p1);

				// 전투 진행시 딜레이 추가
				this_thread::sleep_for(chrono::milliseconds(1000));

				// 두번째 캐릭터가 죽으면 종료
				if (!p1->isAlive()) break;

				// 두번째 캐릭터가 살아있으면 반격
				if (attackType(gen) < 70) p1->attack(*p2);
				else p1->specialAttack(*p2);

				this_thread::sleep_for(chrono::milliseconds(1000));
			}

		}
		catch (const exception& e) {
			cout << e.what() << endl;
		}

		cout << "-----------------------------" << endl;
	}

	cout << (p1->isAlive() ? p1->getName() : p2->getName()) << "이(가) 승리했습니다." << endl;
}