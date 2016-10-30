#ifndef _GSF_NEWWORK_HEADER_
#define _GSF_NEWWORK_HEADER_

#include <stdint.h>
#include <vector>
#include <memory>

#include "network_config.h"

namespace gsf
{
	class NetworkThread;

	//! ����ģ�������
	class Network
	{
	public:
		Network(const NetworkConfig &config);

		~Network();

		int start();

		int run();

	private:
		//! ��ʼ�������߳�
		int32_t init_work_thread();

		static void worker_thread_process(int32_t fd, int16_t which, void *arg);

	private:

		NetworkThread *main_thread_ptr_;
	
		std::vector<NetworkThread*> worker_thread_vec_;

		const NetworkConfig config_;
	};
}


#endif
