#include "stdafx.h"
#include "Dungeon.h"

Dungeon::Dungeon(Player* player)
{
	bool dungeon = 1;
	while (dungeon)	// ����
	{
		cout << "========================= ���� " << player->GetDungeonFloor() << "�� ========================\n";
		cout << "������ ������.\n";
		turn = 1;

		Monster* monster = new Monster(10, 60 + (player->GetDungeonFloor() * 3), 10 + (player->GetDungeonFloor() * 2), (player->GetDungeonFloor() * 3), (player->GetDungeonFloor() * 1.5));	// id, hp, atk, def, avoid
		//	cout << "monster1 : " << goblin1.GetHP() << ", " << goblin1.GetATK() << endl;	// ���� ����

		srand((unsigned int)time(NULL));

		random_device random;
		mt19937 engine(random());
		uniform_int_distribution<int> uniform(0, 99);

		FightAct fightact = FightAct::Attack;
		Attack attack = Attack::Normal;
		Potion potion = Potion::HpPotion;

		bool Fight = 1;
		while (Fight)	// ����
		{
			int run;
			cout << "\n=========================== " << turn << "�� ===========================\n\n";
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
					if (uniform(engine) <= monster->GetAVOID())
					{
						cout << "\n===================== �÷��̾��� ���� =====================\n\n";
						cout << "���Ͱ� ȸ���ߴ�!\n\n";
					}
					else
					{
						player->PlayerAttack(monster);
					}
					break;
				case Attack::Skill:
					if (uniform(engine) <= monster->GetAVOID())
					{
						cout << "\n===================== �÷��̾��� ���� =====================\n\n";
						cout << "���Ͱ� ȸ���ߴ�!\n\n";
					}
					else
					{
						player->SkillBeginnerSword(monster);
					}
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

					if (uniform(engine) <= monster->GetAVOID())
					{
						cout << "\n===================== �÷��̾��� ���� =====================\n\n";
						cout << "���Ͱ� ȸ���ߴ�!\n\n";
					}
					else
					{
						player->PlayerAttack(monster);
					}

					turn += 1;
					
					if (monster->GetHP() <= 0)
					{
						break;
					}
					Sleep(1000);

					if (uniform(engine) <= player->GetAVOID())
					{
						cout << "====================== ������ ���� ======================\n\n";
						cout << "�÷��̾ ȸ���ߴ�!\n\n";
					}
					else
					{
						monster->MonsterAttack(player);
					}

					if (player->GetHP() < 1)
					{
						system("cls");
						cout << "�÷��̾� HP : 0\n";
						cout << "��Ȱ�� : " << player->GetPlayerReviveStone() << "��\n";

						cout << "1. ��Ȱ�� ��� 2. ���� ����\n";
						cout << "���� : ";
						int select = 0;
						cin >> select;

						if (select == 1 && player->GetPlayerReviveStone() > 0)
						{
							cout << "��Ȱ�� 1���� ����Ͽ�\n";
							player->SetPlayerReviveStone(player->GetPlayerReviveStone() - 1);
							player->SetHP(player->GetPlayerLevel() * 150);
							cout << "�÷��̾� ��Ȱ �� ü���� ȸ���Ǿ���.\n";
						}
						else
						{
							Fight = 0;
							dungeon = 0;
						}
					}
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
					if (uniform(engine) <= player->GetAVOID())
					{
						cout << "====================== ������ ���� ======================\n\n";
						cout << "�÷��̾ ȸ���ߴ�!\n\n";
					}
					else
					{
						monster->MonsterAttack(player);
					}
					Sleep(1500);
				}
			}
			if (player->GetHP() < 1)
			{
				system("cls");
				cout << "�÷��̾� HP : 0\n";
				cout << "��Ȱ�� : " << player->GetPlayerReviveStone() << "��\n";

				cout << "1. ��Ȱ�� ��� 2. ���� ����\n";
				cout << "���� : ";
				int select = 0;
				cin >> select;

				if (select == 1 && player->GetPlayerReviveStone() > 0)
				{
					cout << "��Ȱ�� 1���� ����Ͽ�\n";
					player->SetPlayerReviveStone(player->GetPlayerReviveStone() - 1);
					player->SetHP(player->GetPlayerLevel() * 150);
					cout << "�÷��̾� ��Ȱ �� ü���� ȸ���Ǿ���.\n";
				}
				else if (select == 2)
				{
					cout << "������ �����մϴ�.\n";
					return;
				}
				else
				{
					cout << "��Ȱ���� �����մϴ�!!\n";
					cout << "������ �����մϴ�.\n";
					return;
				}
				
			}
		}
		system("cls");
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