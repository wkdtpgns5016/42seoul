#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		std::string msg_level[4];
	
	public:
		Harl();
		void complain(std::string level);
		int	get_index_level(std::string level);
};

#endif