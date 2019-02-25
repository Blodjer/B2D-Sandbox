#include "Core/GameEngine.h"
#include "Core/GameInstance.h"
#include "TestScene.h"

#include <eh.h>
#include <iostream>

#define _CRTDBG_MAP_ALLOC

int main(int argc, const char*[])
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	auto engine = CGameEngine::Init();

	CGameInstance* const pGameInstance = engine->GetGameInstance();
	pGameInstance->LoadLevel<TestScene>();

	engine->Start();

	return 0;
}