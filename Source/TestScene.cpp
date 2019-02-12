#include "TestScene.h"
#include <chrono>
#include "Player.h"
#include <SpriteRenderer.h>
#include <iostream>
#include "BMath.h"
#include "BoxCollider.h"
#include "Debug.h"

TestScene::TestScene()
{
	Player* p =	this->SpawnGameObject<Player>(SVector2(200, 400));

	CGameObject* pGameObject = this->SpawnGameObject(SVector2(500, 600));
	auto pCollider = pGameObject->AddComponent<CBoxCollider>();
	pCollider->SetSize(600, 100);

	/*
	auto start = std::chrono::high_resolution_clock::now();

	int m = 15;
	for (int i = 0; i < m; i++)
	{
		auto g = this->SpawnGameObject();
		auto s = g->AddComponent<CSpriteRenderer>();
		s->mRelativPosition = SVector2(BMath::RandomRange(100, 900), BMath::RandomRange(300, 700));
		auto a = s;
	}

	std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
	std::cout << "Loading of " << m << " GameObjects took: " << elapsed.count() << "s" << std::endl;
	*/
}

TestScene::~TestScene()
{

}
