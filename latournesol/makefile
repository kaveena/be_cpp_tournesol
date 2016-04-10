CXX = g++
CXXFLAGS = -c -Wall
LDFLAGS = -lmraa

projet: actionneur.o capteur.o tournesol.o fonction_tourne.o ecran.o main.o
	$(CXX) -o latournesol actionneur.o capteur.o tournesol.o fonction_tourne.o ecran.o main.o $(LDFLAGS)

actionneur.o: actionneur.hpp type.hpp actionneur.cpp
	$(CXX) $(CXXFLAGS) actionneur.cpp

capteur.o: capteur.hpp type.hpp capteur.cpp
	$(CXX) $(CXXFLAGS) capteur.cpp

tournesol.o: tournesol.hpp tournesol.cpp capteur.hpp actionneur.hpp
	$(CXX) $(CXXFLAGS) tournesol.cpp

fonction_tourne.o: fonction_tourne.hpp fonction_tourne.cpp tournesol.hpp
	$(CXX) $(CXXFLAGS) fonction_tourne.cpp

ecran.o: ecran.hpp
	$(CXX) $(CXXFLAGS) ecran.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
clean:
	rm -f *.o ; rm -f projet
