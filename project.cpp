#include <iostream>
#include <math.h>
//math.h is used to define M_PI as 3.14159... and for the power and squareroot functions

using namespace std;

int main()
{
	double FRM = 0, FRY = 0, FRX = 0, FRT = 0;
	
	int numberofconcentratedloads=0, numberofdistributedloads=0, numberofmoments=0, numberoftorques=0;
	
	
	/*
	Fx and Fy are the x and y components of the conenctrated forces
	XF is the location of the concentrated forces
	M are the moments about the z-axis
	XM is the locations of the moments about the z-axis
	RDL are the rectangular distributed loads
	XRDL1 and XRDL2 are the begining and ending values of the distributed loads
	T is the torsion forces
	XT are the locations of the torsion forces
	*/

	// JONATHAN MARTINI csarea diameter length moment torsion transverse constants


	double length = 0, diameter = 0, CSarea = 0, torsionconstant = 0, momentconstant = 0, transverseconstant = 0;
	
	//I used the answer variable as a way of asking the user what forces are present on the cylinder
	
	cout << "What is the diameter of the cylinder in meters? \n(This veritical diameter will extend vertically in the y direction and in the z direction into and out of the page)"<<endl; //Get values for the dimentions of the cylinder.
	cin >> diameter;
	
	while(diameter <= 0)
	{
		cout << "The diameter of the cylinder must be a positive non-zero value.\nEnter another value for the diameter of the cylinder in meters." << endl;
		cin >> diameter;
	}
	
	cout << "What is the length of the cylinder in meters? \n(This length will be treated as the x direction)" << endl;
	cin >> length;
	
	while (length <= 0)
	{
		cout << "The length of the cylinder must be a positive non-zero value.\nEnter another value for the length of the cylinder in meters." << endl;
		cin >> length;
	}
	
	CSarea = diameter * diameter * M_PI * 0.25;  //Solve for constants based on the diminsions of the cylinder.
	
	//these constants are based on the initial formulas for moment stresses, torsion train, and transverse shear stress
	//I calcualted a portion of the formulas as constants to make solving for the stresses and strains less complicated in the for loop
	
	momentconstant = 32 / (M_PI * pow(diameter, 3));
	
	torsionconstant = 16 / (M_PI * pow(diameter, 3));
	
	transverseconstant = 16 / (3 * M_PI * pow(diameter , 2));
	

	// Jonathan Martini


	//Tyler Prine Concentrated Forces

	cout << "How many concentrated forces are acting on the cylinder?" << endl;
	cin >> numberofconcentratedloads;
	double Fx[numberofconcentratedloads], Fy[numberofconcentratedloads], XF[numberofconcentratedloads];
	
	for(int x=0; x<numberofconcentratedloads;x++)
	{
		cout << "What is the 'x' value of the concentrated load in Newtons? \nPositive values are pointed away from the wall support at x=0." << endl;
		cin >> Fx[x];
		
		cout << "What is the 'y' value of the concentrated load in Newtons? \nPositive values are pointed up in the oppisite direction of gravity." << endl;
		cin >> Fy[x];
		
		cout << "At what x value in meters along the cylinder is the concentrated load located?" << endl;
		cin >> XF[x];
		
		while (XF[x] <= 0 || XF[x] > length)
		{
			cout << "The x value for the location of the concentrated load on the cylinder \nmust be a positive, non-zero value that is less than or equal \nto the lenth of the cylinder. \nEnter a value between 0 and " << length << endl;
			cin >> XF[x];
		}
		FRX+=Fx[x]*-1;
		FRY+=Fy[x]*-1;
		FRM+=Fy[x]*XF[x]*-1;
	}
		
	//Concentrated Moments Ruby Champlin

	cout << "How many concentrated Moments about the z-axis are there?" << endl;
	cin >> numberofmoments;
	double M[numberofmoments], XM[numberofmoments];
	for(int x=0;x<numberofmoments;x++)
	{
		cout << "What is the value of the concentrated moment in Newton meters? \nPositive values are rotating counterclockwise." << endl;
		cin >> M[x];
		
		cout << "At what x value in meters along the cylinder is the conentrated moment located?" << endl;
		cin >> XM[x];
		
		while (XM[x] <= 0 || XM[x] > length)
		{
			cout << "The x value for the location of the concentrated load on the cylinder must be a positive \nnon-zero value that is less than or equal to the length of the cylinder. \nEnter a value between 0 and " << length << endl;
			cin >> XM[x];
		}
		FRM+=M[x]*-1;
	}
	
	// Ruby Champlin
	 
	//Nick Pizzuto Rect Load

	cout << "How many distributed loads are acting on the cylinder?" << endl;
	cin >> numberofdistributedloads;
	double RDL[numberofdistributedloads], XRDL1[numberofdistributedloads], XRDL2[numberofdistributedloads];
	for(int x=0;x<numberofdistributedloads;x++)
	{
		cout << "What is the value of the distributed load in newtons per meter?" << endl;
		cin >> RDL[x];
		
		cout << "At what x value in meters does the distributed load begin?" << endl;
		cin >> XRDL1[x];
		
		cout << "At what x value in meters does the distributed load end?" << endl;
		cin >> XRDL2[x];
		
		while(XRDL1[x] < 0 || XRDL2[x] < XRDL1[x] || XRDL2[x] > length)
		{
			if(XRDL1[x] < 0)
			{
				cout << "The begining and end of the distributed load cannot be less than 0." << endl;
			}
			
			if(XRDL2[x] < XRDL1[x])
			{
				cout << "The x value for the end of the distributed load needs to be the larger value of the two." << endl;
			}
			
			if(XRDL2[x] > length)
			{
				cout << "The distributed load cannot extend past the end of the cylinder. Input a value less than "<<length<< endl;
			}
			
			cout << "At what x value in meters does the distributed load begin?" << endl;
			cin >> XRDL1[x];
			
			cout << "At what x value in meters does the distributed load end?" << endl;
			cin >> XRDL2[x];
		}
		FRY+=RDL[x]*(XRDL2[x]-XRDL1[x])*-1;
		FRM+=RDL[x]*(XRDL2[x]-XRDL1[x])*(XRDL1[x]+((XRDL2[x]-XRDL1[x])/2))*-1;
	}
	
	//Nick Pizzuto
	

	//Juan Mayz Torsion

	cout << "How many Torsion forces are acting on the cylinder?" << endl;
	cin >> numberoftorques;
	double T[numberoftorques], XT[numberoftorques];
	for(int x=0;x<numberoftorques;x++)
	{
		cout << "What is the value of the torsion force about the 'x' axis in Newton meters? \nPositive values are clockwise." << endl;
		cin >> T[x];
		
		cout << "At what x value in meters along the cylinder is the torsion force acting?" << endl;
		cin >> XT[x];
		
		while(XT[x] < 0 || XT[x] > length)
		{
			cout << "The x value for the location of the torsion force cannot \nbe less than zero or more than the length of the cylinder. \nEnter a value between 0 and " << length << endl;
			cin >> XT[x];
		}
		FRT+=T[x]*-1;
	}
		
	//Jaun Mayz

	//Calculating reaction forces at the wall, i multiply each by (0-1) to swap the sign for the reaction force
	
	//James Colvin ME250 math

	double ABNS = 0, ABNSM = 0, ABSS = 0, ABSSM = 0, BBNS = 0, BBNSM = 0, BBSS = 0, BBSSM = 0, maxnormal = 0, maxshear = 0, localVF = 0, localMF = 0, localTF = 0, localAF = 0, maxnormalxlocation = 0, maxshearxlocation = 0, maxnormallocation = 0, maxshearlocation = 0;
	
	double localaxialstressdirection=-1, maxstressdirection=-1;  //since the normal stress due to bending can be either positive or negative the max normal stress will be created
								  //in the same direction as the axial stress
	
	for(double localx = 0; localx <= length; localx += (length/100000))
	{
		
		//the local variables are the forces and moments found at each location
		//the for loop starts at x=0 and goes till x=length which would be end of the cylinder
		//at each location or "localx" the shear force(localVF), axial force(localAF), moment about
		// the z-axis(localMF), and torsion force about the x-axis(localTF) are calulated
		
		localVF = FRY;
		localMF = FRM + (FRY * (0 - localx));
		localTF = FRT;
		localAF = FRX;
		
		localaxialstressdirection = -1;  //resets axial stress direction to assume positive direction
		
		//the if statements are there to determine if the force or moment is being used yet
		//since the cylinder is in static equalibrum at any point the forces and moments on the left
		//equal the ones on the right so these if statement find which forces and moments are acting on the left hand
		//side of localx value and sum them up 
		for(int x=0;x<numberofconcentratedloads;x++)
		{
			if(XF[x] <= localx)
			{
				localVF += Fy[x];
				localMF += (Fy[x] * (XF[x] - localx)); 
				localAF += Fx[x];
			}
		}
		
		for(int x=0;x<numberoftorques;x++)
		{
			if(XT[x] <= localx)
			{
				localTF += T[x];
			}
		}
		
		for(int x=0;x<numberofdistributedloads;x++)
		{
			if(XRDL1[x] <= localx)
			{
				if(XRDL2[x] <= localx)
				{
					localMF += (RDL[x] * (XRDL2[x] - XRDL1[x]) * ((XRDL1[x] + ((XRDL2[x] - XRDL1[x]) / 2)) - localx));
					localVF += (RDL[x] * (XRDL2[x] - XRDL1[x]));
				}
				
				else
				{
					localMF += (RDL[x] * (localx - XRDL1[x]) * ((XRDL1[x] + ((localx - XRDL1[x]) / 2)) - localx));
					localVF += (RDL[x] * (localx - XRDL1[x]));
				}
			}
		}
		
		for(int x=0;x<numberofmoments;x++)
		{		
			if(XM[x] <= localx)
			{
				localMF += M[x];
			}
		}
				
		//I set all local forces positive to help find the maximum values of normal and shear stress
		
		if(localAF < 0)
		{
			localAF = localAF * (0 - 1); //this is to let us know that this particalular axial stress is negative
			localaxialstressdirection = 1;   //we change it to positive anyway to make the math easier but will remember that it should come out negative
		}
		
		if(localVF < 0)
		{
			localVF = localVF * (0 - 1);
		}
		
		if(localMF < 0)
		{
			localMF = localMF * (0 - 1);
		}
		
		if(localTF < 0)
		{
			localTF = localTF * (0 - 1);
		}
		
		//here is where i use the locally calulated forces and moments to find the stress and strains
		//the two locations where a maximum stress or strain will occur is either on the top and bottom or the sides of the cylinder
		//ABNS is the normal stress located at the top or bottom of the cylinder at each localx
		//BBNS is the normal stress located on the sides of the cylinder at each localx
		//ABSS and BBSS are the shear stresses at either the top or bottom or sides of the cylinder at each localx
		
		ABNS = ((localAF) / CSarea) + (localMF * momentconstant);
		
		ABSS = localTF * torsionconstant;
		
		BBNS = localAF / CSarea;
		
		BBSS = (localTF * torsionconstant) + (localVF * transverseconstant);
		
		//after the normal stress and shear stress are found at each localx the max principle stress and max shear stress are found
		//the maxes are caluated using mohrs circle
		//ABNSM is the max normal stress on the top or bottom
		//ABSSM is the max shear stress on the top or bottom
		//BBNSM and BBSSM are the max normal and shear stress and the sides
		
		ABNSM = (ABNS / 2) + sqrt(pow(ABNS / 2, 2) + pow(ABSS, 2));
		
		ABSSM = sqrt(pow(ABNS / 2, 2) + pow(ABSS, 2));
		
		BBNSM = (BBNS / 2) + sqrt(pow(BBNS / 2, 2) + pow(BBSS, 2));
		
		BBSSM = sqrt(pow(BBNS / 2, 2) + pow(BBSS, 2));
		
		//these if statements determine if the localx max shear and nomal strains are larger than the previous maxes
		// if they are they replace them as the new maxnormal and maxshear
		
		if(ABNSM > maxnormal)
		{
			maxnormal = ABNSM;
			maxnormalxlocation = localx;
			maxnormallocation = 1;
			maxstressdirection = localaxialstressdirection;
		}
		
		if(ABSSM > maxshear)
		{
			maxshear = ABSSM;
			maxshearxlocation = localx;
			maxshearlocation = 1;
		}
		
		if(BBNSM > abs(maxnormal))
		{
			maxnormal = BBNSM;
			maxnormalxlocation = localx;
			maxnormallocation = 2;
			maxstressdirection = localaxialstressdirection;
		}
		
		if(BBSSM > maxshear)
		{
			maxshear = BBSSM;
			maxshearxlocation = localx;
			maxshearlocation = 2;
		}
	}                 

	//James Colvin

	//Jon Martini outputs

	//Outputs important information that could to used to verify that the code is working as well as determine where it went wrong.
	
	cout << "The reaction force at the wall in the 'y' direction is " << FRY << " N." << endl;
	
	cout << "The reaction force at the wall in the 'x' direction is " << FRX << " N." << endl;
	
	cout << "The reaction torsion force about the 'x' axis at the wall is " << FRT << " Nm." << endl;
	
	cout << "The reaction moment force about the 'z' axis at the wall is " << FRM << " Nm." << endl;
	
	cout << "The max normal stress in the cylinder is " << maxnormal * maxstressdirection << " Pa at " << maxnormalxlocation << " meters from the wall." << endl;
	
	cout << "The max shear stress in the cylinder is " << maxshear << " Pa at " << maxshearxlocation << " meters from the wall." << endl;
	
	if(maxnormallocation == 1)
	{
		cout << "The max normal stress is located on the top or bottom of the cylinder." << endl;	
	}
	
	if(maxnormallocation == 2)
	{
		cout << "The max normal stress is located on the left or right side of the cylinder." << endl;	
	}
	
	if(maxshearlocation == 1)
	{
		cout << "The max shear stress is located on the top or bottom of the cylinder." << endl;	
	}
	
	if(maxshearlocation == 2)
	{
		cout << "The max shear stress is located on the left or right side of the cylinder" << endl;	
	}
}
