NAME		= btc

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

RM			= rm
RMFLAGS		= -f

INCLUDE		= ./

SRCS		= main.cpp \
			  #BitcoinExchange.cpp

OBJS		= $(SRCS:%.cpp=%.o)

all 		: $(NAME)

$(NAME)		: $(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

clean 		:
			$(RM) $(RMFLAGS) $(OBJS)

fclean 		: clean
			$(RM) $(RMFLAGS) $(NAME)

re 			: fclean all

.PHONY : all clean fclean re
