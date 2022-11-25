#include "stdafx.h"
#include "Player.h"

Player::Player(PlayerDesc desc)
	: Character(desc.id, desc.hp, desc.atk, desc.def, desc.avoid)
	, mana(desc.mana)
	, level(desc.level)
	, exp(desc.exp)
	, maxHp(desc.maxHp)
	, maxMana(desc.maxMana)
	, maxExp(desc.maxExp)
	, gold(desc.gold)
	, dungeonFloor(desc.dungeonFloor)
	, weapon(desc.weapon)
	, armor(desc.armor)
	, shoes(desc.shoes)
	, hpPotion(desc.hpPotion)
	, manaPotion(desc.manaPotion)
	, reviveStone(desc.reviveStone)
{
}

void Player::PlayerLevelUp()
{
	level += 1;
	exp -= maxExp;
	maxExp = (level / 2) * 20;
	maxHp = level * 150;
	maxMana = level * 30;
}

void Player::PlayerAttack(Character* otherCharacter)
{
	if (otherCharacter->GetDEF() < (GetATK() + (GetPlayerWeapon() * 5)))
	{
		otherCharacter->SetHP(otherCharacter->GetHP() - ((GetATK() + (GetPlayerWeapon() * 5)) - otherCharacter->GetDEF()));
		cout << "===================== 플레이어의 공격 =====================\n\n";
		cout << "플레이어는 " << GetATK() << "(+" << (GetPlayerWeapon() * 5) << ") 의 데미지로 공격하였다.\n";
		cout << "하지만 몬스터는 " << otherCharacter->GetDEF() << "의 데미지를 방어하였다.\n";
		cout << "총 입은 데미지 : " << (GetATK() + (GetPlayerWeapon() * 5)) - otherCharacter->GetDEF() << "\n\n";
	}
	else
	{
		cout << "===================== 플레이어의 공격 =====================\n\n";
		cout << "플레이어는 " << GetATK() << "(+" << (GetPlayerWeapon() * 5) << ") 의 데미지로 공격하였다.\n";
		cout << "하지만 몬스터는 " << otherCharacter->GetDEF() << "의 데미지를 방어하였다.\n";
		cout << "총 입은 데미지 : 0\n\n";
	}

	if (otherCharacter->GetHP() < 1)
	{
		cout << "남은 몬스터의 체력 : 0\n\n";
	}
	else
	{
		cout << "남은 몬스터의 체력 : " << otherCharacter->GetHP() << "\n\n";
	}
}

void Player::SkillBeginnerSword(Character* otherCharacter)
{
	if (mana >= 15)
	{
		if (otherCharacter->GetDEF() < ((GetATK() * 2) + (GetPlayerWeapon() * 5)))
		{
			otherCharacter->SetHP(otherCharacter->GetHP() - ((GetATK() * 2) + (GetPlayerWeapon() * 5)) - otherCharacter->GetDEF());
			mana = mana - 15;

			cout << "===================== 플레이어의 공격 =====================\n\n";
			cout << "플레이어는 마나 15를 소모해, 스킬 사용\n"; 
			cout << "플레이어는 " << GetATK() * 2 << "(+" << GetPlayerWeapon() * 5 << ") 의 데미지로 공격하였다.\n";
			cout << "하지만 몬스터는 " << otherCharacter->GetDEF() << "의 데미지를 방어하였다.\n";
			cout << "총 입은 데미지 : " << (GetATK() * 2) - otherCharacter->GetDEF() << "\n\n";
		}
		else
		{
			mana = mana - 15;

			cout << "===================== 플레이어의 공격 =====================\n\n";
			cout << "플레이어는 마나 15를 소모해, 스킬 사용\n";
			cout << "플레이어는 " << GetATK() * 2 << "(+" << GetPlayerWeapon() * 5 << ") 의 데미지로 공격하였다.\n";
			cout << "하지만 몬스터는 " << otherCharacter->GetDEF() << "의 데미지를 방어하였다.\n";
			cout << "총 입은 데미지 : 0\n\n";
		}

		if (otherCharacter->GetHP() < 1)
		{
			cout << "남은 몬스터의 체력 : 0\n\n";
		}
		else
		{
			cout << "남은 몬스터의 체력 : " << otherCharacter->GetHP() << "\n\n";
		}
	}
	else
	{
		cout << "플레이어의 마나가 부족합니다!\n\n";
	}

}