TARGET := calc
OBJECTS := hash.o linkedlist.o variable.o

CFLAGS += -ansi -pedantic-errors
CPPFLAGS += -Wall -Wextra -Werror -Og -ggdb

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJECTS)