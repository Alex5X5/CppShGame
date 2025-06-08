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

namespace shgame::game::logic
{
	class Player : Drawable 
	{

		private:
			int Health_;
			static const int PLAYER_BYTE_LENGTH = 56;

			static const int Radius = 10;
			static const int SIZE = 20, SIDES_COUNT = 50, FLOAT_COUNT = 9 * SIDES_COUNT;

			static const vector<int> CIRCLE_OFFSETS;

			short WeaponCooldownTicks = 10;
			short weaponCooldownTicksDone = 10;

			bool IsShooting = false;
			short InitialBulletSpeed = 0x30;

			Vector3d Pos = Vector3d(100,100,0);
			Vector3d Dir = Vector3d(0, 0, 0);

			double Speed = 2;
			short PlayerUUID = 0;
			bool Visible;
			

		public:
			static vector<int> CalcCircleOffsets();

			Player(Vector3d newPos, int newHealth, short UUID);

			Player();

			string ToString();

			void Move();

			void Damage(int damage);
	
			void Deactivate();

			void OnKeyEvent(Client c);
		
			static void SerializePlayer(byte* buffer, Player player, int offset);
			
			static void DeserializePlayer(byte* buffer, Player player, int offset);
	};
}
