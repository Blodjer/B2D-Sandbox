#pragma once

#include <GameObject.h>

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

	float MovementSpeed = 100.f; // 4
	float MoveRigthtForce = 0.f; // 4
	float MoveLeftForce = 0.f;	 // 4

private:
	class CInputComponent* Input; // 4 / 8
	class CSpriteRenderer* Sprite;// 4 / 8
	class CBoxCollider* Collider; // 4 / 8
	
};
