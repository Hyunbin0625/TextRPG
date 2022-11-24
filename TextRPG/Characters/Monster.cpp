#include "stdafx.h"
#include "Monster.h"

void Monster::MonsterAttack(Player* player)
{
	if ((player->GetDEF() + (player->GetPlayerArmor() * 5)) < GetATK())
	{
		player->SetHP(player->GetHP() - (GetATK() - (player->GetDEF() + (player->GetPlayerArmor() * 5))));
		cout << "====================== ������ ���� ======================\n\n";
		cout << "���ʹ� " << GetATK() << " �� �������� �����Ͽ���.\n";
		cout << "������ �÷��̾�� " << (player->GetDEF() + (player->GetPlayerArmor() * 5)) << "�� �������� ����Ͽ���.\n";
		cout << "�� ���� ������ : " << (GetATK() - (player->GetDEF() + (player->GetPlayerArmor() * 5))) << "\n\n";
	}
	else
	{
		cout << "====================== ������ ���� ======================\n\n";
		cout << "���ʹ� " << GetATK() << " �� �������� �����Ͽ���.\n";
		cout << "������ �÷��̾�� " << (player->GetDEF() + (player->GetPlayerArmor() * 5)) << "�� �������� ����Ͽ���.\n";
		cout << "�� ���� ������ : 0\n\n";
	}

	if (player->GetHP() < 1)
	{
		cout << "���� �÷��̾��� ü�� : 0\n\n";
	}
	else
	{
		cout << "���� �÷��̾��� ü�� : " << player->GetHP() << "\n\n";
	}
}
