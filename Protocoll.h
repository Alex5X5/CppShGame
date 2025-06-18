#pragma once

namespace shgame::net {

	using byte = unsigned char;

	static class Protocoll {

	public:
		static const short PACKET_BYTE_LENGTH = 2000, PAYLOAD_OFFSET = 1;

		static inline byte AnalyzePacket(byte* packet);

		static inline byte* PreparePacket(byte typeID);

		static inline int UnloadMessage(byte* packet);

		static inline byte* LoadPing(bool answer);

		static inline bool UnloadPing(byte* packet);
	};

	class Headers {
	public:
		static const byte PING = 1;
		static const byte ABORT_CONNECTION = 2;
		static const byte MAP = 5;
		static const byte PLAYER = 6;
		static const byte ABILITY = 7;
		static const byte BULLET = 8;
		static const byte PAYER_LIMIT = 11;
	};
}