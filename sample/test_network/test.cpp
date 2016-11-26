#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#include <sys/types.h>

#include <event2/event-config.h>
#include <event2/event.h>

#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#endif // WIN32

#include <network.h>
#include <acceptor.h>

#include <session.h>
#include <session_mgr.h>

#include <iostream>

#include <random>
#include <timer.h>
#include <timer_handler.h>

/*
class PlayerSession : public SessionHandler
{
public:
virtual void connect();
virtual void disconnect();

virtual void recv();
virtual void write();
};

class Player
{

}
*/

class LoginServerHandler : 
	public gsf::network::AcceptHandler
{
public:
    virtual ~LoginServerHandler(){}

    //! new connection bind session to message dispatch
    virtual void handler_new_connection(int session_id)
    {
		printf("new connection session_id : %d\n", session_id);
    }
};


//! user interface test
/*
	class LoginHandler : 
		public AcceptHandler,
		public SessionCloseHandler
	{
		public:
			virtual void handle_new_connection(int acceptor_id, int session_id)
			{
				gsf::SessionMgr::instance().open(session_id, this);
			}
			
			vittual void handle_close(int session_id
				, int err_code
				, int acceptor_id
				, int connector_id
				, const std::string &ip
				, const int port);
	}

	class Login2GameHandler :
		public ConnectHandler,
		public SessionCloseHandler
	{
		public:
			virtual void handle_new_connection(int connector_id, int session_id)
			{
				gsf::SessionMgr::instance().open(session_id, this);
			}

			virtual void handle_connect_failed(int connector_id, int err_code, const std::string &ip, const int port);

			vittual void handle_close(int session_id
			, int err_code
			, int acceptor_id
			, int connector_id
			, const std::string &ip
			, const int port);
	}

	class LoginTimeoutHandler : public TimeOutHandler
	{
		public:
			virtual void time_out(int thread_id, int overtime_time);
	}

	------init------
	gsf::NetworkConfig _config(...);
	gsf::Network::instance().init(_config);

	gsf::MessageSessionBinder<T>::instance();

	//accept
	gsf::AcceptorConfig _acceptor_config(...);
	int _acceptor_id = gsf::AcceptorMgr::instance().make_acceptor(&_acceptor_config);
	if (acceptor_id < 0){
		//err
	}

	if (gsf::AcceptorMgr::instance().open(_acceptor_id, new LoginHandler()) < 0){
		//err
	}

	//connect
	gsf::ConnectorConfig _gameserver_connector_config(...);
	int _connector_id = gsf::ConnectorMgr::instance().make_connector(&_gameserver_connector_config);
	if (_connector_id < 0){
		//err
	}

	if (gsf::ConnectorMgr::instance().open(_connector_id, new Login2GameHandler() < 0){
		//err
	}

	gsf::Network::instance().start(new LoginTimeoutHandler());
	-----decode-----

	class ModuleDecode
	{
		void regist()
		{
			gsf::MessageSessionBinder<T>::instance().bind(message_id, &class::func);
		}
	}
*/


int main()
{
#ifdef WIN32
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(1, 1);
	int result = WSAStartup(wVersionRequested, &wsaData);
	if (result != 0){
		exit(1);
	}
#endif // WIN32

	using namespace gsf::network;

	NetworkConfig _config;
	Network::instance().init(_config);
    
	AcceptorConfig _acceptConfig;
	_acceptConfig.port = 8888;

	if (Network::instance().make_acceptor(_acceptConfig, new LoginServerHandler()) < 0){
		//err
	}

	gsf::network::Network::instance().start();

	return 0;
}
