#include "StageScene.h"
#include <Novice.h>
#include <Vector2.h>
#include <Windows.h>
#include <corecrt_math.h>

struct Player {

	Vector2 position = { 640,620 };
	int radius = 10;
	int speed = 8;

};
Player player;
struct Enemy {

	Vector2 position = { 640,100 };
	int radius = 15;
	bool isEnemy = true;

};
Enemy enemy;
struct Bullet {

	Vector2 position = { 0,620 };
	int radius = 5;
	int speed = 8;
	bool isBullet = false;

};
Bullet bullet;

void StageScene::Initialize() {

	player.position.x = 640;
	enemy.isEnemy = true;
	bullet.isBullet = false;
	bullet.position.y = 620;

}

void StageScene::Update(char* keys, char* preKeys) {

	if (keys[DIK_A]) {
		player.position.x -= player.speed;
	}
	if (keys[DIK_D]) {
		player.position.x += player.speed;
	}
	if (player.position.x < 0.0f + player.radius) {
		player.position.x = 0.0f + player.radius;
	}
	if (player.position.x > 1280.0f - player.radius) {
		player.position.x = 1280.0f - player.radius;
	}

	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0 && bullet.isBullet == false) {

		bullet.isBullet = true;
		bullet.position.x = player.position.x;

	}

	if (bullet.isBullet == true) {

		Novice::DrawEllipse(int(bullet.position.x), int(bullet.position.y), bullet.radius, bullet.radius, 0.0f, BLACK, kFillModeSolid);
		bullet.position.y -= bullet.speed;

	}

	if (bullet.position.y <= 0 - bullet.radius) {

		bullet.isBullet = false;
		bullet.position.y = 620;

	}

	if (enemy.isEnemy == true) {

		Novice::DrawEllipse(int(enemy.position.x), int(enemy.position.y), enemy.radius, enemy.radius, 0.0f, RED, kFillModeSolid);

	}

	float a = enemy.position.x - bullet.position.x;
	float b = enemy.position.y - bullet.position.y;
	float distance = sqrtf(a * a + b * b);
	if (distance <= bullet.radius + enemy.radius) {
		enemy.isEnemy = false;
		sceneNo = CLEAR;
	} else {
		enemy.isEnemy = true;
	}

}

void StageScene::Draw() {

	SetConsoleOutputCP(65001);

	Novice::ScreenPrintf(0, 0, "A:playerLeft D:playerRight");
	Novice::ScreenPrintf(0, 30, "Space : Bullet Shot");

	Novice::DrawEllipse(int(player.position.x), int(player.position.y), player.radius, player.radius, 0.0f, BLUE, kFillModeSolid);

}
