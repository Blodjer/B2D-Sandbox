#pragma once

#include "GameObject.h"

class CBoxCollider;
class CInputComponent;
class CComplexSpriteRenderer;

class Player : public CGameObject
{
public:
	Player();
	~Player();

	virtual void Update(float deltaTime) override; // 4 / 8

private:
	void OnMoveRight();
	void OnMoveRightStopped();
	void OnMoveLeft();
	void OnMoveLeftStopped();

	void OnJump();
	void OnJumpStopped();

	float mMovementSpeed = 100.f; // 4
	float mMoveRigthtForce = 0.f; // 4
	float mMoveLeftForce = 0.f;	 // 4

private:
	CInputComponent* mInput; // 4 / 8
	CComplexSpriteRenderer* mSprite;// 4 / 8
	CBoxCollider* mCollider; // 4 / 8
	
};
