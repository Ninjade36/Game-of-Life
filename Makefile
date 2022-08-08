BIN = game
SOURCES = main.c game.c io.c
# -----------------------------
CFLAGS = -g -std=c99 -Wall
LDFLAGS = -lm
CC = gcc
LD = gcc
OBJECTS = $(SOURCES:.c=.o)
DEPS = $(OBJECTS:.o=.d)

all: $(BIN)

$(BIN): $(OBJECTS)
	@echo "Linking: $@"
	$(LD) $^ -o $@ $(LDFLAGS)

%.o: %.c
	@echo "Compiling: $< to $@"
	$(CC) $(CFLAGS) -MP -MMD -c $< -o $@

-include $(DEPS)

.PHONY: clean
clean:
	@echo "Cleaning..."
	rm -f $(BIN) $(OBJECTS) $(DEPS)
