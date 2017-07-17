OBJPATH = ./obj
EXECPATH = ./bin
SRCPATH = .
CC = g++

EXEC = $(EXECPATH)/Proxy
OBJS = $(OBJPATH)/ProxyImage.o $(OBJPATH)/Image.o $(OBJPATH)/main.o

all: dir build

dir:
	mkdir -p $(OBJPATH)
	mkdir -p $(EXECPATH)

build: $(OBJS) $(EXEC)

$(EXEC):$(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/ProxyImage.o: $(SRCPATH)/ProxyImage.cpp
	$(CC) -g -c $< -o $@

$(OBJPATH)/Image.o: $(SRCPATH)/Image.cpp
	$(CC) -g -c $< -o $@

$(OBJPATH)/main.o: $(SRCPATH)/main.cpp
	$(CC) -g -c $< -o $@

clean:
	-rm -rf $(EXEC) $(OBJS)