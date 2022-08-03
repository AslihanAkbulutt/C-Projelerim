hepsi: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/AVL.cpp -o ./lib/AVL.o
	g++ -c -I "./include" ./src/DogruKuyrugu.cpp -o ./lib/DogruKuyrugu.o
bagla:
	g++ ./lib/DogruKuyrugu.o ./lib/Dugum.o ./lib/AVL.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program