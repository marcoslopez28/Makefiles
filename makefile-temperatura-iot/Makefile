CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = temperatura
SRCS = main.c
OBJS = $(SRCS:.c=.o)

.PHONY: all run clean rebuild help

all: $(TARGET)

help:
	@echo "Comandos disponibles:"
	@echo " mingw32-make        -> compila el programa"
	@echo " mingw32-make run    -> compila y ejecuta"
	@echo " mingw32-make clean  -> elimina archivos generados"
	@echo " mingw32-make rebuild -> limpia y recompila"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	del /Q $(OBJS) $(TARGET).exe 2>nul || exit 0

rebuild: clean all