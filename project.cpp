#include <iostream>
#include <math.h>
#include <vector>
//math.h is used to define M_PI as 3.14159... and for the power and squareroot functions

using namespace std;

int main()
{
	double FRM = 0, FRY = 0, FRX = 0, FRT = 0, F1y = 0, F1x = 0, XF1 = 0, F2x = 0, F2y = 0, XF2 = 0, M1 = 0, XM1 = 0, M2 = 0, XM2 = 0, RDL1 = 0, XRL11 = 0, XRL12 = 0, RDL2 = 0, XRL21 = 0, XRL22 = 0, TF1 = 0, XTF1 = 0, TF2 = 0, XTF2 = 0;
	
	//FRM, FRY, FRX, and FRT are the reaction forces at the wall broken down into the moment about the z axis, y axis, x axis, and a reaction torsion force about the x axis
	//F1x and F1y are the 1st concentrated force x and y components
	//F2x and F2y are the 2nd concentrated force x and y components
	//XF1 and XF2 are the locations that the 2 concentrated force act on the cylinder
	//M1 and M2 are the concentrated moments about the z axis acting on the cylinder
	//XM1 and XM2 are the locations where the concentrated moments are acting on the cylinder
	//TF1 and TF2 are the torsion forces acting on the cylinder at locations XTF1 and XTF2 respectfully
	//RDL1 and RDL2 are the rectangular distributed loads
	//XRL11 and XRL12 are the starting and ending locations for the first rectangular distributed load
	//XRL21 and XRL22 are the starting and ending locations for the second rectangular distributed load
	
	double length = 0, diameter = 0, CSarea = 0, torsionconstant = 0, momentconstant = 0, transverseconstant = 0;
	
	//I used the answer variable as a way of asking the user what forces are present on the cylinder
	
	char answer;
	//		JONATHAN MARTINI INPUTS AND Torsion moment and traverse constants
	//
	//
	cout << "What is the diameter of the cylinder in meters?"<<endl; //Get values for the dimentions of the cylinder.
	cin >> diameter;
	
	while(diameter <= 0)
	{
		cout << "The diameter of the cylinder must be a positive non-zero value.\nEnter another value for the diameter of the cylinder in meters." << endl;
		cin >> diameter;
	}
	
	
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
	

	//END JONATHAN MARTINI

	//Ruby Champlin concentrated forces
	cout << "Is there a concentrated force acting on the cylinder ('y' for yes and 'n' for no)?" << endl;
	cin >> answer;
	
	while(answer != 'y' && answer != 'n')
	{
		cout << "Did not understand input, enter 'y' for yes and 'n' for no." << endl;
		cin >> answer;
	}
	
	if (answer == 'y') //Collecting inputs of concentrated forces on the cylinder.
	{
		cout << "What is the 'x' value of the concentrated load in Newtons? \nPositive values are pointed away from the wall support at x=0." << endl;
		cin >> F1x;
		
		cout << "What is the 'y' value of the concentrated load in Newtons? \nPositive values are pointed up in the oppisite direction of gravity." << endl;
		cin >> F1y;
		
		cout << "At what x value in meters along the cylinder is the concentrated load located?" << endl;
		cin >> XF1;
		
		while (XF1 <= 0 || XF1 > length)
		{
			cout << "The x value for the location of the concentrated load on the cylinder \nmust be a positive, non-zero value that is less than or equal \nto the lenth of the cylinder. \nEnter another value." << endl;
			cin >> XF1;
		}
		
		cout << "Is there another concentrated load acting on the cylinder ('y' for yes and 'n' for no)?" << endl;
		cin >> answer;
		
		while(answer != 'y' && answer != 'n')
		{
			cout << "Could not understand input. \nEnter 'y' for yes and 'n' for no." << endl;
			cin >> answer;
		}
		
		if (answer == 'y')
		{
			cout << "What is the value of the 'x' value of the concentrated load in Newtons? \nNegative values are pointed toward the wall support located at x=0." << endl;
			cin >> F2x;
			
			cout << "What is the value of the 'y' value of the concentrated load in Newtons? \nNegative values are pointed in the oppisite direction of gravity." << endl;
			cin >> F2y;
			
			cout << "At what x value in meters along the cylinder is the concentrated load located?" << endl;
			cin >> XF2;
			
			while (XF2 <= 0 || XF2 > length)
			{
				cout << "The x value for the location of the concentrated load on the cylinder \nmust be a positive non-zero value that is less than or equal to the length of the cylinder. \nEnter another value." << endl;
				cin >> XF2;
			}
		}
	}
	
	// Ruby Champlin

	//Juan Mayz Concentrated Moments

	cout << "Is there a concentrated moment force about the 'z' axis acting on the cylinder ('y' for yes and 'n' for no)?" << endl;
	cin >> answer;
	
	while(answer != 'y' && answer != 'n')
	{
		cout << "Could not understand input, enter 'y' for yes and 'n' for no." << endl;
		cin >> answer;
	}
	
	if(answer == 'y') //Collecting values for concentrated moments on the cylinder.
	{
		cout << "What is the value of the concentrated moment in Newton meters? \nPositive values are rotating counterclockwise." << endl;
		cin >> M1;
		
		cout << "At what x value in meters along the cylinder is the conentrated moment located?" << endl;
		cin >> XM1;
		
		while (XM1 <= 0 || XM1 > length)
		{
			cout << "The x value for the location of the concentrated load on the cylinder must be a positive \nnon-zero value that is less than or equal to the length of the cylinder. \nEnter another value" << endl;
			cin >> XM1;
		}
		
		cout << "Is there another concentrated moment force about the 'z' axis acting on the cylinder ('y' for yes and 'n' for no)?" << endl;
		cin >> answer;
		
		while(answer != 'y' && answer != 'n')
		{
			cout << "Did not understand the input. \nEnter 'y' for yes and 'n' for no." << endl;
			cin >> answer;
		}
		
		if(answer == 'y')
		{
			cout << "What is the value of the concentrated moment in Newton meters? \nPositive values are rotating counterclockwise." << endl;
			cin >> M2;
			
			cout << "At what x value in meters along the cylinder is the conentrated moment located?" << endl;
			cin >> XM2;
			
			while (XM2 <= 0 || XM2 > length)
			{
				cout << "The x value for the location of the concentrated load on the cylinder \nmust be a positive non-zero value that is less than or equal to the lenth of the cylinder.\nEnter another value." << endl;
				cin >> XM2;
			}
		}
	}
	 

	//Juan Mayz

	//Nick Pizzuto Rect Loads

	cout << "Is there a rectangualar distributed load acting on the cylinder ('y' for yes and 'n' for no)?" << endl;
	cin >> answer;
	
	while(answer != 'y' && answer != 'n')
	{
		cout << "Did not understand input, enter 'y' for yes and 'n' for no" << endl;
		cin >> answer;
	}
	
	if(answer == 'y') //Collecting inputs for the distributed loads.
	{
		cout << "What is the value of the distributed load in newtons per meter?" << endl;
		cin >> RDL1;
		
		cout << "At what x value in meters does the distributed load begin?" << endl;
		cin >> XRL11;
		
		cout << "At what x value in meters does the distributed load end?" << endl;
		cin >> XRL12;
		
		while(XRL11 < 0 || XRL12 < XRL12 || XRL12 > length)
		{
			if(XRL11 < 0)
			{
				cout << "The begining and end of the distributed load cannot be less than 0." << endl;
			}
			
			if(XRL12 < XRL11)
			{
				cout << "The x value for the end of the distributed load needs to be the larger value of the two." << endl;
			}
			
			if(XRL12 > length)
			{
				cout << "The distributed load cannot extend past the end of the cylinder." << endl;
			}
			
			cout << "At what x value in meters does the distributed load begin?" << endl;
			cin >> XRL11;
			
			cout << "At what x value in meters does the distributed load end?" << endl;
			cin >> XRL12;
		}
		
		cout << "Is there another rectangular distributed load acting on the cylinder ('y' for yes and 'n' for no)?" << endl;
		cin >> answer;
		
		while(answer != 'y' && answer != 'n')
		{
			cout << "Did not understand input, enter 'y' for yes and 'n' for no." << endl;
			cin >> answer;
		}
		
		if(answer == 'y')
		{
			cout << "What is the value of the distributed load in Newton per meter?" << endl;
			cin >> RDL2;
			
			cout << "At what x value in meters does the distributed load begin?" << endl;
			cin >> XRL21;
			
			cout << "At what x value in meters does the distributed load end?" << endl;
			cin >> XRL22;
			
			while(XRL21 < 0 || XRL22 < XRL12 || XRL22 > length)
			{
				if(XRL21 < 0)
				{
					cout << "The begining and end of the distributed load cannot be less than 0." << endl;
				}
				
				if(XRL22 < XRL21)
				{
					cout << "The x value for the end of the distributed load needs to be the larger value between the two." << endl;
				}
				
				if(XRL22 > length)
				{
					cout << "The distributed load cannot extend past the end of the cylinder." << endl;
				}
				
				cout << "At what x value in meters does the distributed load begin?" << endl;
				cin >> XRL21;
				
				cout << "At what x value in meters does the distributed load end?" << endl;
				cin >> XRL22;
			}
		}
	}
	
	//Nick Pizzuto

	//Tyler Prine Torsion


	cout << "Is there a torsion force about the 'x' axis acting on the cylinder ('y' for yes and 'n' for no)?" << endl;
	cin >> answer;
	
	while(answer != 'y' && answer != 'n')
	{
		cout << "Did not understand input, enter 'y' for yes and 'n' for no." << endl;
		cin >> answer;
	}
	
	if(answer == 'y') //Collecting inputs about torsion forces.
	{
		cout << "What is the value of the torsion force about the 'x' axis in Newton meters? \nPositive values are clockwise." << endl;
		cin >> TF1;
		
		cout << "At what x value in meters along the cylinder is the torsion force acting?" << endl;
		cin >> XTF1;
		
		while(XTF1 < 0 || XTF1 > length)
		{
			cout << "The x value for the location of the torsion force cannot \nbe less than zero or more than the length of the cylinder. \nEnter another value." << endl;
			cin >> XTF1;
		}
		
		cout << "Is there another torsion force about the 'x' axis acting on the cylinder ('y' for yes and 'n' for no)?" << endl;
		cin >> answer;
		
		while(answer != 'y' && answer != 'n')
		{
			cout << "Did not understand input, enter 'y' for yes and 'n' for no." << endl;
			cin >> answer;
		}
		
		if(answer == 'y')
		{
			cout << "What is the value of the torsion force about the 'x' axis in Newton meters? Positive values are clockwise." << endl;
			cin >> TF2;
			
			cout << "At what x value in meters along the cylinder is the torsion force acting?" << endl;
			cin >> XTF2;
			
			while(XTF2 < 0 || XTF2 > length)
			{
				cout << "The x value for the location of the torsion force cannot \nbe less than zero or more than the length of the cylinder. \nEnter another value." << endl;
				cin >> XTF2;
			}
		}
	}
	
	//Tyler Prine

	//James Colvin ME250 stuff

	//Calculating reaction forces at the wall, i multiply each by (0-1) to swap the sign for the reaction force
	
	FRT = (TF1 + TF2) * (0 - 1);
	
	FRX = (F1x + F2x) * (0 - 1);
	
	FRY = (F1y + F2y + (RDL1 * (XRL12 - XRL11)) + (RDL2 * (XRL22 - XRL21))) * (0 - 1);
	
	FRM = ((F1y * XF1) + (F2y * XF2) + ((RDL1 * (XRL12 - XRL11)) * (XRL11 + ((XRL12 - XRL11) / 2))) + ((RDL2 * (XRL22 - XRL21)) * (XRL21 + ((XRL22 - XRL21) / 2)))+M1+M2) * (0 - 1);
	
	double ABNS = 0, ABNSM = 0, ABSS = 0, ABSSM = 0, BBNS = 0, BBNSM = 0, BBSS = 0, BBSSM = 0, maxnormal = 0, maxshear = 0, localVF = 0, localMF = 0, localTF = 0, localAF = 0, maxnormalxlocation = 0, maxshearxlocation = 0, maxnormallocation = 0, maxshearlocation = 0;
	
	double axialstressdirection;  //since the normal stress due to bending can be either positive or negative the max normal stress will be created
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
		
		axialstressdirection = -1;  //resets axial stress direction to assume positive direction
		
		//the if statements are there to determine if the force or moment is being used yet
		//since the cylinder is in static equalibrum at any point the forces and moments on the left
		//equal the ones on the right so these if statement find which forces and moments are acting on the left hand
		//side of localx value and sum them up 
		
		if(XF1 <= localx)
		{
			localVF += F1y;
			localMF += (F1y * (XF1 - localx)); 
			localAF += F1x;
		}
		
		if(XF2 <= localx)
		{
			localVF += F2y;
			localMF += (F2y * (XF2 - localx));
			localAF += F2x;
		}
		
		if(XTF1 <= localx)
		{
			localTF += TF1;
		}
		
		if(XTF2 <= localx)
		{
			localTF += TF2;
		}
		
		if(XRL11 <= localx)
		{
			if(XRL12 <= localx)
			{
				localMF += (RDL1 * (XRL12 - XRL11) * ((XRL11 + ((XRL12 - XRL11) / 2)) - localx));
				localVF += (RDL1 * (XRL12 - XRL11));
			}
			
			else
			{
				localMF += (RDL1 * (localx - XRL11) * ((XRL11 + ((localx - XRL11) / 2)) - localx));
				localVF += (RDL1 * (localx - XRL11));
			}
		}
		
		if(XRL21 <= localx)
		{
			if(XRL22 <= localx)
			{
				localMF += (RDL2 * (XRL22 - XRL21) * ((XRL21 + ((XRL22 - XRL21) / 2)) - localx));
				localVF += (RDL2 * (XRL22 - XRL21));
			}
			
			else
			{
				localMF += (RDL2 * (localx - XRL21) * ((XRL21 + ((localx - XRL21) / 2)) - localx));
				localVF += (RDL2 * (localx - XRL21));
			}
		}
		
		if(XM1 <= localx)
		{
			localMF += M1;
		}
		
		if(XM2 <= localx)
		{
			localMF += M2;
		}
		
		//I set all local forces positive to help find the maximum values of normal and shear stress
		
		if(localAF < 0)
		{
			localAF = localAF * (0 - 1); //this is to let us know that this particalular axial stress is negative
			axialstressdirection = 1;   //we change it to positive anyway to make the math easier but will remember that it should come out negative
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
		
		if(ABNSM > abs(maxnormal))
		{
			maxnormal = ABNSM * axialstressdirection;
			maxnormalxlocation = localx;
			maxnormallocation = 1;
		}
		
		if(ABSSM > maxshear)
		{
			maxshear = ABSSM;
			maxshearxlocation = localx;
			maxshearlocation = 1;
		}
		
		if(BBNSM > abs(maxnormal))
		{
			maxnormal = BBNSM * axialstressdirection;
			maxnormalxlocation = localx;
			maxnormallocation = 2;
		}
		
		if(BBSSM > maxshear)
		{
			maxshear = BBSSM;
			maxshearxlocation = localx;
			maxshearlocation = 2;
		}
	}                 

	// James Colvin

	//Jonathan Martini	outputs

	//Outputs important information that could to used to verify that the code is working as well as determine where it went wrong.
	
	cout << "The reaction force at the wall in the 'y' direction is " << FRY << "N." << endl;
	
	cout << "The reaction force at the wall in the 'x' direction is " << FRX << "N." << endl;
	
	cout << "The reaction torsion force about the 'x' axis at the wall is " << FRT << "Nm." << endl;
	
	cout << "The reaction moment force about the 'z' axis at the wall is " << FRM << "Nm." << endl;
	
	cout << "The max normal stress in the cylinder is " << maxnormal << "Pa at " << maxnormalxlocation << " meters from the wall." << endl;
	
	cout << "The max shear stress in the cylinder is " << maxshear << "Pa at " << maxshearxlocation << " meters from the wall." << endl;
	
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

	// Jonathan Martini outputs

}
