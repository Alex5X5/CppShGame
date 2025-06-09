#pragma once
#include "asio.hpp";
#include "Client.h";
#include "Drawable.h";
#include "ServerConnection.h"
#include "Player.h"
#include "GameInstance.h"

using namespace asio;
using namespace asio::ip;
using namespace shgame::logic;

namespace shgame::net
{
	class GameServer
	{
		private:
			bool stop;
			//Logger logger;
			//long serverTimer = 0;
			//ServerConnection clients[];
			//unsafe readonly Obstacle[] obstacles = new Obstacle[OBSTACLE_COUNT];
			//Bullet[] bullets;

			io_context context;

			tcp::endpoint endpoint;
			tcp::acceptor acceptor;

			GameInstance game;

			void OnAccept(tcp::endpoint socket);

			bool IsPlayerRegistered(shgame::logic::Player player);

			bool RegisterNewPlayer(shgame::logic::Player player);

			void DisposeObjects();

			void acceptLoop();


		public:
			static const int TARGET_TPS = 50;
			static const int MAP_WIDTH = 2100, MAP_HEIGHT = 1400;
			static const int OBSTACKLE_ROWS = 5, OBSTACKLE_LINES = 8;
			static const int OBSTACLE_ROW_DISANCE = MAP_WIDTH / OBSTACKLE_ROWS;
			static const int OBSTACLE_LINE_DISTANCE = MAP_HEIGHT / OBSTACKLE_LINES;
			static const int MAX_PLAYER_COUNT = 20;
			static const int OBSTACLE_COUNT = OBSTACKLE_ROWS * OBSTACKLE_LINES, BULLET_COUNT = 200;

			GameServer() = default;

			GameServer(int port);

			GameServer(asio::ip::address_v4 address, int port);


			byte* onMapRequest(std::byte* packet);

			byte* onPingRequest(byte* packet);

			byte* onRegisterPlayerRequest(byte* packet);

			byte* onExchangePlayerRequest(byte* packet);

			byte* onBulletRequest(byte* packet);


			void stop();

			static address_v4 GetLocalIPv4();

			static address_v6 GetLocalIPv6();

			static address GetLocalIP();
	};
}