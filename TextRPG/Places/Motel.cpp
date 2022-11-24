#include "stdafx.h"
#include "Motel.h"

Motel::Motel(Player* player)
{
	int motel = 1;
	while (motel)
	{
		cout << "=================== ���� =================== \n\n";
		cout << "�������� ���ڽ��ϱ�?(2���)\n";
		cout << "1. Yes 2. No(������)\n";
		cout << "���� : ";
		int choice = 0;
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			if (player->GetPlayerGold() >= 2)
			{
				player->SetPlayerGold(player->GetPlayerGold() - 2);		// ��� �Һ�
				system("cls");
				cout << "�÷��̾��� \n";
				cout << "ü���� " << player->GetPlayerMaxHp() - player->GetHP() << "\n";
				cout << "������ " << (player->GetPlayerLevel() * 30) - player->GetPlayerMana() << "\n";
				cout << "��ŭ ȸ���Ǿ���.";
				player->SetHP(player->GetPlayerLevel() * 150);			// ü�� ȸ��
				player->SetPlayerMana(player->GetPlayerLevel() * 30);	// ���� ȸ��
			}
			else
			{
				cout << "\n������ ��尡 �����մϴ�.\n";
			}
			Sleep(1200);
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "������ ���ư��� ��";
			for (int i = 0; i < 3; ++i)
			{
				cout << ". ";
				Sleep(300);
			}
			motel = 0;
			break;
		}
		default:
			cout << "�ش� ������ �ൿ�� �����ϴ�.\n";
			break;
		}
		system("cls");
	}
}

Motel::~Motel()
{
}
