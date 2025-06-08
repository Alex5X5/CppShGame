#pragma once

#include "asio.hpp"

namespace shgame::game::net {
	using asio::ip::tcp;
	//using system;
	//using system::net::sockets;
	//using system::threading;
	//using system::threading::tasks;

	class ServerConnection {
	private:
		/*readonly*/ tcp _socket;
		bool stop = false;
		/*readonly*/ Logger logger;

		bool ReceivePacket(ref byte[] buffer) {
			if (!_socket.Connected)
				return false;

			Array.Resize(ref buffer, Protocoll.PACKET_BYTE_LENGTH);
			buffer.Initialize();

			int received = 0;
			while (received < Protocoll.PACKET_BYTE_LENGTH && !stop) {
				int bytes;
				try {
					bytes = _socket.Receive(buffer, received, Protocoll.PACKET_BYTE_LENGTH - received, SocketFlags.None);
				}
				catch (Exception) {
					return false;
				}
				if (bytes == 0)
					break;

				received += bytes;
			}
			return received >= Protocoll.PACKET_BYTE_LENGTH;
		}

		void SendPacket(byte[] ? send) {
			if (send == null)
				return;
			_ = _socket.Send(send);
		}

		void Run(GameServer gs) {
			logger.Log("run");
			byte[] buffer = new byte[Protocoll.PACKET_BYTE_LENGTH];
			while (!stop) {
				try {
					if (!ReceivePacket(ref buffer))
						continue;

					switch (Protocoll.AnalyzePacket(buffer)) {
					case Headers.PING:
						SendPacket(gs.OnPingRequest(buffer));
						break;
					case Headers.PLAYER:
						SendPacket(gs.OnPlayerRequest(buffer));
						break;
					case Headers.MAP:
						SendPacket(gs.OnMapRequest());
						break;
					default:
						Console.WriteLine("[ServerConnection]: Unknown protocol type (protocol.type=" + Protocoll.AnalyzePacket(buffer) + ")");
						break;
					}
				}
				catch (SocketException e) {
					logger.Error(e.Message);
					disposalCooldown--;
					break;
				}
			}
		}

	public:
		int disposalCooldown = 100;
		/*readonly*/ int id;

		ServerConnection(tcp::socket s, /*GameServer gs,*/ int id_) {
			_socket = s;
			logger = new Logger(new LoggingLevel("ServerConnection"));
			logger.Log("Constructor");
			id = id_;
			//Task.Run(() = > Run(gs));
		}

		override string ? ToString() = > socket.ToString();

		void Stop() {
			logger.Log("stopping");
			stop = true;
			socket.Close();
			socket.Dispose();
		}
	};
}