//zadanie1
#include <iostream>

class Engine {
public:
	Engine() { std::cout << "Двигатель создан\n"; }

	~Engine() { std::cout << "Двигатель уничтожен\n"; }

	void run() { std::cout << "Двигатель запущен\n"; }


};

class Car {
private:
	Engine engine;

public:
	Car() : engine() { std::cout << "Создание машины\n"; }

	void start() {
		std::cout << "Запуск машины...\n";
		engine.run();
	}

};


int main() {
	setlocale(LC_ALL, "ru");
	Car car1;
	car1.start();



}
