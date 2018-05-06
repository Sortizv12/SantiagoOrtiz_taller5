placas.png : placas.cpp grafica.py
	g++ placas.cpp
	./a.out > matriz.txt
	python grafica.py

