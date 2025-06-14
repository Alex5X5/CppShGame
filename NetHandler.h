#pragma once
namespace shgame::game::net {

	using byte = unsigned char;

#pragma warning disable CS8500 //a pointer is created to a variable of an unmanaged type


	class NetHandler : Socket {

	private:
		/*readonly */IPAddress IP = new([0, 0, 0, 0]);
		/*readonly */int PORT = 100;

		bool stop = false;

		/*readonly */Logger logger = new(new LoggingLevel("NetHandler"));

		bool Connect_(IPAddress address, int port) {
			IPEndPoint point = new(address, port);
			logger.Log("connecting " + point);
			IAsyncResult result = BeginConnect(point, null, null);
			bool success = result.AsyncWaitHandle.WaitOne(10000, true);
			while (!success)
				Thread.Sleep(100);
			logger.Log(Convert.ToString(Connected));
			if (!Connected) {
				EndConnect(result);
				return success;
			}
			else {
				Close();
				throw new SocketException(0, "Connect Timeout");
			}
			return success;
		}

		byte[] RecievePacket() {
			if (!Connected)
				throw new ConnectException("not connected");
			byte[] buffer = new byte[Protocoll.PACKET_BYTE_LENGTH];
			int recieved = 0;
			while (recieved < Protocoll.PACKET_BYTE_LENGTH && !stop) {
				int bytes;
				try {
					bytes = Receive(buffer, recieved, Protocoll.PACKET_BYTE_LENGTH - recieved, SocketFlags.None);
				}
				catch (Exception) {
					break;
				}
				if (bytes == 0)
					break;
				recieved += bytes;
			}
			return buffer;
		}

		void SendPacket(byte[] send) {
			if (send == null)
				throw new ArgumentException("cannot send null");
			try {
				_ = Send(send);
			}
			catch (SocketException e) {
				logger.Error(e.ToString());
			}
		}

	public:
		NetHandler() : this(5000) {
			logger.Log("enpty constructor");
		}

		NetHandler(int port) : this(GameServer.GetLocalIP(), port) {
			logger.Log("port constructor");
		}

		NetHandler(IPAddress address, int port) : base(address.AddressFamily, SocketType.Stream, ProtocolType.Tcp) {
			logger.Log("port addresss constructor");
			logger.Log(address.AddressFamily.ToString());
			IP = IPAddress.Parse("192.168.2.112");
			PORT = port;
			//logger.Log(ToString());
			IPEndPoint point = new(address, port);
			logger.Log(point.ToString());
			try {
				logger.Log("trying to connect, point=" + point.ToString() + ", family=" + point.Address.AddressFamily);
				Connect(point);
			}
			catch (SocketException e) {
				logger.Warn("failed to connect (reason=" + e.ToString() + ")");
			}
			if (Connected)
				logger.Log("connected!");
			else
				logger.Warn("no connection");
		}

		/*unsafe */void GetMap(Client client, ref Obstacle[] obstacles) {
			logger.Log("getting map");
			SendPacket(Protocoll.PreparePacket(Headers.MAP));
			byte[] packet = RecievePacket();
			int counter = 0;
			if (packet != null)
				for (int i = 0; i < GameServer.OBSTACLE_COUNT; i++)
					fixed(byte * ptr = &packet[i * Obstacle.OBSTACLE_BYTE_LENGTH + Protocoll.PAYLOAD_OFFSET])
					Obstacle.DeserializeObstacle(client, ptr, obstacles[i], 0);
			foreach(Obstacle obstacle in obstacles)
				Console.WriteLine(obstacle.ToString());
		}

		/*unsafe */void ExchangePlayers(Player p, ref Player[] players) {
			//logger.Log("exchanging players", [new MessageParameter("player",p.ToString())]);
			byte[] send = Protocoll.PreparePacket(Headers.PLAYER);
			fixed(byte * ptr = &send[0])
				Player.SerializePlayer(ptr, p, Protocoll.PAYLOAD_OFFSET);
			try {
				Send(send);
				byte[] packet = RecievePacket();
				if (packet != null)
					for (int i = 0; i < GameServer.MAX_PLAYER_COUNT; i++) {
						logger.Log("deserializing player", new MessageParameter("player", players[i].ToString()));
						//Player2 temp = new();
						//if (temp != null && temp.PlayerUUID != p.PlayerUUID)
						//players[i] = temp;
						fixed(byte * ptr = &packet[0])
							Player.DeserializePlayer(ptr, players[i], i * Player.PLAYER_BYTE_LENGTH + Protocoll.PAYLOAD_OFFSET);
						logger.Log("deserialized player", new MessageParameter("player", players[i].ToString()));
					}
			}
			catch (Exception e) {
				logger.Log(e.ToString());
			}
		}

		/*unsafe */void GetBullets(Bullet[] bullets) {
			//logger.Log("exchanging players", [new MessageParameter("player",p.ToString())]);
			byte[] send = Protocoll.PreparePacket(Headers.BULLET);
			try {
				Send(send);
				byte[] packet = RecievePacket();
				if (packet != null)
					for (int i = 0; i < GameServer.MAX_PLAYER_COUNT; i++) {
						logger.Log("deserializing player", new MessageParameter("player", bullets[i].ToString()));
						//Player2 temp = new();
						//if (temp != null && temp.PlayerUUID != p.PlayerUUID)
						//players[i] = temp;
						fixed(byte * ptr = &packet[0])
							Bullet.DeserializeBullet(ptr, bullets[i], i * Player.PLAYER_BYTE_LENGTH + Protocoll.PAYLOAD_OFFSET);
						logger.Log("deserialized player", new MessageParameter("player", bullets[i].ToString()));
					}
			}
			catch (Exception e) {
				logger.Log(e.ToString());
			}

		}

		void Stop() {
			logger.Log("stopping");
			stop = true;
			Close();
			Dispose();
		}

		override string ToString() {
			return "sh_game.Game.net.NetHandler:[ip=" + IP.ToString() + ", port=" + Convert.ToString(PORT) + "]";
		}
	};
}