#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>														// input output stream : 흐름
#include <random>														// C++ 에서 난수 생성
#include <string>
#include <cassert>	// c를 c++ 버전으로 바꾼버전은 앞에 c가 붙는다.
#include <windows.h>													// sleep 함수 사용을 위한

#pragma warning (disable : 6031)										// scanf 반환관련 경고 삭제

#define SAFE_DELETE(p) { if(p) { delete(p); p = nullptr; } }			// 동적할당한 주소값을 못사용하게 매크로 함수
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[](p); p = nullptr; } }

using namespace std;													// ﻿함수명, 변수명을 해당 함수, 변수의 기능, 설정값과 함께 저장해놓는 곳 namespace, 즉 기본적으로 사용하겠다. :: 범위 확인 연산자

#include "Characters/Character.h"		// 기반 생성자 우선
#include "Characters/Player.h"			// 파생 생성자 다음
#include "Characters/Monster.h"
#include "Places/Dungeon.h"
#include "Places/Forge.h"
#include "Places/Store.h"
#include "Places/Motel.h"