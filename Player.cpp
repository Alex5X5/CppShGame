#include "Player.h"

using namespace shgame::logic;

void Player::setHealth(double _health) { health = _health; }
double Player::getHealth() const { return health; }

void Player::setSpeed(double _speed) { speed = _speed; }
double Player::getSpeed() const { return speed; }

void Player::setUUID(short _uuid) { uuid = _uuid; }
short Player::getUUID() const { return uuid; }

void Player::setPos(Vector3d* _pos) { pos.set(_pos); }
Vector3d Player::getPos() const { return pos; }

void Player::setDir(Vector3d* _dir) { dir.set(_dir);}
Vector3d Player::getDir() const { return dir; }

vector<int> Player::CalcCircleOffsets()
{

}

void Player::move()
{

}

void Player::onKeyEvent(Client c)
{

}

void Player::serializePlayer(byte* buffer, Player player, int offset)
{

}

void Player::deserializePlayer(byte* buffer, Player player, int offset)
{

}