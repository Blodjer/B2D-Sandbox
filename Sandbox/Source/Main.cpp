#include "EntryPoint.h"

#include "Component/BoxCollider.h"
#include "GameObject.h"
#include "Level.h"
#include "Player.h"

void B2D::Config(ApplicationConfig& config)
{
	config.name = "Sandbox";
}

void B2D::PopulateLevel(CLevel* const level)
{
    Player* player = level->SpawnGameObject<Player>(TVec2(200, 400));

    CGameObject* gameObject = level->SpawnGameObject(TVec2(500, 600));
    CBoxCollider* collider = gameObject->AddComponent<CBoxCollider>();
    collider->SetSize(600, 100);

    /*
    auto start = std::chrono::high_resolution_clock::now();

    int m = 20;
    for (int i = 0; i < m; i++)
    {
        Player* g = level->SpawnGameObject<Player>();

        for (CComponent* const c : g->GetComponents())
        {
            c->SetRelativePosition(TVec2(UMath::RandomRange(-400, 400), UMath::RandomRange(-200, 200)));
        }
    }

    std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
    B2D_INFO("Loading of {0} GameObjects took {1}s", m, elapsed.count());
    */
}