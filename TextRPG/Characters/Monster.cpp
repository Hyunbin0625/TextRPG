#include "stdafx.h"
#include "Monster.h"

void Monster::MonsterAttack(Player* player)
{
	if ((player->GetDEF() + (player->GetPlayerArmor() * 5)) < GetATK())
	{
		player->SetHP(player->GetHP() - (GetATK() - (player->GetDEF() + (player->GetPlayerArmor() * 5))));
		cout << "====================== 몬스터의 공격 ======================\n\n";
		cout << "몬스터는 " << GetATK() << " 의 데미지로 공격하였다.\n";
		cout << "하지만 플레이어는 " << (player->GetDEF() + (player->GetPlayerArmor() * 5)) << "의 데미지를 방어하였다.\n";
		cout << "총 입은 데미지 : " << (GetATK() - (player->GetDEF() + (player->GetPlayerArmor() * 5))) << "\n\n";
	}
	else
	{
		cout << "====================== 몬스터의 공격 ======================\n\n";
		cout << "몬스터는 " << GetATK() << " 의 데미지로 공격하였다.\n";
		cout << "하지만 플레이어는 " << (player->GetDEF() + (player->GetPlayerArmor() * 5)) << "의 데미지를 방어하였다.\n";
		cout << "총 입은 데미지 : 0\n\n";
	}

	if (player->GetHP() < 1)
	{
		cout << "남은 플레이어의 체력 : 0\n\n";
	}
	else
	{
		cout << "남은 플레이어의 체력 : " << player->GetHP() << "\n\n";
	}
}
