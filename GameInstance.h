#pragma once
#include <functional>
#include <algorithm>
#include "Bullet.h"
#include "Player.h"

namespace shgame::logic
{

	class GameInstance
	{
		
		public:
			static const int OBSTACKLE_ROWS = 5, OBSTACKLE_LINES = 8;
			static const int MAP_GRID_WIDTH = 2100, MAP_GRID_HEIGHT = 1400;
			static const int OBSTACLE_ROW_DISANCE = MAP_GRID_WIDTH / OBSTACKLE_ROWS;
			static const int OBSTACLE_COUNT = OBSTACKLE_ROWS * OBSTACKLE_LINES;
			static const int OBSTACLE_LINE_DISTANCE = MAP_GRID_HEIGHT / OBSTACKLE_LINES;

			static constexpr int PLAYER_COUNT = 20;
			static constexpr int BULLET_COUNT = 200;

			static const int TARGET_TPS = 20;

			static const long TARGET_LOOP_DELAY_TICKS = 100; //TimeSpan.TicksPerSecond / TARGET_TPS;
			static const long LOOP_FRAGMENT_SLEEP_TICKS = TARGET_LOOP_DELAY_TICKS / 20;

		private:
			bool Idle = true;
			bool Run = false;

			void AllocBullet(shgame::logic::Player* p);

			std::function<void()> prePlayerMoveLoop;
			std::function<void()> pastPlayerMoveLoop;

			std::function<void()> preBulletMoveLoop;
			std::function<void()> pastBulletMoveLoop;

			std::function<void()> prePlayerShootLoop;
			std::function<void()> pastPlayerShootLoop;

			shgame::logic::Bullet bullets[BULLET_COUNT] = {};
			shgame::logic::Player players[PLAYER_COUNT] = {};

		public:
			GameInstance();
			//GameInstance(shgame::Client* client);

			void StartNewLoop(std::function<void()> loop);
			void StartAllLoops();

			void Stop();

			void PlayerMoveLoop();
			void BulletMoveLoop();
			void PlayerShootLoop();

			void SpreadObstacles();
			void PlaceObstacles(int row, int line, int offset);
	};
}