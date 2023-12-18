//
// Created by hauk on 2023-12-18.
//

#ifndef HAUK_STATE_H
#define HAUK_STATE_H



namespace hauk::game::states
{

	class State
	{
	public:
		struct Context
		{
			Context()
			{
				std::cout << "Context" << std::endl;
			}
		};
	};

} // hauk::game::states

#endif //HAUK_STATE_H
