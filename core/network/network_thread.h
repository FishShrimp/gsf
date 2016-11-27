#ifndef _GSF_NETWORK_THREAD_HEADER_
#define _GSF_NETWORK_THREAD_HEADER_


#include <event2/event.h>

#include <vector>
#include <unordered_map>

#include <stdint.h>
#include <memory>
#include <thread>

#include "session_mgr.h"
#include "network_connect.h"


namespace gsf
{
	namespace network
	{
		//! ����buffer��������֤�߼��������Ż�Ϊ�������У�lockfree | ringbuffer ...)

		class IBuffer
		{
		public:
			void mark_produce(uint32_t session_id, evbuffer *buff);

			//! ����������Ϣ��䵽ringbuff
			void produce();

			//! �����߳�ȡ��ringbuff
			void consume(std::vector<std::pair<uint32_t, evbuffer*>> &vec);

		private:
			//! produce list
			std::vector<std::pair<uint32_t, evbuffer*>> ibuffer_vec_;
			std::vector<std::pair<uint32_t, evbuffer*>> consume_vec_;
			
			std::mutex mtx;
		};

		class OBuffer
		{

		};

		struct NetworkThread
		{
			NetworkThread(int index);
			~NetworkThread();

			std::thread *th;

			event_base *event_base_ptr_;

			event *notify_event_;

			evutil_socket_t notify_receive_fd_;
			evutil_socket_t notify_send_fd_;

			CQ *connect_queue_;

			IBuffer *in_buffer_;
			OBuffer *out_buffer_;

			SessionMgr *session_mgr;

			int index_;
		};
	}
	
}

#endif
