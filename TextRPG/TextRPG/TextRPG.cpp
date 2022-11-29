#include "stdafx.h"
#include "TextRPG.h"


TextRPG::TextRPG()
{
	PlayerDesc desc = { 0 };
	cout << "저장된 게임정보를 불러오겠습니까?\n";
	cout << "1. Yes\t2. No(새 게임)\n";
	cout << "선택 : ";

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		PlayerSavedRetrieve(&desc);
	}
	else 
	{
		desc.level = 1;
		desc.hp = 150;
		desc.mana = 30;
		desc.atk = 20;
		desc.def = 5;
		desc.gold = 500;
		desc.dungeonFloor = 1;
		desc.maxHp = desc.level * 150;
		desc.maxMana = desc.level * 30;
		desc.maxExp = desc.level * 20;
		desc.avoid = desc.shoes * 2;
	}

	Player* player1 = new Player(desc);
	system("cls");
	Play(player1);
}

TextRPG::~TextRPG()
{
	SAFE_DELETE(motel);
	SAFE_DELETE(store);
	SAFE_DELETE(forge);
	SAFE_DELETE(dungeon);
	SAFE_DELETE(player);
}

void TextRPG::Play(Player* player)
{
	bool playing = 1;

	while (playing)
	{
		Act act;
		cout << "=======================\n";
		cout << "1. 던전\n";			// 몬스터 사냥, 경험치, 돈
		cout << "2. 대장간\n";		// 무기, 갑옷 등 강화로 방어력, 공격력 증가
		cout << "3. 잡화점\n";		// 체력포션, 마나포션, 부활석 아이템 구매, 골드 소비
		cout << "4. 여관\n";			// ?? 체력 및 마나 회복
		cout << "5. 캐릭터 정보\n";	// 캐릭터 정보 확인
		cout << "6. 스킬 정보\n";		// 스킬 정보 확인
		cout << "7. 게임 저장\n";		// 게임 정보를 파일로 저장
		cout << "8. 여정 끝내기\n";	// 게임 종료
		cout << "=======================\n";
		cout << "행동 선택 : ";
		scanf("%d", &act);

		switch (act)
		{
		case Act::Dungeon:	// switch문에서 선언이나 할당할 시, 중괄호를 사용해야한다!!
		{
			system("cls");
			dungeon = new Dungeon(player);
			SAFE_DELETE(dungeon);
			break;
		}
		case Act::Forge:
		{
			system("cls");
			forge = new Forge(player);
			SAFE_DELETE(forge);
			break;
		}
		case Act::Store:
		{
			system("cls");
			store = new Store(player);
			SAFE_DELETE(store);
			break;
		}
		case Act::Motel:
		{
			system("cls");
			motel = new Motel(player);
			SAFE_DELETE(motel);
			break;
		}
		case Act::CharInfo:
		{
			system("cls");
			PlayerInfo(player);
			break;
		}
		case Act::SkillInfo:
		{
			system("cls");
			SkillInfo(player);
			break;
		}
		case Act::Save:
		{
			system("cls");
			cout << "플레이한 게임 정보를 저장하시겠습니까?\n";
			cout << "1. Yes\t2. No(나가기)\n";
			cout << "선택 : ";
			int select = 0;
			cin >> select;
			if (select == 1)
			{
				Save(player);
				cout << "플레이한 정보가 저장되었습니다.";
				Sleep(1000);
			}
			system("cls");
			break;
		}
		case Act::End:
		{
			system("cls");
			cout << "저장하지 않은 정보는 사라집니다.\n";
			cout << "1. Yes 2. No\n";
			cout << "선택 : ";
			int select = 0;
			cin >> select;
			if (select == 1)
			{
				playing = 0;
				break;
			}
			break;
		}
		default:
			break;
		}
	}
}

void TextRPG::PlayerInfo(Player* player)
{
	cout << "=================== 캐릭터 정보 ===================\n";
	cout << " Id\t: " << player->GetID() << "\n";
	cout << " Hp\t: " << player->GetHP() << " / " << player->GetPlayerMaxHp() << "\n";
	cout << " Mana\t: " << player->GetPlayerMana() << " / " << player->GetPlayerMaxMana() << "\n";
	cout << " Atk\t: " << player->GetATK() << "\n";
	cout << " Def\t: " << player->GetDEF() << "\n";
	cout << " Avoid\t: " << player->GetAVOID() << "\n";
	cout << " Level\t: " << player->GetPlayerLevel() << "\n";
	cout << " Exp\t: " << player->GetPlayerExp() << " / " << player->GetPlayerMaxExp() << "\n";
	cout << " Gold\t: " << player->GetPlayerGold() << "\n";

	cout << "\n==================== 던전 정보 ====================\n";
	cout << " DungeonFloor\t: " << player->GetDungeonFloor() << "층\n";
	// 장비정보
	cout << "\n==================== 장비 정보 ====================\n";
	cout << " Weapon\t: " << player->GetPlayerWeapon() << "강, 추가 공격력 : +" << player->GetPlayerWeapon() * 5 << "\n";
	cout << " Armor\t: " << player->GetPlayerArmor() << "강, 추가 방어력 : +" << player->GetPlayerArmor() * 5 << "\n";
	cout << " Shoes\t: " << player->GetPlayerShoes() << "강, 추가 회피력 : +" << player->GetPlayerShoes() * 2 << "%\n";
	// 보유 아이템정보
	cout << "\n=================== 아이템 정보 ===================\n";
	cout << " HpPotion\t: " << player->GetPlayerHpPotion() << "개\n";
	cout << " ManaPotion\t: " << player->GetPlayerManaPotion() << "개\n";
	cout << " ReviveStone\t: " << player->GetPlayerReviveStone() << "개\n";

	cout << "\n===================================================\n";
	cout << "\n나가기\n";
	system("pause");
	system("cls");
}

void TextRPG::SkillInfo(Player* player)
{
	// 스킬정보
	cout << "\n==================== 스킬 정보 ====================\n";
	cout << "1. 초급검술\n";
	cout << "\t공격력 : " << player->GetATK() * 2 << "\n";
	cout << "\t마나 소모 : " << 15 << "\n";

	cout << "\n===================================================\n";
	cout << "\n나가기\n";
	system("pause");
	system("cls");
}

void TextRPG::Save(Player* player)
{
	FILE* saveFile = fopen("SaveFile.txt", "w");
	// https://moozi.tistory.com/356
//	fprintf(saveFile, "%l ", player);


//	fprintf(saveFile, "%d ", player->GetID());
//	fprintf(saveFile, "%d ", player->GetHP());
//	fprintf(saveFile, "%d ", player->GetATK());
//	fprintf(saveFile, "%d ", player->GetDEF());
//	fprintf(saveFile, "%d ", player->GetAVOID());
//	fprintf(saveFile, "%d ", player->GetPlayerMaxHp());
//	fprintf(saveFile, "%d ", player->GetPlayerMaxMana());
//	fprintf(saveFile, "%d ", player->GetPlayerMaxExp());
//	fprintf(saveFile, "%d ", player->GetPlayerLevel());
//	fprintf(saveFile, "%d ", player->GetPlayerExp());
//	fprintf(saveFile, "%d ", player->GetPlayerMana());
//	fprintf(saveFile, "%d ", player->GetPlayerGold());
//	fprintf(saveFile, "%d ", player->GetDungeonFloor());
//	fprintf(saveFile, "%d ", player->GetPlayerWeapon());
//	fprintf(saveFile, "%d ", player->GetPlayerArmor());
//	fprintf(saveFile, "%d ", player->GetPlayerShoes());
//	fprintf(saveFile, "%d ", player->GetPlayerHpPotion());
//	fprintf(saveFile, "%d ", player->GetPlayerManaPotion());
//	fprintf(saveFile, "%d\n", player->GetPlayerReviveStone());

	fclose(saveFile);
}

void TextRPG::PlayerSavedRetrieve(PlayerDesc* desc)
{
	FILE* readFile = fopen("SaveFile.txt", "r");

	if (readFile != nullptr)
	{	
	//	fscanf(readFile, "%l ", &desc);

	//	fscanf(readFile, "%d ", &desc->id);
	//	fscanf(readFile, "%d ", &desc->hp);
	//	fscanf(readFile, "%d ", &desc->atk);
	//	fscanf(readFile, "%d ", &desc->def);
	//	fscanf(readFile, "%d ", &desc->avoid);
	//	fscanf(readFile, "%d ", &desc->maxHp);
	//	fscanf(readFile, "%d ", &desc->maxMana);
	//	fscanf(readFile, "%d ", &desc->maxExp);
	//	fscanf(readFile, "%d ", &desc->level);
	//	fscanf(readFile, "%d ", &desc->exp);
	//	fscanf(readFile, "%d ", &desc->mana);
	//	fscanf(readFile, "%d ", &desc->gold);
	//	fscanf(readFile, "%d ", &desc->dungeonFloor);
	//	fscanf(readFile, "%d ", &desc->weapon);
	//	fscanf(readFile, "%d ", &desc->armor);
	//	fscanf(readFile, "%d ", &desc->shoes);
	//	fscanf(readFile, "%d ", &desc->hpPotion);
	//	fscanf(readFile, "%d ", &desc->manaPotion);
	//	fscanf(readFile, "%d ", &desc->reviveStone);

		fclose(readFile);
	}
	else
	{
		printf("Read Stream Open Error!");	// 에러 출력
		Sleep(1200);
	}
}
