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
	double F, Lc, Lr, I, E, d, v, G, density, maxnc, maxnt, maxs;
	char casenumber, material;
	cout<<"this program takes a cylinder made out of a certain material and\napplies a force to it under a selected loading condition"<<endl;
	cout<<"\n\nIs the cylinder made out of steel(s), aluminum(a), or iron(i)"<<endl;
	cin>>material;
	while(material!='s'&&material!='a'&&material!='i')
	{
		cout<<"\ndid not understand selection, enter 's' for steel, 'a' for aluminum, or 'i' for iron"<<endl;
		cin>>material;
	}
	if (material=='s')
	{
		cout<<"\nthe cylinder is made out of steel"<<endl;
		E=12312;
		v=213123;
		G=2131231;
		density=231232;
		maxnc=123123;
		maxnt=1223123;
		maxs=4142141;
	}
	else if(material=='a')
	{
		cout<<"\nthe cylinder is made out of aluminum"<<endl;
		E=12312;
		v=213123;
		G=2131231;
		density=231232;
		maxnc=123123;
		maxnt=1223123;
		maxs=4142141;
	}
	else if(material=='i')
	{
		cout<<"\nthe cylinder is made out of iron"<<endl;
		E=12312;
		v=213123;
		G=2131231;
		density=231232;
		maxnc=123123;
		maxnt=1223123;
		maxs=4142141;
	}
	cout<<"\n\nwhat is the diameter of the cylinder in meters"<<endl;
	cin>>d;
	while(d<=0)
	{
		cout<<"\nthe diameter must be a positive value larger than 0,\nenter a value for the diameter in meters"<<endl;
		cin>>d;
	}
	cout<<"\n\nwhat is the length of the cylinder in meters"<<endl;
	cin>>Lc;
	while(Lc<=0)
	{
		cout<<"\nthe length of the cylinder must be a positive value larger than 0,\nenter a value for the length of the cylinder in meters"<<endl;
		cin>>Lc;
	}
	cout<<"\n\nwhat is the force being applied in newtons"<<endl;
	cin>>F;
	while(F<0)
	{
		cout<<"the force value must be a positive value,\nenter a positive value for the force in newtons"<<endl;
		cin>>F;
	}
	cout<<"\n\nis the cylinder in a torsion case(t), horizontal loading case(h), or vertical loading case(v)"<<endl;
	cin>>casenumber;
	while(casenumber!='t'&&casenumber!='h'&&casenumber!='v')
	{
		cout<<"\ndid not understand input for selection, enter 't' for a torion case, 'h' for a horizontal loading case, or 'v' for a vertical loading case"<<endl;
		cin>>casenumber;
	}
	cout<<"\n\n";
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
	cout<<"this is the torsion case"<<endl;
	double T, M, I, Lr, ns, ss;
	cout<<"what is the length of the rod connected at the end of the cylinder\nmeasured from the center of the cylinder\nto force vector in meters"<<endl;
	cin>>Lr;
	while(Lr<=0)
	{
		cout<<"\nthe length of the rod must be a positive value larger than 0,\nenter a value for the length of the rod in meters"<<endl;
		cin>>Lr;
	}
	T=F*Lr;
	M=F*Lc;
	I=M_PI*pow(d,4)/32;
	ns=M*d/2/I;
	ss=T*d/2/I;
	if(ns>maxnc)
	{
		cout<<"the cylinder fails due to compressive normal stress"<<endl;
	}
	else if(ns>maxnt)
	{
		cout<<"the cylinder fails due to tensile normal stress"<<endl;
	}
	else if(ss>maxs)
	{
		cout<<"the cylinder fails due to shear stress"<<endl;
	}
	else
	{
		cout<<"the part will not fail,\nthe max normal stress experienced is "<<ns<<"\nand the max ss experienced is "<<ss<<endl;
	}
}
void casetwo(double F, double d, double Lc, double density, double E, double v, double G, double maxnc, double maxnt, double maxs)
{
	cout<<"this is the horizontal loading case"<<endl;
	double w, I, M, r, ns, ss;
	I=M_PI*pow(d,4)/32;
	r=d/2;
	w=density*M_PI*d*d*Lc/4;
	M=(F*Lc)+(w*Lc/2);
	ns=M*r/I;
	ss=(F+w)/(M_PI*d*d/4);
	if(ns>maxnc)
	{
		cout<<"the cylinder will fail due to normal compressive stress"<<endl;
	}
	if(ns>maxnt)
	{
		cout<<"the cylinder will fail due to normal tensile stress"<<endl;
	}
	if(ss>maxs)
	{
		cout<<"the cylinder will fail due to shear stress"<<endl;
	}
}
void casethree(double F, double d, double Lc, double density, double E, double v, double G, double maxnc, double maxnt, double maxs)
{
	cout<<"this is the vertical loading condition"<<endl;
	double I, ns, ss, maxb, Ac;
	Ac=M_PI*d*d/4;
	I=M_PI*pow(d,4)/32;
	maxb=M_PI*M_PI*E*I/4/Lc/Lc;
	ns=F/Ac;
	ss=ns/2;
	if(maxb<F)
	{
		cout<<"the cylinder will buckle under the force"<<endl;
	}
	if(ns>maxnc)
	{
		cout<<"the cylinder fails due to compressive forces"<<endl;
	}
	if(ss<=maxs&&maxb<=F&&ns<=maxnc)
	{
		cout<<"the cylinder will not buckle under the Force applied"<<endl;
		cout<<"the max normal stress acting on the cylinder is "<<ns<<endl;
		cout<<"the max shear stress acting on the cylinder is "<<ss<<endl;
	}
	if(ss>maxs)
	{
		cout<<"the cylinder will fail due to the shear stress"<<endl;
	}
}
