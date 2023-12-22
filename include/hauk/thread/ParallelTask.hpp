//
// Created by hauk on 2023-12-22.
//

#ifndef HAUK_THREAD_PARALLELTASK_HPP
#define HAUK_THREAD_PARALLELTASK_HPP

namespace hauk::thread
{

	class ParallelTask
	{
	public:
		ParallelTask();
		void execute();
		bool isFinished();
		float getCompletion();
	private:
		void runTask();

		sf::Thread m_thread;
		bool m_finished;
		sf::Clock m_elapsedTime;
		sf::Mutex m_mutex;
	};

} // hauk::thread

#endif //HAUK_THREAD_PARALLELTASK_HPP
