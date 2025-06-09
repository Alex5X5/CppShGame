#include <cstddef>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>
#include <string>

#include "Vector3d.hpp"
#include "Drawable.h"
#include "Client.h"

using namespace std;
using namespace shgame::logic::math;

namespace shgame::logic
{
	class Player : shgame::rendering::Drawable
	{

		private:
			static const vector<int> CIRCLE_OFFSETS;

			short WeaponCooldownTicks = 10;
			short weaponCooldownTicksDone = 10;

			bool IsShooting = false;
			short InitialBulletSpeed = 0x30;

			Vector3d pos = Vector3d(100,100,0);
			Vector3d dir = Vector3d(0, 0, 0);

			double health;
			double speed = 2;
			short uuid = 0;
			bool visible;
			

		public:
			static const int PLAYER_BYTE_LENGTH = 56;
			static const int Radius = 10;
			
			double getHealth() const;
			void setHealth(double _health);

			double getSpeed() const;
			void setSpeed(double _speed);

			short getUUID() const;
			void setUUID(short _uuid);

			Vector3d getPos() const;
			void setPos(Vector3d* _pos);

			Vector3d getDir() const;
			void setDir(Vector3d* _dir);

			static const int SIZE = 20, SIDES_COUNT = 50, FLOAT_COUNT = 9 * SIDES_COUNT;
			
			static vector<int> CalcCircleOffsets();

			Player(Vector3d newPos, int newHealth, short UUID);
			Player();

			string ToString();

			void move();
			void damage(int damage);
			void deactivate();

			void onKeyEvent(Client c);

			static void serializePlayer(byte* buffer, Player player, int offset);
			
			static void deserializePlayer(byte* buffer, Player player, int offset);
	};
}
