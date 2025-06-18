#include "Gameserver.h"
#include <iostream>

using namespace asio::ip;

shgame::net::GameServer::GameServer() : shgame::net::GameServer::GameServer(5000)
{
	
}

shgame::net::GameServer::GameServer(int port) : shgame::net::GameServer::GameServer(ip::make_address_v4("192.168.56.1"), port)
{

}

shgame::net::GameServer::GameServer(asio::ip::address_v4 address, int port) : 
	_context(),
	_acceptor(_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
{
	//create an IPEndpoint with the given address and the given port and bind the server to the IPEndpoint
	
	// Create an endpoint listening on port 12345
	//tcp::endpoint endpoint(tcp::v4(), 12345);

	// Create and open the acceptor
	_endpoint = tcp::endpoint(asio::ip::tcp::v4(), port);
	
	_acceptor.set_option(asio::ip::tcp::acceptor::reuse_address(true));
	_acceptor.open(_endpoint.protocol());
	_acceptor.bind(_endpoint);
	_acceptor.listen();

	// Create and open the
	std::cout << "Server listening on port 12345..." << std::endl;
}

void shgame::net::GameServer::onAccept(tcp::endpoint socket)
{

}

bool shgame::net::GameServer::isPlayerRegistered(shgame::logic::Player player)
{
	return false;
}

bool shgame::net::GameServer::registerNewPlayer(shgame::logic::Player player)
{
	return false;
}

void shgame::net::GameServer::disposeObjects()
{

}

void shgame::net::GameServer::acceptLoop()
{

}

void shgame::net::GameServer::callStop()
{

}

byte* shgame::net::GameServer::onMapRequest(byte* packet)
{
	return nullptr;
}

byte* shgame::net::GameServer::onPingRequest(byte* packet)
{
	return nullptr;
}

byte* shgame::net::GameServer::onExchangePlayerRequest(byte* packet)
{
	return nullptr;
}

byte* shgame::net::GameServer::onRegisterPlayerRequest(byte* packet)
{
	return nullptr;
}

byte* shgame::net::GameServer::onBulletRequest(byte* packet)
{
	return nullptr;
}

address_v4 shgame::net::GameServer::GetLocalIPv4()
{
	return address_v4();
}

address_v6 shgame::net::GameServer::GetLocalIPv6()
{
	return address_v6();
}

address shgame::net::GameServer::GetLocalIP()
{
	return address_v4();
}