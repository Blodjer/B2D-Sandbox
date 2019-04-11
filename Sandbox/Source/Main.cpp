#include "EntryPoint.h"

#include "Game/Core/World.h"
#include "Game/Component/CharacterMovementComponent.h"
#include "Game/Component/HoverComponent.h"
#include "Game/Component/InputComponent.h"
#include "Game/Component/SpriteComponent.h"
#include "Game/Component/TransformComponent.h"

void B2D::Config(ApplicationConfig& config)
{
	config.name = "Sandbox";
}

void B2D::PopulateWorld(World* const world)
{
    auto start = std::chrono::high_resolution_clock::now();

    //mWorld->AddSystemEntityObject<EcsPlayer>();

    EntityID characterEntity = world->AddEntity<Entity>();
    world->AddComponent<TransformComponent>(characterEntity, TVec3(0.0f, 0.0f, -2.0f));
    world->AddComponent<InputComponent>(characterEntity);
    world->AddComponent<CharacterMovementComponent>(characterEntity);

    ResourcePtr<CTexture> characterTexture = IResourceManager::Get<CTexture>("Content/Sprites/Character.png");
    SpriteComponent* spriteComponent = world->AddComponent<SpriteComponent>(characterEntity, CShader::Load("Content/Shader/DefaultVS.glsl", "Content/Shader/SimpleSpritePS.glsl"));
    spriteComponent->material.SetTexture(0, characterTexture);

    int m = 9900;
    for (int i = 0; i < m; i++)
    {
        EntityID entity = world->AddEntity<Entity>();

        TransformComponent* t = world->AddComponent<TransformComponent>(entity);
        t->position = TVec3(UMath::RandomRange(-5.0f, 5.0f), UMath::RandomRange(-3.0f, 3.0f), UMath::RandomRange(-1.0f, 1.0f));
        t->matrix = TMatrix::Translate(t->matrix, t->position);
        t->matrix = TMatrix::Scale(t->matrix, t->scale);

        ResourcePtr<CTexture> texture = IResourceManager::Get<CTexture>("Content/Sprites/diff.png");
        SpriteComponent* s = world->AddComponent<SpriteComponent>(entity, CShader::Load("Content/Shader/DefaultVS.glsl", "Content/Shader/SimpleSpritePS.glsl"));
        s->material.SetTexture(0, texture);

        if (i < 1000)
        {
            HoverComponent* h = world->AddComponent<HoverComponent>(entity);
            h->speed = UMath::RandomRange(1.0f, 5.0f);
        }
    }

    std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
    B2D_INFO("Loading of {0} Entities took {1}s", m, elapsed.count());
}