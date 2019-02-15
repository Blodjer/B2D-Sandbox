#include "Core/GameEngine.h"
#include "Core/GameInstance.h"
#include "Debug/Debug.h"
#include "TestScene.h"

#include <eh.h>
#include <iostream>
#include <Windows.h>

LONG WINAPI MyUnhandledExceptionFilter(PEXCEPTION_POINTERS pExceptionPtrs)
{
	static char msg[256];
	sprintf_s(msg, 256, "Unhandled exception 0x%08x at 0x%08x",
		pExceptionPtrs->ExceptionRecord->ExceptionCode,
		pExceptionPtrs->ExceptionRecord->ExceptionAddress);
	printf(msg);
	getchar();
	return EXCEPTION_EXECUTE_HANDLER;
}

int main(int argc, const char*[])
{
	SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);

	auto engine = CGameEngine::Init();

	CGameInstance* const pGameInstance = engine->GetGameInstance();
	pGameInstance->LoadLevel<TestScene>();

	engine->Start();

	return 0;
}