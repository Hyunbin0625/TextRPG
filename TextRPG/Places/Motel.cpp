#include "stdafx.h"
#include "Motel.h"

Motel::Motel(Player* player)
{
	int motel = 1;
	while (motel)
	{
		cout << "=================== 여관 =================== \n\n";
		cout << "여관에서 쉬겠습니까?(2골드)\n";
		cout << "1. Yes 2. No(나가기)\n";
		cout << "선택 : ";
		int choice = 0;
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			if (player->GetPlayerGold() >= 2)
			{
				player->SetPlayerGold(player->GetPlayerGold() - 2);		// 골드 소비
				system("cls");
				cout << "플레이어의 \n";
				cout << "체력이 " << player->GetPlayerMaxHp() - player->GetHP() << "\n";
				cout << "마나가 " << (player->GetPlayerLevel() * 30) - player->GetPlayerMana() << "\n";
				cout << "만큼 회복되었다.";
				player->SetHP(player->GetPlayerLevel() * 150);			// 체력 회복
				player->SetPlayerMana(player->GetPlayerLevel() * 30);	// 마나 회복
			}
			else
			{
				cout << "\n보유한 골드가 부족합니다.\n";
			}
			Sleep(1200);
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "마을로 돌아가는 중";
			for (int i = 0; i < 3; ++i)
			{
				cout << ". ";
				Sleep(300);
			}
			motel = 0;
			break;
		}
		default:
			cout << "해당 숫자의 행동은 없습니다.\n";
			break;
		}
		system("cls");
	}
}

Motel::~Motel()
{
}
