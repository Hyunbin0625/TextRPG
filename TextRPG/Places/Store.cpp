#include "stdafx.h"
#include "stdafx.h"

Store::Store(Player* player)
{
	bool store = 1;
	Potion potion = Potion::HpPotion;
	while (store)
	{
		cout << "=================== 잡화점 ===================\n\n";

		cout << "보유 골드 : " << player->GetPlayerGold() << "\n";
		cout << "보유 아이템 : 체력포션 " << player->GetPlayerHpPotion() << "개, 마나포션 " << player->GetPlayerManaPotion() << "개, 부활석 " << player->GetPlayerReviveStone() << "개\n\n";

		cout << "무엇을 하시겠습니까?\n\n";
		cout << "1. 체력포션 구매(3골드) 2. 마나포션 구매(2골드) 3. 부활석 구매(10골드) 4. 나가기\n";
		cout << "선택 : ";
		scanf("%d", &potion);
		switch (potion)
		{
		case Potion::HpPotion:
			if (player->GetPlayerGold() >= 3)
			{
				player->SetPlayerHpPotion(player->GetPlayerHpPotion() + 1);
				player->SetPlayerGold( player->GetPlayerGold() -3);
			}
			else
			{
				cout << "\n보유한 골드가 부족합니다.\n";
				Sleep(1000);
			}
			break;
		case Potion::ManaPotion:
			if (player->GetPlayerGold() >= 2)
			{
				player->SetPlayerManaPotion(player->GetPlayerManaPotion() + 1);
				player->SetPlayerGold(player->GetPlayerGold() - 2);
			}
			else
			{
				cout << "\n보유한 골드가 부족합니다.\n";
				Sleep(1000);
			}
			break;
		case Potion::ReviveStone:
			if (player->GetPlayerGold() >= 10)
			{
				if (player->GetPlayerReviveStone() < 3)
				{
					player->SetPlayerReviveStone(player->GetPlayerReviveStone() + 1);
					player->SetPlayerGold(player->GetPlayerGold() - 10);
				}
				else
				{
					cout << "\n최대 구매수량은 3개입니다!\n\n";
					Sleep(1000);
					system("cls");
				}
			}
			else
			{
				cout << "\n보유한 골드가 부족합니다.\n";
				Sleep(1000);
			}
			break;
		case Potion::End:
			system("cls");
			cout << "마을로 돌아가는 중";
			for (int i = 0; i < 3; ++i)
			{
				cout << ". ";
				Sleep(500);
			}
			store = 0;
			break;
		default:
			break;
		}

		system("cls");
	}
}

Store::~Store()
{
}
