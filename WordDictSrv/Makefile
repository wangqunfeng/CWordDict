########################################################################
TARGET = dict
OBJS = dict.o cworddb.o cwordserver.o eworderror.o

CXX = g++
GDB = gdb
MKDIR = mkdir

CXXFLAGS = -g -std=c++11

SRC = ./src
BIN = ./bin

#######################################################################

all:bin depend $(BIN)/$(TARGET)

$(BIN)/$(TARGET) : $(addprefix $(BIN)/,$(OBJS))
	$(CXX) $(addprefix $(BIN)/,$(OBJS)) $(CXXFLAGS) -o $(BIN)/$(TARGET)

$(addprefix $(BIN)/,$(OBJS)): $(BIN)/%.o : $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(BIN)/.depend

depend: 
	$(CXX) $(CXXFLAGS) -MM ${OBJS:%.o=$(SRC)/%.cpp} > $(BIN)/.depend

bin:
	[ ! -d $(BIN) ] & $(MKDIR) -p $(BIN)

clean:
	rm -rf $(SRC)/*~ $(BIN)/$(TARGET) $(addprefix $(BIN)/,$(OBJS)) $(BIN)/.depend

exec:
	$(BIN)/$(TARGET)

gdb:
	$(GDB) $(BIN)/$(TARGET)
