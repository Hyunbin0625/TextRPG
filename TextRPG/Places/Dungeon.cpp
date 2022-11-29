#include "stdafx.h"
#include "Dungeon.h"

Dungeon::Dungeon(Player* player)
{
	bool dungeon = 1;
	while (dungeon)	// 던전
	{
		cout << "========================= 던전 " << player->GetDungeonFloor() << "층 ========================\n";
		cout << "몬스터을 만났다.\n";
		turn = 1;

		Monster* monster = new Monster(10, 60 + (player->GetDungeonFloor() * 3), 10 + (player->GetDungeonFloor() * 2), (player->GetDungeonFloor() * 3), (player->GetDungeonFloor() * 1.5));	// id, hp, atk, def, avoid
		//	cout << "monster1 : " << goblin1.GetHP() << ", " << goblin1.GetATK() << endl;	// 몬스터 정보

		srand((unsigned int)time(NULL));

		random_device random;
		mt19937 engine(random());
		uniform_int_distribution<int> uniform(0, 99);

		FightAct fightact = FightAct::Attack;
		Attack attack = Attack::Normal;
		Potion potion = Potion::HpPotion;

		bool Fight = 1;
		while (Fight)	// 몬스터
		{
			int run;
			cout << "\n=========================== " << turn << "턴 ===========================\n\n";
			cout << "플레이어 체력 : " << player->GetHP() << " / " << player->GetPlayerMaxHp() << "\n";		// 총 체력 임시
			cout << "플레이어 마나 : " << player->GetPlayerMana() << " / " << player->GetPlayerMaxMana() << "\n\n";	// 총 마나 임시
			cout << "무엇을 하시겠습니까?\n\n";
			cout << "1. 공격 2. 도망 3. 물약 사용 4. 막고라\n\n행동 선택 : ";
			scanf("%d", &fightact);

			switch (fightact)
			{
			case FightAct::Attack:
				cout << "1. 일반 공격 2. 스킬 사용\n==> ";
				scanf("%d", &attack);
				switch (attack)
				{
				case Attack::Normal:
					if (uniform(engine) <= monster->GetAVOID())
					{
						cout << "\n===================== 플레이어의 공격 =====================\n\n";
						cout << "몬스터가 회피했다!\n\n";
					}
					else
					{
						player->PlayerAttack(monster);
					}
					break;
				case Attack::Skill:
					if (uniform(engine) <= monster->GetAVOID())
					{
						cout << "\n===================== 플레이어의 공격 =====================\n\n";
						cout << "몬스터가 회피했다!\n\n";
					}
					else
					{
						player->SkillBeginnerSword(monster);
					}
					break;
				default:
					cout << "해당 숫자의 행동은 없습니다.\n";
					break;
				}
				break;
			case FightAct::Escape:
				// 확률있음
				run = rand() % 100;
				if (run < 60)	// 대충 60퍼? 확률로 도망
				{
					cout << "몬스터에게서 도망쳤다!\n";
					Fight = 0;
					dungeon = 0;
				}
				else
				{
					cout << "\n몬스터에게서 도망치지 못했다!\n\n";
					Sleep(1000);
					monster->MonsterAttack(player);
					Sleep(1500);
				}
				break;
			case FightAct::Potion:
				cout << "1. 체력포션("<< player->GetPlayerHpPotion() << "개) 2. 마나포션(" << player->GetPlayerManaPotion() <<"개)\n ==> ";
				scanf("%d", &potion);
				switch (potion)
				{
				case Potion::HpPotion:
					if (player->GetPlayerHpPotion() > 0)
					{
						player->SetHP(player->GetHP() + 30);
						player->SetPlayerHpPotion(player->GetPlayerHpPotion() - 1);
						cout << "체력이 30 회복되었다!\n\n";
					}
					else
						cout << "포션이 없습니다!\n\n";
					break;
				case Potion::ManaPotion:
					if (player->GetPlayerManaPotion() > 0)
					{
						player->SetPlayerMana(player->GetPlayerMana() + 15);
						player->SetPlayerManaPotion(player->GetPlayerManaPotion() - 1);
						cout << "마나가 15 회복되었다!\n\n";
					}
					else
						cout << "포션이 없습니다!\n\n";
					break;
				default:
					break;
				}
				break;
			case FightAct::Makgora:
				// 둘중 한명이 죽을때까지 일반공격
				while (1)
				{
					cout << "=========================== " << turn << "턴 ===========================\n\n";

					cout << "플레이어 체력 : " << player->GetHP() << " / " << player->GetPlayerMaxHp() << "\n";
					cout << "플레이어 마나 : " << player->GetPlayerMana() << " / " << player->GetPlayerLevel() * 30 << "\n\n";

					if (uniform(engine) <= monster->GetAVOID())
					{
						cout << "\n===================== 플레이어의 공격 =====================\n\n";
						cout << "몬스터가 회피했다!\n\n";
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
						cout << "====================== 몬스터의 공격 ======================\n\n";
						cout << "플레이어가 회피했다!\n\n";
					}
					else
					{
						monster->MonsterAttack(player);
					}

					if (player->GetHP() < 1)
					{
						system("cls");
						cout << "플레이어 HP : 0\n";
						cout << "부활석 : " << player->GetPlayerReviveStone() << "개\n";

						cout << "1. 부활석 사용 2. 게임 종료\n";
						cout << "선택 : ";
						int select = 0;
						cin >> select;

						if (select == 1 && player->GetPlayerReviveStone() > 0)
						{
							cout << "부활석 1개를 사용하여\n";
							player->SetPlayerReviveStone(player->GetPlayerReviveStone() - 1);
							player->SetHP(player->GetPlayerLevel() * 150);
							cout << "플레이어 부활 및 체력이 회복되었다.\n";
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
				cout << "해당 숫자의 행동은 없습니다.\n";
				break;
			}
			turn += 1;

			Sleep(1500);

			if (monster->GetHP() < 1)	// 몬스터의 hp가 0이라면 싸움 탈출
			{
				cout << "몬스터를 처치하였습니다!!\n\n";
				player->SetPlayerGold(player->GetPlayerGold() + (player->GetDungeonFloor() * 4));		// 층 수에 곱해져 골드 드랍, 나중에 범위 지정해 랜덤
				cout << "====> " << 4 * player->GetDungeonFloor() << " Gold를 획득했습니다.\n";
				player->SetPlayerExp(player->GetDungeonFloor() * 5);		// 층 수에 곱해져 골드 드랍, 나중에 범위 지정해 랜덤
				cout << "      " << 5 * player->GetDungeonFloor() << " Exp를 획득했습니다.\n\n";

				if (player->GetPlayerExp() >= player->GetPlayerMaxExp())	// Player Level Up Function
				{
					player->PlayerLevelUp();
					cout << "플레이어 Level Up!\nplayerLevel : " << player->GetPlayerLevel() << "\n\n";
				}
				cout << "플레이어 체력 : " << player->GetHP() << " / " << player->GetPlayerLevel() * 150 << "\n";	// 총 체력 임시(아직 안만듬)
				cout << "플레이어 마나 : " << player->GetPlayerMana() << " / " << player->GetPlayerLevel() * 30 << "\n";
				cout << "플레이어 경험치 : " << player->GetPlayerExp() << " / " << player->GetPlayerLevel() * 20 << "\n\n";
				player->SetDungeonFloor(player->GetDungeonFloor() + 1);		// 층을 올려준 후

				cout << "다음 층으로 이동하시겠습니까?\n\n";

				cout << "1. 이동한다 2. 마을로 돌아간다.\n";
				cout << "선택 : ";

				int select = 0;
				cin >> select;

				if (select == 1)
				{
					break;														// 전투 while 반복문 탈출
				}
				else if (select == 2)
				{
					dungeon = 0;	// while 반복문을 미리 false로 만든 후,
					break;			// 안쪽 while 반복문을 탈출
				}
			}
			else	// monster가 죽지 않았다면 monster의 공격턴
			{
				if (fightact != FightAct::Escape)
				{
					if (uniform(engine) <= player->GetAVOID())
					{
						cout << "====================== 몬스터의 공격 ======================\n\n";
						cout << "플레이어가 회피했다!\n\n";
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
				cout << "플레이어 HP : 0\n";
				cout << "부활석 : " << player->GetPlayerReviveStone() << "개\n";

				cout << "1. 부활석 사용 2. 게임 종료\n";
				cout << "선택 : ";
				int select = 0;
				cin >> select;

				if (select == 1 && player->GetPlayerReviveStone() > 0)
				{
					cout << "부활석 1개를 사용하여\n";
					player->SetPlayerReviveStone(player->GetPlayerReviveStone() - 1);
					player->SetHP(player->GetPlayerLevel() * 150);
					cout << "플레이어 부활 및 체력이 회복되었다.\n";
				}
				else if (select == 2)
				{
					cout << "게임을 종료합니다.\n";
					return;
				}
				else
				{
					cout << "부활석이 부족합니다!!\n";
					cout << "게임을 종료합니다.\n";
					return;
				}
				
			}
		}
		system("cls");
	}

	// 던전에서 플레이한 후 player의 정보 넘기기
	system("cls");
	cout << "마을로 돌아가는 중";	// 그냥 해봤다.
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