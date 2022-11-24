#include "stdafx.h"
#include "Forge.h"

Forge::Forge(Player* player)
{
	Reinforce reinforce = Reinforce::Armor;

	bool forge = 1;
	while (forge)
	{
		cout << "=================== ���尣 ===================\n\n";

		cout << "���� ��� : " << player->GetPlayerGold() << "\n";
		cout << "���� ��� : ���� " << player->GetPlayerWeapon() << "��, ���� " << player->GetPlayerArmor() << "��, �Ź� " << player->GetPlayerShoes() << "��\n\n";

		cout << "������ �Ͻðڽ��ϱ�?\n\n";

		cout << "1. ���� ��ȭ(" << 4 + player->GetPlayerWeapon() << "���) 2. ���� ��ȭ(" << 4 + player->GetPlayerArmor() << "���) 3. �Ź� ��ȭ(" << 4 + player->GetPlayerShoes() << "���) 4. ������\n";
		cout << "���� : ";

		scanf("%d", &reinforce);

		switch (reinforce)
		{
		case Reinforce::Weapon:
			if (player->GetPlayerGold() > 4 + player->GetPlayerWeapon())
			{
				player->SetPlayerGold(player->GetPlayerGold() - (4 + player->GetPlayerWeapon()));
				player->SetPlayerWeapon(player->GetPlayerWeapon() + 1);
				cout << "��ȭ �Ϸ�!!\n";
				cout << "���� " << player->GetPlayerWeapon() << " ��\n";
			}
			else
			{
				cout << "\n������ ��尡 �����մϴ�.\n";
				Sleep(1000);
			}
			break;
		case Reinforce::Armor:
			if (player->GetPlayerGold() > 4 + player->GetPlayerArmor())
			{
				player->SetPlayerGold(player->GetPlayerGold() - (4 + player->GetPlayerArmor()));
				player->SetPlayerArmor(player->GetPlayerArmor() + 1);
				cout << "��ȭ �Ϸ�!!\n";
				cout << "���� " << player->GetPlayerArmor() << " ��\n";
			}
			else
			{
				cout << "\n������ ��尡 �����մϴ�.\n";
				Sleep(1000);
			}
			break;
		case Reinforce::Shoes:
			if (player->GetPlayerGold() > 4 + player->GetPlayerShoes())
			{
				player->SetPlayerGold(player->GetPlayerGold() - (4 + player->GetPlayerShoes()));
				player->SetPlayerShoes(player->GetPlayerShoes() + 1);
				player->SetAVOID(player->GetPlayerShoes() * 2);
				cout << "��ȭ �Ϸ�!!\n";
				cout << "�Ź� " << player->GetPlayerShoes() << " ��\n";
			}
			else
			{
				cout << "\n������ ��尡 �����մϴ�.\n";
				Sleep(1000);
			}
			break;
		case Reinforce::End:
			system("cls");
			cout << "������ ���ư��� ��";
			for (int i = 0; i < 3; ++i)
			{
				cout << ". ";
				Sleep(300);
			}
			forge = 0;
			break;
		default:
			cout << "�ش� ������ �ൿ�� �����ϴ�.\n";
			break;
		}
		system("cls");
	}

	system("cls");
}

Forge::~Forge()
{
}