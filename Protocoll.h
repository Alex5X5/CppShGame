#pragma once

namespace ShGame::Game::Net {

	using byte = unsigned char;

	static class Protocoll {

	public:
		const byte PING_HEADER = 1, PLAYER_HEADER = 11, MAP_HEADER = 3;
		const short PACKET_BYTE_LENGTH = 2000, PAYLOAD_OFFSET = 1;


		static byte AnalyzePacket(byte[] packet) {
			return packet[0];
		}

		static byte[] PreparePacket(byte typeID) {
			byte[] packet = new byte[PACKET_BYTE_LENGTH];
			packet[0] = typeID;
			return packet;
		}

		static int UnloadMessage(byte[] packet) {
			byte[] temp = new byte[8];
			Array.ConstrainedCopy(packet, 0, temp, 0, 8);
			return BitConverter.ToInt32(temp);
		}

		static byte[] LoadPing(bool answer) {
			byte[] result = PreparePacket(Headers.PING);
			BitConverter.GetBytes(answer).CopyTo(result, 5);
			return result;
		}

		static bool UnloadPing(byte[] packet) = >
			AnalyzePacket(packet) == Headers.PING;
	};

	class Headers {
	public:
		const byte PING = 1;
		const byte ABORT_CONNECTION = 2;
		const byte MAP = 5;
		const byte PLAYER = 6;
		const byte ABILITY = 7;
		const byte BULLET = 8;
		const byte PAYER_LIMIT = 11;
	};
}