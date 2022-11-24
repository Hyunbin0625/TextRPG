#include "stdafx.h"
#include "Forge.h"

Forge::Forge(Player* player)
{
	Reinforce reinforce = Reinforce::Armor;

	bool forge = 1;
	while (forge)
	{
		cout << "=================== 대장간 ===================\n\n";

		cout << "보유 골드 : " << player->GetPlayerGold() << "\n";
		cout << "보유 장비 : 무기 " << player->GetPlayerWeapon() << "강, 갑옷 " << player->GetPlayerArmor() << "강, 신발 " << player->GetPlayerShoes() << "강\n\n";

		cout << "무엇을 하시겠습니까?\n\n";

		cout << "1. 무기 강화(" << 4 + player->GetPlayerWeapon() << "골드) 2. 갑옷 강화(" << 4 + player->GetPlayerArmor() << "골드) 3. 신발 강화(" << 4 + player->GetPlayerShoes() << "골드) 4. 나가기\n";
		cout << "선택 : ";

		scanf("%d", &reinforce);

		switch (reinforce)
		{
		case Reinforce::Weapon:
			if (player->GetPlayerGold() > 4 + player->GetPlayerWeapon())
			{
				player->SetPlayerGold(player->GetPlayerGold() - (4 + player->GetPlayerWeapon()));
				player->SetPlayerWeapon(player->GetPlayerWeapon() + 1);
				cout << "강화 완료!!\n";
				cout << "무기 " << player->GetPlayerWeapon() << " 강\n";
			}
			else
			{
				cout << "\n보유한 골드가 부족합니다.\n";
				Sleep(1000);
			}
			break;
		case Reinforce::Armor:
			if (player->GetPlayerGold() > 4 + player->GetPlayerArmor())
			{
				player->SetPlayerGold(player->GetPlayerGold() - (4 + player->GetPlayerArmor()));
				player->SetPlayerArmor(player->GetPlayerArmor() + 1);
				cout << "강화 완료!!\n";
				cout << "갑옷 " << player->GetPlayerArmor() << " 강\n";
			}
			else
			{
				cout << "\n보유한 골드가 부족합니다.\n";
				Sleep(1000);
			}
			break;
		case Reinforce::Shoes:
			if (player->GetPlayerGold() > 4 + player->GetPlayerShoes())
			{
				player->SetPlayerGold(player->GetPlayerGold() - (4 + player->GetPlayerShoes()));
				player->SetPlayerShoes(player->GetPlayerShoes() + 1);
				player->SetAVOID(player->GetPlayerShoes() * 2);
				cout << "강화 완료!!\n";
				cout << "신발 " << player->GetPlayerShoes() << " 강\n";
			}
			else
			{
				cout << "\n보유한 골드가 부족합니다.\n";
				Sleep(1000);
			}
			break;
		case Reinforce::End:
			system("cls");
			cout << "마을로 돌아가는 중";
			for (int i = 0; i < 3; ++i)
			{
				cout << ". ";
				Sleep(300);
			}
			forge = 0;
			break;
		default:
			cout << "해당 숫자의 행동은 없습니다.\n";
			break;
		}
		system("cls");
	}

	system("cls");
}

Forge::~Forge()
{
}