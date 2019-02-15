#include "Player.h"

#include "Component/BoxCollider.h"
#include "Component/InputComponent.h"
#include "Component/SpriteRenderer.h"
#include "Core/GameInstance.h"
#include "Debug/Debug.h"
#include "Input.h"
#include "Math/BMath.h"
#include "PlayerController.h"

// Derive from actor instead of GameObject
// Actor should hold reference to its components but cannot be reused on another GameObject
// The unity approach is it to add the script to the gameobject, but needs always to get its sibling components

Player::Player()
{
	CPlayerController* const controller = CGameInstance::AddPlayerController(0);

	mInput = AddComponent<CInputComponent>();
	mInput->BindController(controller);
	mInput->BindKey(65, EKeyEvent::KEY_DOWN, TKeyDelegate::Create(&Player::OnMoveLeft));
	mInput->BindKey(65, EKeyEvent::KEY_UP, TKeyDelegate::Create(&Player::OnMoveLeftStopped));
	mInput->BindKey(68, EKeyEvent::KEY_DOWN, TKeyDelegate::Create(&Player::OnMoveRight));
	mInput->BindKey(68, EKeyEvent::KEY_UP, TKeyDelegate::Create(&Player::OnMoveRightStopped));
	mInput->BindKey(32, EKeyEvent::KEY_DOWN, TKeyDelegate::Create(&Player::OnJump));
	mInput->BindKey(32, EKeyEvent::KEY_UP, TKeyDelegate::Create(&Player::OnJumpStopped));
	
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

	SVector2 position = GetPosition();
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
	SVector2 position = GetPosition();
	position.Y -= 50;
	SetPosition(position, true);
	
	printf("JUMP\n");
}

void Player::OnJumpStopped()
{
	SVector2 position = GetPosition();
	position.Y += 50;
	SetPosition(position, true);
}
