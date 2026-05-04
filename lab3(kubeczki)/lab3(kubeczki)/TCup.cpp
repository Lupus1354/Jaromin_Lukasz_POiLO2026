#include "TCup.h"
using namespace std;

void TCup::add(TSubstance substance, double volume_in_ml)
{

	for (int i = 0; i < substances.size(); i++)
	{
		if (substances[i].get_name() == substance.get_name())
		{
			volumes[i] += volume_in_ml / 1e6;
			return;
		}
		
	}


	substances.push_back(substance);
	// volume.push_back(volume_in_ml / 1000 / 1000);
	volumes.push_back(volume_in_ml / 1e6);

}

void TCup::add(std::string name, double volume_in_ml)
{
	int _id = get_substance_id(name);

	if (_id >= 0)
	{
		this->add(substancje[_id], volume_in_ml);
	}
}

int TCup::get_substance_id(string name)
{
	int count = substancje.size();
	int _id = -1;
	bool run = true;

	while (run)
	{
		_id += 1;
		string sub_name = substancje[_id].get_name();

		if (sub_name == name) run = false;

		if ((_id + 1 == count) and (run == true))
		{
			cout << "Nie znaleziono plynu o podanej nazwie: \"" << name << "\"!\n";
			run = false;
			_id = -1;
		}
	}

	return _id;

}

void TCup::show()
{
	int count = substances.size();
	for (int i = 0; i < count; i++)
	{
		double mass = substances[i].get_ro() * volumes[i] * 1000;  //[g]
		cout << substances[i].get_name()
			<< "; volume: " << volumes[i] * 1e6 << " ml"
			<< "; mass: " << mass << " g" << endl;
	}

	// skorzystanie z funkcji get_coe_vol i get_coe_mass
	print_coe_vol();
	print_coe_mass();
	cout << endl;
}




void TCup::print_coe_vol()
{
	cout << "\nYolume coe: ";

	double sumavol = 0;

	for (int i = 0; i < volumes.size(); i++)
	{
		//sumavol += volumes[i];
		sumavol = sumavol + volumes[i];
	}


	for (int i = 0; i < volumes.size(); i++)
	{
		double temp = volumes[i] / sumavol * 100;
		cout << temp << " - ";
	}
	cout << endl;

		

		//for (int i = 0; i < volumes.size(); i++)
		//{
		//	niewiem = volumes[i] / sumavol * 100;
		//}

}


void TCup::print_coe_mass()
{
	cout << "\nMass coe: ";
	//implementacja

	double sumamas = 0;

	for (int i = 0;i < volumes.size(); i++)
	{
		//sumamas =+ (volumes[i] * substances[i].get_ro()) * 1000;
		sumamas = (volumes[i] * substances[i].get_ro() * 1000) + sumamas;
	}


	for (int i = 0;i < volumes.size(); i++)
	{
		double a = (((volumes[i] * substances[i].get_ro()) * 1000 ) / sumamas) * 100 ;

		cout << a << " - ";
	}

	cout << endl;
}
