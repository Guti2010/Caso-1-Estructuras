all: comm_progs

comm_progs:
	g++ -o news.o doublelist.cpp -lcurl
	./news.o

# docker run -it --rm -v "/c/Users/windows/Documents/Caso 1 Estr:/home" gcc bash
# apt update -y
# apt install curl
