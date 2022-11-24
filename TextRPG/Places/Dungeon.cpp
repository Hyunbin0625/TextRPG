#include "stdafx.h"
#include "Dungeon.h"

Dungeon::Dungeon(Player* player)
{
	bool dungeon = 1;
	while (dungeon)	// ����
	{
		cout << "========================= ���� " << player->GetDungeonFloor() << "�� ========================\n";
		cout << "������ ������.\n\n";
		turn = 1;

		Monster* monster = new Monster(10, 60 + (player->GetDungeonFloor() * 3), 10 + (player->GetDungeonFloor() * 2), (player->GetDungeonFloor() * 3), (player->GetDungeonFloor() * 1.5));	// id, hp, atk, def, avoid
		//	cout << "monster1 : " << goblin1.GetHP() << ", " << goblin1.GetATK() << endl;	// ���� ����

		srand((unsigned int)time(NULL));
		FightAct fightact = FightAct::Attack;
		Attack attack = Attack::Normal;
		Potion potion = Potion::HpPotion;

		bool Fight = 1;
		while (Fight)	// ����
		{
			int run;
			cout << "=========================== " << turn << "�� ===========================\n\n";
			cout << "�÷��̾� ü�� : " << player->GetHP() << " / " << player->GetPlayerMaxHp() << "\n";		// �� ü�� �ӽ�
			cout << "�÷��̾� ���� : " << player->GetPlayerMana() << " / " << player->GetPlayerMaxMana() << "\n\n";	// �� ���� �ӽ�
			cout << "������ �Ͻðڽ��ϱ�?\n\n";
			cout << "1. ���� 2. ���� 3. ���� ��� 4. �����\n\n�ൿ ���� : ";
			scanf("%d", &fightact);

			switch (fightact)
			{
			case FightAct::Attack:
				cout << "1. �Ϲ� ���� 2. ��ų ���\n==> ";
				scanf("%d", &attack);
				switch (attack)
				{
				case Attack::Normal:
					player->PlayerAttack(monster);
					break;
				case Attack::Skill:
					player->SkillBeginnerSword(monster);
					break;
				default:
					cout << "�ش� ������ �ൿ�� �����ϴ�.\n";
					break;
				}
				break;
			case FightAct::Escape:
				// Ȯ������
				run = rand() % 100;
				if (run < 60)	// ���� 60��? Ȯ���� ����
				{
					cout << "���Ϳ��Լ� �����ƴ�!\n";
					Fight = 0;
					dungeon = 0;
				}
				else
				{
					cout << "\n���Ϳ��Լ� ����ġ�� ���ߴ�!\n\n";
					Sleep(1000);
					monster->MonsterAttack(player);
					Sleep(1500);
				}
				break;
			case FightAct::Potion:
				cout << "1. ü������("<< player->GetPlayerHpPotion() << "��) 2. ��������(" << player->GetPlayerManaPotion() <<"��)\n ==> ";
				scanf("%d", &potion);
				switch (potion)
				{
				case Potion::HpPotion:
					if (player->GetPlayerHpPotion() > 0)
					{
						player->SetHP(player->GetHP() + 30);
						player->SetPlayerHpPotion(player->GetPlayerHpPotion() - 1);
						cout << "ü���� 30 ȸ���Ǿ���!\n\n";
					}
					else
						cout << "������ �����ϴ�!\n\n";
					break;
				case Potion::ManaPotion:
					if (player->GetPlayerManaPotion() > 0)
					{
						player->SetPlayerMana(player->GetPlayerMana() + 15);
						player->SetPlayerManaPotion(player->GetPlayerManaPotion() - 1);
						cout << "������ 15 ȸ���Ǿ���!\n\n";
					}
					else
						cout << "������ �����ϴ�!\n\n";
					break;
				default:
					break;
				}
				break;
			case FightAct::Makgora:
				// ���� �Ѹ��� ���������� �Ϲݰ���
				while (1)
				{
					cout << "=========================== " << turn << "�� ===========================\n\n";

					cout << "�÷��̾� ü�� : " << player->GetHP() << " / " << player->GetPlayerMaxHp() << "\n";
					cout << "�÷��̾� ���� : " << player->GetPlayerMana() << " / " << player->GetPlayerLevel() * 30 << "\n\n";
					player->PlayerAttack(monster);
					turn += 1;
					if (monster->GetHP() <= 0)
					{
						break;
					}
					Sleep(1000);
					monster->MonsterAttack(player);
					if (monster->GetHP() <= 0)
					{
						break;
					}
					Sleep(1000);
				}
				break;
			default:
				cout << "�ش� ������ �ൿ�� �����ϴ�.\n";
				break;
			}
			turn += 1;

			Sleep(1500);

			if (monster->GetHP() < 1)	// ������ hp�� 0�̶�� �ο� Ż��
			{
				cout << "���͸� óġ�Ͽ����ϴ�!!\n\n";
				player->SetPlayerGold(player->GetPlayerGold() + (player->GetDungeonFloor() * 4));		// �� ���� ������ ��� ���, ���߿� ���� ������ ����
				cout << "====> " << 4 * player->GetDungeonFloor() << " Gold�� ȹ���߽��ϴ�.\n";
				player->SetPlayerExp(player->GetDungeonFloor() * 5);		// �� ���� ������ ��� ���, ���߿� ���� ������ ����
				cout << "      " << 5 * player->GetDungeonFloor() << " Exp�� ȹ���߽��ϴ�.\n\n";

				if (player->GetPlayerExp() >= player->GetPlayerMaxExp())	// Player Level Up Function
				{
					player->PlayerLevelUp();
					cout << "�÷��̾� Level Up!\nplayerLevel : " << player->GetPlayerLevel() << "\n\n";
				}
				cout << "�÷��̾� ü�� : " << player->GetHP() << " / " << player->GetPlayerLevel() * 150 << "\n";	// �� ü�� �ӽ�(���� �ȸ���)
				cout << "�÷��̾� ���� : " << player->GetPlayerMana() << " / " << player->GetPlayerLevel() * 30 << "\n";
				cout << "�÷��̾� ����ġ : " << player->GetPlayerExp() << " / " << player->GetPlayerLevel() * 20 << "\n\n";
				player->SetDungeonFloor(player->GetDungeonFloor() + 1);		// ���� �÷��� ��

				cout << "���� ������ �̵��Ͻðڽ��ϱ�?\n\n";

				cout << "1. �̵��Ѵ� 2. ������ ���ư���.\n";
				cout << "���� : ";

				int select = 0;
				cin >> select;

				if (select == 1)
				{
					break;														// ���� while �ݺ��� Ż��
				}
				else if (select == 2)
				{
					dungeon = 0;	// while �ݺ����� �̸� false�� ���� ��,
					break;			// ���� while �ݺ����� Ż��
				}
			}
			else	// monster�� ���� �ʾҴٸ� monster�� ������
			{
				if (fightact != FightAct::Escape)
				{
					monster->MonsterAttack(player);
					Sleep(1500);
				}
			}
		}
	}

	// �������� �÷����� �� player�� ���� �ѱ��
	system("cls");
	cout << "������ ���ư��� ��";	// �׳� �غô�.
	for (int i = 0; i < 3; ++i)
	{
		cout << ". ";
		Sleep(300);
	}

	system("cls");
}

Dungeon::~Dungeon()
{
}