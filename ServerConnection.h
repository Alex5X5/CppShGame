#pragma once

using namespace asio::ip;

namespace shgame::net {

	class ServerConnection {
		private:
			/*readonly*/ tcp::endpoint socket;
			bool stop = false;

			bool ReceivePacket();
			void SendPacket();

			void Run();

		public:
			int disposalCooldown = 100;
			int id;

			ServerConnection(tcp::socket s, /*GameServer gs,*/ int id_);
		
			string to_string();

			void Stop();
	};
}