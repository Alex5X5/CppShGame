#include "Gameserver.h";


void shgame::net::GameServer::OnAccept(tcp::endpoint socket)
{

}

bool shgame::net::GameServer::IsPlayerRegistered(shgame::logic::Player player)
{

}

bool shgame::net::GameServer::RegisterNewPlayer(shgame::logic::Player player)
{

}

void shgame::net::GameServer::DisposeObjects()
{

}

void shgame::net::GameServer::acceptLoop()
{

}

void shgame::net::GameServer::stop()
{

}

shgame::net::GameServer::GameServer() : shgame::net::GameServer::GameServer(5000)
{
	
}

shgame::net::GameServer::GameServer(int port) : shgame::net::GameServer::GameServer(tcp::v4(), port)
{

}

shgame::net::GameServer::GameServer(asio::ip::address_v4 address, int port)
{
	//logger = new Logger(new LoggingLevel("GameServer"));
	//logger.Log(
	//	"address port constructor",
	//	new MessageParameter("address", address),
	//	new MessageParameter("addressFamily", AddressFamily.ToString()),
	//	new MessageParameter("port", port)
	//);
	//create an IPEndpoint with the given address and the given port and bind the server to the IPEndpoint
	endpoint = tcp::endpoint(ip::make_address("192.168.56.1"), 5000);
	acceptor = tcp::acceptor(context, endpoint);
}

byte* shgame::net::GameServer::onMapRequest(byte* packet)
{

}

byte* shgame::net::GameServer::onPingRequest(byte* packet)
{

}

byte* shgame::net::GameServer::onExchangePlayerRequest(byte* packet)
{
	
}

byte* shgame::net::GameServer::onRegisterPlayerRequest(byte* packet)
{

}

byte* shgame::net::GameServer::onBulletRequest(byte* packet)
{

}

address_v4 shgame::net::GameServer::GetLocalIPv4()
{
	
}

address_v6 shgame::net::GameServer::GetLocalIPv6()
{

}

address shgame::net::GameServer::GetLocalIP()
{

}