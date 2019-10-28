#include <fstream>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void caseone(double,double,double,double,double,double,double,double,double,double);
void casetwo(double,double,double,double,double,double,double,double,double,double);
void casethree(double,double,double,double,double,double,double,double,double,double);

int main()
{
	double F = 0, Lc = 0, Lr = 0, I = 0, E = 0, d = 0, v = 0, G = 0, density = 0, maxnc = 0, maxnt = 0, maxs = 0;
	char casenumber, material;
	
	cout << "This program takes a cylinder made out of a certain material and \n applies a force to it under a selected loading condition"<<endl;
	cout << "\n\n Is the cylinder made out of steel(s), aluminum(a), or iron(i)" << endl;
	cin >> material;
	
	while(material!='s'&& material!='a'&& material!='i')
	{
		cout << "\n Did not understand selection, enter 's' for steel, 'a' for aluminum, or 'i' for iron"<<endl;
		cin >> material;
	}
	
	if (material=='s')
	{
		cout << "\n The cylinder is made out of steel" << endl;
		E = 12312;
		v = 213123;
		G = 2131231;
		density = 231232;
		maxnc = 123123;
		maxnt = 1223123;
		maxs = 4142141;
	}
	
	else if(material=='a')
	{
		cout << "\n The cylinder is made out of aluminum" << endl;
		E = 12312;
		v = 213123;
		G = 2131231;
		density = 231232;
		maxnc = 123123;
		maxnt = 1223123;
		maxs = 4142141;
	}
	
	else if(material=='i')
	{
		cout << "\n The cylinder is made out of iron" << endl;
		E = 12312;
		v = 213123;
		G = 2131231;
		density = 231232;
		maxnc = 123123;
		maxnt = 1223123;
		maxs = 4142141;
	}
	
	cout << "\n\n What is the diameter of the cylinder in meters" << endl;
	cin >> d;
	
	while(d<=0)
	{
		cout << "\n The diameter must be a positive value larger than 0,\n enter a value for the diameter in meters" << endl;
		cin >> d;
	}
	
	cout << "\n\n What is the length of the cylinder in meters" << endl;
	cin >> Lc;
	
	while(Lc<=0)
	{
		cout << "\n The length of the cylinder must be a positive value larger than 0,\nenter a value for the length of the cylinder in meters" << endl;
		cin >> Lc;
	}
	
	cout << "\n\n What is the force being applied in newtons" << endl;
	cin >> F;
	
	while(F<0)
	{
		cout << "The force value must be a positive value,\nenter a positive value for the force in newtons"<<endl;
		cin >> F;
	}
	
	cout << "\n\n Is the cylinder in a torsion case(t), horizontal loading case(h), or vertical loading case(v)" << endl;
	cin >> casenumber;
	
	while(casenumber!='t'&&casenumber!='h'&&casenumber!='v')
	{
		cout << "\n Did not understand input for selection, enter 't' for a torion case, 'h' for a horizontal loading case, or 'v' for a vertical loading case" << endl;
		cin >> casenumber;
	}
	
	cout << "\n\n";
	
	if(casenumber=='t')
	{
		caseone(F,d,Lc,density,E,v,G,maxnc,maxnt,maxs);
	}
	
	else if(casenumber=='h')
	{
		casetwo(F,d,Lc,density,E,v,G,maxnc,maxnt,maxs);
	}
	
	else if(casenumber=='v')
	{
		casethree(F,d,Lc,density,E,v,G,maxnc,maxnt,maxs);
	}
	
	return 0;
}

void caseone(double F, double d, double Lc, double density, double E, double v, double G, double maxnc, double maxnt, double maxs)
{
	cout << "This is the torsion case" << endl;
	
	double T = 0, M = 0, I = 0, Lr = 0, ns = 0, ss = 0;
	cout << "What is the length of the rod connected at the end of the cylinder \n measured from the center of the cylinder \n to force vector in meters" << endl;
	cin >> Lr;
	
	while(Lr<=0)
	{
		cout << "\n The length of the rod must be a positive value larger than 0, \n enter a value for the length of the rod in meters" << endl;
		cin >> Lr;
	}
	
	T = F * Lr;
	M = F * Lc;
	I = M_PI * pow(d,4) / 32;
	ns = M * d / 2 / I;
	ss = T * d / 2 / I;
	
	if(ns>maxnc)
	{
		cout << "The cylinder fails due to compressive normal stress" << endl;
	}
	else if(ns>maxnt)
	{
		cout << "The cylinder fails due to tensile normal stress" << endl;
	}
	else if(ss>maxs)
	{
		cout << "The cylinder fails due to shear stress" << endl;
	}
	else
	{
		cout << "The part will not fail,\nthe max normal stress experienced is " << ns << "\n and the max ss experienced is " << ss << endl;
	}
}
void casetwo(double F, double d, double Lc, double density, double E, double v, double G, double maxnc, double maxnt, double maxs)
{
	cout << "This is the horizontal loading case" << endl;
	
	double w = 0, I = 0, M = 0, r = 0, ns = 0, ss = 0;
	
	I = M_PI * pow(d,4) / 32;
	r = d / 2;
	w = density * M_PI * d * d * Lc / 4;
	M= (F * Lc) + (w * Lc / 2);
	ns = M * r / I;
	ss = (F + w) / (M_PI * d * d / 4);
	
	if(ns>maxnc)
	{
		cout << "The cylinder will fail due to normal compressive stress" << endl;
	}
	
	if(ns>maxnt)
	{
		cout << "The cylinder will fail due to normal tensile stress" << endl;
	}
	
	if(ss>maxs)
	{
		cout << "The cylinder will fail due to shear stress" << endl;
	}
}
void casethree(double F, double d, double Lc, double density, double E, double v, double G, double maxnc, double maxnt, double maxs)
{
	cout << "This is the vertical loading condition" << endl;
	
	double I = 0, ns = 0, ss = 0, maxb = 0, Ac = 0;
	Ac = M_PI * d * d/4;
	I = M_PI * pow(d,4) / 32;
	maxb = M_PI * M_PI * E * I / 4 / Lc / Lc;
	ns = F / Ac;
	ss = ns / 2;
	
	if(maxb<F)
	{
		cout << "The cylinder will buckle under the force" << endl;
	}
	
	if(ns>maxnc)
	{
		cout << "The cylinder fails due to compressive forces" << endl;
	}
	
	if(ss<=maxs&&maxb<=F&&ns<=maxnc)
	{
		cout << "The cylinder will not buckle under the Force applied" << endl;
		cout << "The max normal stress acting on the cylinder is " << ns << endl;
		cout << "The max shear stress acting on the cylinder is " << ss << endl;
	}
	
	if(ss>maxs)
	{
		cout << "The cylinder will fail due to the shear stress" << endl;
	}		
}
