NAME 		= PmergeMe

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 #-fsanitize=thread

RM			= rm
RMFLAGS		= -f

INCLUDE		= ./

SRCS		= main.cpp	\
			  PmergeMe.cpp

OBJS		= $(SRCS:%.cpp=%.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

clean		:
			$(RM) $(RMFLAGS) $(OBJS)

fclean 		: 
			$(MAKE) clean
			$(RM) $(RMFLAGS) $(NAME)

re 			: 
			$(MAKE) fclean
			$(MAKE) all

.PHONY		: all clean fclean re