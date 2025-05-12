NAME		= type
CC			= c++
FLAGS		= -Wall -Werror -Wextra -std=c++11

CFILES 		= 	main.cpp Base.cpp A.cpp B.cpp C.cpp
				
			  	
OFILES  	= $(CFILES:.cpp=.o) 


%.o			: %.cpp
			@	$(CC) $(FLAGS) -c $< -o $@

$(NAME)		: $(OFILES)
			@	$(CC) $(FLAGS) -o $(NAME) $(OFILES)
			@ echo "made"

all			: $(NAME)

clean		:
			@	rm -f $(OFILES) 
			@ echo "cleaned up"


fclean		: clean
			@rm -f $(NAME)
			@ echo "files cleaned f-style!"

re			: fclean all
			@echo "re-ed up"

.PHONY		: all clean fclean re
