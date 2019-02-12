#include "Player.h"
#include "GameInstance.h"
#include "PlayerController.h"
#include "InputComponent.h"
#include "SpriteRenderer.h"
#include "BoxCollider.h"
#include "BMath.h"
#include "Input.h"
#include "Debug.h"

// Derive from actor instead of GameObject
// Actor should hold reference to its components but cannot be reused on another GameObject
// The unity approach is it to add the script to the gameobject, but needs always to get its sibling components

Player::Player()
{
	auto controller = CGameInstance::AddPlayerController(0);

	this->Input = this->AddComponent<CInputComponent>();
	this->Input->BindController(controller);
	this->Input->BindKey(65, EKeyEvent::KEY_DOWN, TKeyDelegate::Create(this, &Player::OnMoveLeft));
	this->Input->BindKey(65, EKeyEvent::KEY_UP, TKeyDelegate::Create(this, &Player::OnMoveLeftStopped));
	this->Input->BindKey(68, EKeyEvent::KEY_DOWN, TKeyDelegate::Create(this, &Player::OnMoveRight));
	this->Input->BindKey(68, EKeyEvent::KEY_UP, TKeyDelegate::Create(this, &Player::OnMoveRightStopped));
	this->Input->BindKey(32, EKeyEvent::KEY_DOWN, TKeyDelegate::Create(this, &Player::OnJump));
	this->Input->BindKey(32, EKeyEvent::KEY_UP, TKeyDelegate::Create(this, &Player::OnJumpStopped));

	this->Sprite = this->AddComponent<CSpriteRenderer>();
	this->Sprite->SetSprite("Content/Sprites/norm.png");

	this->Collider = this->AddComponent<CBoxCollider>();
	this->Collider->SetSize(100, 100);
}

Player::~Player()
{
	printf("osifdgsg");
}

void Player::Update(float fDeltaTime)
{
	CGameObject::Update(fDeltaTime);

	SVector2 vPosition = this->GetPosition();
	vPosition.X += (this->MoveRigthtForce - this->MoveLeftForce) * this->MovementSpeed * fDeltaTime;
	this->SetPosition(vPosition, true);
}

void Player::OnMoveRight()
{
	this->MoveRigthtForce = 1.f;
}

void Player::OnMoveRightStopped()
{
	this->MoveRigthtForce = 0.f;
}

void Player::OnMoveLeft()
{
	this->MoveLeftForce = 1.f;
}

void Player::OnMoveLeftStopped()
{
	this->MoveLeftForce = 0.f;
}

void Player::OnJump()
{
	SVector2 vPosition = this->GetPosition();
	vPosition.Y -= 50;
	this->SetPosition(vPosition, true);
	
	printf("JUMP\n");
}

void Player::OnJumpStopped()
{
	SVector2 vPosition = this->GetPosition();
	vPosition.Y += 50;
	this->SetPosition(vPosition, true);
}
