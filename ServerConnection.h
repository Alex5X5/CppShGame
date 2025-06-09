#pragma once

#include "asio.hpp"
#include "GameServer.h"

using namespace asio::ip;
using namespace shgame::game::net;

namespace shgame::game::net {

	class ServerConnection {
		private:
			/*readonly*/ tcp _socket;
			bool stop = false;

			bool ReceivePacket();
			void SendPacket();

			void Run(shgame::net::GameServer gs);

		public:
			int disposalCooldown = 100;
			int id;

			ServerConnection(tcp::socket s, /*GameServer gs,*/ int id_);
		
			string to_string();

			void Stop();
	};
}