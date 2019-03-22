#include "EntryPoint.h"

#include "ECS/World.h"
#include "ECS/Component/SpriteComponent.h"
#include "ECS/Component/TransformComponent.h"
#include "ECS/Component/HoverComponent.h"

void B2D::Config(ApplicationConfig& config)
{
	config.name = "Sandbox";
}

void B2D::PopulateWorld(World* const world)
{
    auto start = std::chrono::high_resolution_clock::now();

    int m = 400;

    //mWorld->AddSystemEntityObject<EcsPlayer>();

    for (int i = 0; i < m; i++)
    {
        EntityID entity = world->AddEntity<Entity>();

        ResourcePtr<CTexture> textures = IResourceManager::Get<CTexture>("Content/Sprites/Character.png");
        SpriteComponent* s = world->AddComponent<SpriteComponent>(entity, CShader::Load("Content/Shader/DefaultVS.glsl", "Content/Shader/SimpleSpritePS.glsl"));
        s->material.SetTexture(0, textures);

        TransformComponent* t = world->AddComponent<TransformComponent>(entity);
        t->position = TVec3(UMath::RandomRange(-5.0f, 5.0f), UMath::RandomRange(-3.0f, 3.0f), UMath::RandomRange(-1.0f, 1.0f));
        t->matrix = TMatrix::Translate(t->matrix, t->position);
        t->matrix = TMatrix::Scale(t->matrix, t->scale);

        HoverComponent* h = world->AddComponent<HoverComponent>(entity);
        h->speed = UMath::RandomRange(1.0f, 5.0f);
    }

    std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
    B2D_INFO("Loading of {0} Entities took {1}s", m, elapsed.count());
}