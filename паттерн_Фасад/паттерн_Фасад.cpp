#include <iostream>
using namespace std;

/* Реализовать паттерн "Фасад". 
Предметная область - использование стиральной машины.*/

// подсистема кнопок управления 
class ControlButtons 
{
	public:
	void Start() { cout << "Starting the washing machine" << endl; }
	void Pause() { cout << "Pausing the washing machine" << endl; }
	void Stop() { cout << "Stopping the washing machine" << endl; }
};
// подсистема программы стирки
class WashingProgram 
{
	public:
	void QuickWash() { cout << "Starting quick wash program" << endl; }
	void NormalWash() { cout << "Starting normal wash program" << endl; }
	void DelicateWash() { cout << "Starting delicate wash program" << endl; }
};
// подсистема дозатора моющего средства
class DetergentDispenser 
{
	public:
	void Load() { cout << "Loading detergent into the dispenser" << endl; }
	void Unload() { cout << "Removing unused detergent from the dispenser" << endl; }
};
// Фасад для управления стиральной машиной
class WashingMachineFacade 
{
	ControlButtons* controlButtons;
	WashingProgram* washingProgram;
	DetergentDispenser* detergentDispenser;

	public:
	WashingMachineFacade() 
	{
		// Инициализация подсистем
		controlButtons = new ControlButtons();
		washingProgram = new WashingProgram();
		detergentDispenser = new DetergentDispenser();
	}
	void StartNormalWash()
	{
		controlButtons->Start();
		washingProgram->NormalWash();
		detergentDispenser->Load();
	}
	void StartQuickWash() 
	{
		controlButtons->Start();
		washingProgram->QuickWash();
		detergentDispenser->Load();
	}
	void StartDelicateWash() 
	{
		controlButtons->Start();
		washingProgram->DelicateWash();
		detergentDispenser->Load();
	}
	void Stop() 
	{
		controlButtons->Stop();
		detergentDispenser->Unload();
	}
	~WashingMachineFacade() 
	{
		// Очистка ресурсов
		delete controlButtons;
		delete washingProgram;
		delete detergentDispenser;
	}
};

int main() 
{
	
	// Создание интерфейса для работы с стиральной машиной
	WashingMachineFacade* washingMachine = new WashingMachineFacade();

	// Запуск стиральной программы
	washingMachine->StartNormalWash();
	cout << "-----------------" << endl;

	// Запуск быстрой стирки
	washingMachine->StartQuickWash();
	cout << "-----------------" << endl;

	// Запуск деликатной программы стирки
	washingMachine->StartDelicateWash();
	cout << "-----------------" << endl;

	// Остановка стиральной машины и выгрузка остатков моющего средства
	washingMachine->Stop();

	// Очистка ресурсов
	delete washingMachine;

	return 0;
}
