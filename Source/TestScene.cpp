#include "TestScene.h"

#include "Component/BoxCollider.h"
#include "Component/SpriteRenderer.h"
#include "Debug/Debug.h"
#include "Math/BMath.h"
#include "Player.h"

#include <chrono>
#include <iostream>

TestScene::TestScene()
{
	Player* player = SpawnGameObject<Player>(SVector2(200, 400));

	CGameObject* gameObject = SpawnGameObject(SVector2(500, 600));
	CBoxCollider* collider = gameObject->AddComponent<CBoxCollider>();
	collider->SetSize(600, 100);

	/*
	auto start = std::chrono::high_resolution_clock::now();

	int m = 15;
	for (int i = 0; i < m; i++)
	{
		auto g = SpawnGameObject();
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
