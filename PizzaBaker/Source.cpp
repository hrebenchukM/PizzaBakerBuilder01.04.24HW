#include <iostream>
#include <string>

using namespace std;

/* Паттерн Строитель отделяет конструирование сложного объекта от его представления, так что
	   в результате одного и того же процесса конструирования могут получаться разные представления.
	Применимость
	   - алгоритм создания сложного объекта не должен зависеть от того, из каких частей состоит объект и как они стыкуются между собой;
	   - процесс конструирования должен обеспечивать различные представления конструируемого объекта.
   Достоинства паттерна строитель и его применения:
	- позволяет изменять внутреннее представление продукта
	- изолирует код, реализующий конструирование и представление
	- дает более тонкий контроль над процессом конструирования
   */

   /*
		* Pizza (продукт) представляет сложный конструируемый объект.
		* ConcreteBuilder строит внутреннее представление продукта и определяет процесс его сборки.
		* */
class Automobile
{
	string name;
	string frame;
	int engine;
	int wheels;
	string gearbox;

public:
	void SetName(string name)
	{
		this->name = name;
	}
	string GetName()
	{
		return this->name;
	}


	void SetFrame(string frame)
	{
		this->frame = frame;
	}
	string GetFrame()
	{
		return this->frame;
	}


	void SetEngine(int engine)
	{
		this->engine = engine;
	}
	int GetEngine()
	{
		return this->engine;
	}



	void SetWheels(int wheels)
	{
		this->wheels = wheels;
	}
	int GetWheels()
	{
		return this->wheels;
	}


	void SetGearbox(string gearbox)
	{
		this->gearbox = gearbox;
	}
	string GetGearbox()
	{
		return this->gearbox;
	}




	void ShowAutomobile()
	{
		cout << "Name of automobile: " + name + "." << endl;
		cout << "Корпус: " + frame + "." << endl;
		cout << "Двигатель(л.с) : " + to_string(engine) + "." << endl;
		cout << "Колеса(R) : " + to_string(wheels) + "." << endl;
		cout<<"К.П.П.(Коробка передач) : " + gearbox +"\n\n\n";
	}
};

   // Abstract Builder задает абстрактный интерфейс (класс) для создания частей объекта Product (в нашем случае, Pizza);
   /** "Abstract Builder" */
class AutomobileBuilder abstract
{
protected:
	Automobile automobile;
public:
	Automobile GetAutomobile()
	{
		return automobile;
	}
	/*string name;
	string frame;
	int engine;
	int wheels;
	string gearbox;*/

	virtual void BuildName() abstract;
	virtual void BuildFrame() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildWheels() abstract;
	virtual void BuildGearbox() abstract;

};

// ConcreteBuilder выполняет следующие действия:
// - конструирует и собирает вместе части продукта посредством реализации интерфейса Builder;
// - определяет создаваемое представление и следит за ним;
// - предоставляет интерфейс для доступа к продукту

class DaewooLanosBuilder : public AutomobileBuilder
{
public:
	void BuildName() override
	{
		automobile.SetName("Daewoo Lanos");
		
	}
	void BuildFrame() override
	{
		automobile.SetFrame("Седан");
	}
	void BuildEngine() override
	{
		automobile.SetEngine(98);
	}

	void BuildWheels() override
	{
		automobile.SetWheels(13);
	}
	void BuildGearbox() override
	{
		automobile.SetGearbox("5 Manual");
	}
};

class FordProbeBuilder : public AutomobileBuilder
{
public:
	void BuildName() override
	{
		automobile.SetName("Ford Probe");

	}
	void BuildFrame() override
	{
		automobile.SetFrame("Купе");
	}
	void BuildEngine() override
	{
		automobile.SetEngine(160);
	}

	void BuildWheels() override
	{
		automobile.SetWheels(14);
	}
	void BuildGearbox() override
	{
		automobile.SetGearbox("4 Auto");
	}
};

class UAZPatriotBuilder : public AutomobileBuilder
{
public:
	void BuildName() override
	{
		automobile.SetName("UAZ Patriot");

	}
	void BuildFrame() override
	{
		automobile.SetFrame("Универсал");
	}
	void BuildEngine() override
	{
		automobile.SetEngine(120);
	}

	void BuildWheels() override
	{
		automobile.SetWheels(16);
	}
	void BuildGearbox() override
	{
		automobile.SetGearbox("4 Manual");
	}
};






// Director(распорядитель) - конструирует объект (Pizza), пользуясь интерфейсом Builder
class Shop
{
	
	AutomobileBuilder* automobileBuilder;
public:


	void SetAutomobileBuilder(AutomobileBuilder* pb)
	{
		automobileBuilder = pb;
	}

	Automobile GetAutomobile()
	{
		return automobileBuilder->GetAutomobile();
	}


	void ConstructAutomobile()
	{
		automobileBuilder->BuildName();
		automobileBuilder->BuildFrame();
		automobileBuilder->BuildEngine();
		automobileBuilder->BuildWheels();
		automobileBuilder->BuildGearbox();
	}
};










// клиент создает объект-распорядитель Director и конфигурирует его нужным объектом-строителем Builder
void client(AutomobileBuilder* builder)
{
	Shop waiter;
	waiter.SetAutomobileBuilder(builder);

	waiter.ConstructAutomobile();

	Automobile automobile = waiter.GetAutomobile();



	automobile.ShowAutomobile();
}



void main()
{

	setlocale(LC_ALL, "Russian");

	AutomobileBuilder* builder = new  DaewooLanosBuilder();
	client(builder);
	delete builder;

	builder = new FordProbeBuilder();
	client(builder);
	delete builder;


	builder = new UAZPatriotBuilder();
	client(builder);
	delete builder;


	system("pause");
}