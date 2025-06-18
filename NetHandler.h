#pragma once
#include "Player.h"
#include "Bullet.h"
namespace shgame::net {

	using byte = unsigned char;

	class NetHandler
	{
		private:
			int PORT = 100;

			bool stop = false;

			void SendPacket(unsigned char* packet);

		public:
			NetHandler();

			NetHandler(int port);

			//NetHandler(IPAddress address, int port);

			//void GetMap(Client client, Obstacle* obstacles);

			void ExchangePlayers(shgame::logic::Player* controlledPlayer, shgame::logic::Player* allPlayers);

			void GetBullets(shgame::logic::Bullet* bullets);

			void Stop();

			string ToString(); //return "sh_game.Game.net.NetHandler:[ip=" + IP.ToString() + ", port=" + Convert.ToString(PORT) + "]";
	};
}