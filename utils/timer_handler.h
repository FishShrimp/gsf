#ifndef _TIMER_HANDLER_HEADER_
#define _TIMER_HANDLER_HEADER_


namespace gsf
{
	namespace utils
	{
		//!��ʱ���������ӿڶ���
		class TimerHandler
		{
		public:
			//!���캯��
			TimerHandler();

			//!��������
			virtual ~TimerHandler();

			//!��ʱ��������
			virtual void handleTimeout() = 0;
		};

		inline TimerHandler::TimerHandler()
		{

		}
		inline TimerHandler::~TimerHandler()
		{

		}

#include "make_timer_handler.h"
	}
}

#endif
