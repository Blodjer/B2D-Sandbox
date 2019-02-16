#include "Player.h"

#include "Component/BoxCollider.h"
#include "Component/InputComponent.h"
#include "Component/SpriteRenderer.h"
#include "Core/GameInstance.h"
#include "Input.h"
#include "PlayerController.h"

// Derive from actor instead of GameObject
// Actor should hold reference to its components but cannot be reused on another GameObject
// The unity approach is it to add the script to the gameobject, but needs always to get its sibling components

Player::Player()
{
	CPlayerController* const controller = CGameInstance::AddPlayerController(0);

	mInput = AddComponent<CInputComponent>();
	mInput->BindController(controller);
	mInput->BindKey(EKey::A, EKeyEvent::KEY_DOWN, TKeyDelegate::CREATE(&Player::OnMoveLeft));
	mInput->BindKey(EKey::A, EKeyEvent::KEY_UP, TKeyDelegate::CREATE(&Player::OnMoveLeftStopped));
	mInput->BindKey(EKey::D, EKeyEvent::KEY_DOWN, TKeyDelegate::CREATE(&Player::OnMoveRight));
	mInput->BindKey(EKey::D, EKeyEvent::KEY_UP, TKeyDelegate::CREATE(&Player::OnMoveRightStopped));
	mInput->BindKey(EKey::SPACE, EKeyEvent::KEY_DOWN, TKeyDelegate::CREATE(&Player::OnJump));
	mInput->BindKey(EKey::SPACE, EKeyEvent::KEY_UP, TKeyDelegate::CREATE(&Player::OnJumpStopped));
	
	mSprite = AddComponent<CSpriteRenderer>();
	mSprite->SetSprite("Content/Sprites/norm.png");

	mCollider = AddComponent<CBoxCollider>();
	mCollider->SetSize(100, 100);
}

Player::~Player()
{
	printf("osifdgsg");
}

void Player::Update(float deltaTime)
{
	CGameObject::Update(deltaTime);

	TVec2 position = GetPosition();
	position.X += (mMoveRigthtForce - mMoveLeftForce) * mMovementSpeed * deltaTime;
	SetPosition(position, true);
}

void Player::OnMoveRight()
{
	mMoveRigthtForce = 1.f;
}

void Player::OnMoveRightStopped()
{
	mMoveRigthtForce = 0.f;
}

void Player::OnMoveLeft()
{
	mMoveLeftForce = 1.f;
}

void Player::OnMoveLeftStopped()
{
	mMoveLeftForce = 0.f;
}

void Player::OnJump()
{
	TVec2 position = GetPosition();
	position.Y -= 50;
	SetPosition(position, true);
	
	printf("JUMP\n");
}

void Player::OnJumpStopped()
{
	TVec2 position = GetPosition();
	position.Y += 50;
	SetPosition(position, true);
}
