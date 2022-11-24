#include "stdafx.h"
#include "stdafx.h"

Store::Store(Player* player)
{
	bool store = 1;
	Potion potion = Potion::HpPotion;
	while (store)
	{
		cout << "=================== ��ȭ�� ===================\n\n";

		cout << "���� ��� : " << player->GetPlayerGold() << "\n";
		cout << "���� ������ : ü������ " << player->GetPlayerHpPotion() << "��, �������� " << player->GetPlayerManaPotion() << "��, ��Ȱ�� " << player->GetPlayerReviveStone() << "��\n\n";

		cout << "������ �Ͻðڽ��ϱ�?\n\n";
		cout << "1. ü������ ����(3���) 2. �������� ����(2���) 3. ��Ȱ�� ����(10���) 4. ������\n";
		cout << "���� : ";
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
				cout << "\n������ ��尡 �����մϴ�.\n";
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
				cout << "\n������ ��尡 �����մϴ�.\n";
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
					cout << "\n�ִ� ���ż����� 3���Դϴ�!\n\n";
					Sleep(1000);
					system("cls");
				}
			}
			else
			{
				cout << "\n������ ��尡 �����մϴ�.\n";
				Sleep(1000);
			}
			break;
		case Potion::End:
			system("cls");
			cout << "������ ���ư��� ��";
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
