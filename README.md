# SFML Pendulum
## Simple C++ pendulum animation for windows using SFML.
Follow the steps below for running it

First download the repository, we need the SFML library and the dlls
```bash
git clone https://github.com/ghidella/pendulum
```
In the pendulum folder, compile with:
```bash
g++ -Isrc/include -c main.cpp
```
Now, you must link the compiled file to the SFML libraries in order to get the final executable with the following command:
```bash
g++ main.o -o pendulum -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
```
It's done, just run it
```bash
./pendulum.exe
```
