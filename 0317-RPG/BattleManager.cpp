#include "BattleManager.h"
#include <random>
#include <chrono>
#include <thread>

void BattleManager::startBattle(unique_ptr<Character>& p1, unique_ptr<Character>& p2) {
	cout << "���� ����! " << p1->getName() << " vs " << p2->getName() << endl;

	// ���� ������ ���� ������ ����(ù ��° ������)�� �������� ����
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> firstTurn(0, 1);
	uniform_int_distribution<int> attackType(0, 100);

	bool firstAttack = firstTurn(gen);

	// �� �� �� ĳ���Ͱ� ü���� 0�� �Ǹ� -> �Ѵ� ��� ���������� �ݺ�
	while (p1->isAlive() && p2->isAlive()) {
		// ĳ���� ���� ���
		p1->showStatus();
		p2->showStatus();
		
		try {
			if (firstAttack) {
				// �⺻���� or Ư������ (70%Ȯ��)
				if (attackType(gen) < 70) p1->attack(*p2);
				else p1->specialAttack(*p2);

				// ���� ����� ������ �߰�
				this_thread::sleep_for(chrono::milliseconds(1000));

				// �ι�° ĳ���Ͱ� ������ ����
				if (!p2->isAlive()) break;

				// �ι�° ĳ���Ͱ� ��������� �ݰ�
				if (attackType(gen) < 70) p2->attack(*p1);
				else p2->specialAttack(*p1);

				this_thread::sleep_for(chrono::milliseconds(1000));
			}
			else {
				// �⺻���� or Ư������ (70%Ȯ��)
				if (attackType(gen) < 70) p2->attack(*p1);
				else p2->specialAttack(*p1);

				// ���� ����� ������ �߰�
				this_thread::sleep_for(chrono::milliseconds(1000));

				// �ι�° ĳ���Ͱ� ������ ����
				if (!p1->isAlive()) break;

				// �ι�° ĳ���Ͱ� ��������� �ݰ�
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

	cout << (p1->isAlive() ? p1->getName() : p2->getName()) << "��(��) �¸��߽��ϴ�." << endl;
}