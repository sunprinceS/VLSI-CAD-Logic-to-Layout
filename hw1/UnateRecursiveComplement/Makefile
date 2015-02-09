CXX    = g++
CFLAGS = -g -Wall
EXEC   = urpComp

urpComp:BooleanEngine.o main.cpp
	@$(CXX) $(CFLAGS) -o $(EXEC) main.cpp BooleanEngine.o
BooleanEngine.o:BooleanEngine.h BooleanEngine.cpp
	@$(CXX) $(CFLAGS) -c BooleanEngine.cpp
clean:
	@rm -f *.o 
	@rm -f *.log
	@rm -f *~
	@echo "Removing $(EXEC)..."
	@rm -f $(EXEC)
	

