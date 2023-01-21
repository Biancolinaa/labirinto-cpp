LD = g++

SRC = src
OBJ = dist/obj

SOURCES = $(shell find $(SRC) -name '*.cpp')
OBJECTS = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SOURCES))

BIN = dist/maze
CFLAGS = -Wall -O2 -std=c++11

all: $(BIN)

setup: force
force:
	$(foreach filename, $(OBJECTS), $(shell mkdir -p `dirname $(filename)`))
	@echo 'Setup complete'

$(BIN): $(OBJECTS)
	$(LD) $^ $(CFLAGS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	@rm -f $(OBJECTS)
	@rm -f $(BIN)
