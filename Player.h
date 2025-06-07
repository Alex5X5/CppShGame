#include <cstddef>

using namespace std;

namespace shgame::game::logic
{

	class Person 
	{
	
		public:
			static const int SIZE = 20, SIDES_COUNT = 50, FLOAT_COUNT = 9 * SIDES_COUNT;
			static const int PLAYER_BYTE_LENGTH = 56;

			int points[SIDES_COUNT];
	
			byte IsShooting = byte{ 0x00 };
			short InitialBulletSpeed = 0x30;
	};
}