#include <iostream>
#include <string>

using namespace std;

/* ������� ��������� �������� ��������������� �������� ������� �� ��� �������������, ��� ���
	   � ���������� ������ � ���� �� �������� ��������������� ����� ���������� ������ �������������.
	������������
	   - �������� �������� �������� ������� �� ������ �������� �� ����, �� ����� ������ ������� ������ � ��� ��� ��������� ����� �����;
	   - ������� ��������������� ������ ������������ ��������� ������������� ��������������� �������.
   ����������� �������� ��������� � ��� ����������:
	- ��������� �������� ���������� ������������� ��������
	- ��������� ���, ����������� ��������������� � �������������
	- ���� ����� ������ �������� ��� ��������� ���������������
   */

   /*
		* Pizza (�������) ������������ ������� �������������� ������.
		* ConcreteBuilder ������ ���������� ������������� �������� � ���������� ������� ��� ������.
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
		cout << "������: " + frame + "." << endl;
		cout << "���������(�.�) : " + to_string(engine) + "." << endl;
		cout << "������(R) : " + to_string(wheels) + "." << endl;
		cout<<"�.�.�.(������� �������) : " + gearbox +"\n\n\n";
	}
};

   // Abstract Builder ������ ����������� ��������� (�����) ��� �������� ������ ������� Product (� ����� ������, Pizza);
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

// ConcreteBuilder ��������� ��������� ��������:
// - ������������ � �������� ������ ����� �������� ����������� ���������� ���������� Builder;
// - ���������� ����������� ������������� � ������ �� ���;
// - ������������� ��������� ��� ������� � ��������

class DaewooLanosBuilder : public AutomobileBuilder
{
public:
	void BuildName() override
	{
		automobile.SetName("Daewoo Lanos");
		
	}
	void BuildFrame() override
	{
		automobile.SetFrame("�����");
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
		automobile.SetFrame("����");
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
		automobile.SetFrame("���������");
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






// Director(�������������) - ������������ ������ (Pizza), ��������� ����������� Builder
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










// ������ ������� ������-������������� Director � ������������� ��� ������ ��������-���������� Builder
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