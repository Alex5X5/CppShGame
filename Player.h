#pragma once
#include <vector>

#include <cmath>
#include <string>

#include "Drawable.h"
#include "Vector3d.hpp"

namespace shgame::logic
{
    class Player : public shgame::rendering::Drawable
    {

        private:
            static const std::vector<int> CIRCLE_OFFSETS;

            short WeaponCooldownTicks;
            short weaponCooldownTicksDone;

            bool IsShooting;
            short InitialBulletSpeed;

            shgame::logic::math::Vector3d pos;
            shgame::logic::math::Vector3d dir;

            double health;
            double speed;
            short uuid;
            bool visible;
        
        public:
            static const int Radius = 10;
            static const int PLAYER_BYTE_LENGTH = 56;
            
        public:
            double getHealth() const;
            void setHealth(double _health);

            double getSpeed() const;
            void setSpeed(double _speed);

            short getUUID() const;
            void setUUID(short _uuid);

            shgame::logic::math::Vector3d getPos() const;
            void setPos(shgame::logic::math::Vector3d* _pos);

            shgame::logic::math::Vector3d getDir() const;
            void setDir(shgame::logic::math::Vector3d* _dir);

            static const int SIZE = 20, SIDES_COUNT = 50, FLOAT_COUNT = 9 * SIDES_COUNT;
            
            static std::vector<int> calcCircleOffsets();
            
            void updateVertices() override;

            Player();
            Player(shgame::logic::math::Vector3d newPos, int newHealth, short UUID);

            string ToString();

            void move();
            void damage(int damage);
            void deactivate();


            void onKeyEvent(std::tuple<bool, bool, bool, bool>* pressedKeys);

            static void serializePlayer(unsigned char* buffer, shgame::logic::Player player, int offset);
            
            static void deserializePlayer(unsigned char* buffer, Player player, int offset);
    };
}
