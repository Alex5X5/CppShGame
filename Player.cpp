#include "Player.h"

void shgame::logic::Player::setHealth(double _health) { health = _health; }
double shgame::logic::Player::getHealth() const { return health; }

void shgame::logic::Player::setSpeed(double _speed) { speed = _speed; }
double shgame::logic::Player::getSpeed() const { return speed; }

void shgame::logic::Player::setUUID(short _uuid) { uuid = _uuid; }
short shgame::logic::Player::getUUID() const { return uuid; }

void shgame::logic::Player::setPos(shgame::logic::math::Vector3d* _pos) { pos.set(_pos); }
shgame::logic::math::Vector3d shgame::logic::Player::getPos() const { return pos; }

void shgame::logic::Player::setDir(shgame::logic::math::Vector3d* _dir) { dir.set(_dir);}
shgame::logic::math::Vector3d shgame::logic::Player::getDir() const { return dir; }

vector<int> shgame::logic::Player::calcCircleOffsets()
{
	return vector<int>();
}

void shgame::logic::Player::updateVertices()
{
}

shgame::logic::Player::Player()
{
}

shgame::logic::Player::Player(shgame::logic::math::Vector3d newPos, int newHealth, short UUID)
{
}

string shgame::logic::Player::ToString()
{
	return "";
}

void shgame::logic::Player::move()
{

}

void shgame::logic::Player::damage(int damage)
{
}

void shgame::logic::Player::deactivate()
{
}

void shgame::logic::Player::onKeyEvent(std::tuple<bool, bool, bool, bool>* pressedKeys)
{

}

void shgame::logic::Player::serializePlayer(unsigned char* buffer, shgame::logic::Player player, int offset)
{

}

void shgame::logic::Player::deserializePlayer(unsigned char* buffer, shgame::logic::Player player, int offset)
{

}