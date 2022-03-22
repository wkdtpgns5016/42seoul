CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =
SRC_DIR = ./src
OBJ_DIR = .
TARGET = rush-02
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJS = $(SRCS:.c=.o)
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))
DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)
.PHONY: all clean fclean re
clean:
	rm -f *.o *.d
fclean: clean
	rm -f $(TARGET)
re: fclean all
test:
	norminette

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -MD $(LDFLAGS)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

-include $(DEPS)
