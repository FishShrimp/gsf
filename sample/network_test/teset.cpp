#include <stdio.h>
#include <stdint.h>

#include <WinSock2.h>

// �ӿڲ���

class Test1 :
	public gsf::connect_handler,
	public gsf::session_close_handler
{
public :
	// ����Ŀ��������ɹ�
	virtual void handle_new_connection();

	// ���ӶϿ�
	virtual void handle_close();
};


class Test2 :
	public gsf::accept_handler,
	public gsf::session_close_handle
{
public:
	// ���µ�session���ӵ�������
	virtual void handle_new_connection();

	// ���ӶϿ�
	virtual void handle_close();
};


int main()
{

	return 0;
}