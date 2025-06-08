#pragma once
#include "asio.hpp";
#include "Client.h";
#include "Drawable.h";
#include "ServerConnection.h"
#include "Player.h"

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

			void OnAccept(tcp::endpoint socket);

			bool IsPlayerRegistered(Player player);

			bool RegisterNewPlayer(Player player);

			void DisposeObjects();

			void ClockLoop();

			void AcceptLoop();


		public:
			static const int TARGET_TPS = 50;
			static const int MAP_WIDTH = 2100, MAP_HEIGHT = 1400;
			static const int OBSTACKLE_ROWS = 5, OBSTACKLE_LINES = 8;
			static const int OBSTACLE_ROW_DISANCE = MAP_WIDTH / OBSTACKLE_ROWS;
			static const int OBSTACLE_LINE_DISTANCE = MAP_HEIGHT / OBSTACKLE_LINES;
			static const int MAX_PLAYER_COUNT = 20;
			static const int OBSTACLE_COUNT = OBSTACKLE_ROWS * OBSTACKLE_LINES, BULLET_COUNT = 200;

			GameServer();

			GameServer(int port);

			GameServer(asio::ip::address address, int port);


			byte* OnMapRequest();

			byte* OnPingRequest(byte* packet);

			byte* OnPlayerRequest(byte* packet);


			void Stop();

			static address_v4 GetLocalIPv4();

			static address_v6 GetLocalIPv6();

			static address GetLocalIP();
	};
}