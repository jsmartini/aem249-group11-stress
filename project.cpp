#include <iostream>
#include <cmath>
using namespace std;
int main(){
	// First line of double variables are all of the inputed and reaction forces on the cylinder and set them equal to 0
	double FRM=0, FRY=0, FRX=0, FRT=0, F1y=0, F1x=0, XF1=0, F2x=0, F2y=0, XF2=0, M1=0, XM1=0, M2=0, XM2=0, RDL1=0, XRL11=0, XRL12=0, RDL2=0, XRL21=0, XRL22=0, UDTL=0, TF1=0, XTF1=0, TF2=0, XTF2=0;
	// Second line of double variables define the properties of the cylinder
	double length, diameter, CSarea, torsionconstant, momentconstant, transverseconstant;
	//third line of variables are used for orgainizing inputed values 
	char answer;
	cout<<"what is the diameter of the cylinder in meters"<<endl;
	cin>>diameter;
	while(diameter<=0){
		cout<<"the diameter of the cylinder must be a positive non-zero value,\nenter another value for the diameter of the cylinder"<<endl;
		cin>>diameter;
	}
	cout<<"what is the length of the cylinder in meters"<<endl;
	cin>>length;
	while (length<=0){
		cout<<"the lenght of the cylinder must be a positive non-zero value,\nenter another value for the length of the cylinder in meters"<<endl;
		cin>>length;
	}
	CSarea = diameter*diameter*M_PI*0.25;
	momentconstant = 32/(M_PI*pow(diameter,3));
	torsionconstant = 16/(M_PI*pow(diameter,3));
	transverseconstant = 4/(3*M_PI*pow(diameter/2,2));
	cout<<"Is there a concentrated force acting on the cylinder(y,n)"<<endl;
	cin>>answer;
	while(answer!= 'y' && answer != 'n'){
		cout<<"did not understand input, enter 'y' for yes and 'n' for no"<<endl;
		cin>>answer;
	}
	if (answer== 'y'){         // collecting inputs of concentrated forces on the cylinder
		cout<<"what is the 'x' value of the concentrated load in Newtons.  positive values are pointed away from the wall support @ x=0"<<endl;
		cin>>F1x;
		cout<<"what is the 'y' value of the concentrated load in Newtons.  positive values are pointed up in the oppisite direction of gravity"<<endl;
		cin>>F1y;
		cout<<"at what x value in meters along the cylinder is the concentrated load located?"<<endl;
		cin>>XF1;
		while (XF1<=0 or XF1>length){
			cout<<"the x value for the location of the concentrated load on the cylinder must be a positive non-zero value that is less than or equal to the lenth of the cylinder,\nenter another value"<<endl;
			cin>>XF1;
		}
		cout<<"is there another concentrated load acting on the cylinder(y,n)"<<endl;
		cin>>answer;
		while(answer!= 'y' && answer != 'n'){
			cout<<"did not understand input, enter 'y' for yes and 'n' for no"<<endl;
			cin>>answer;
		}
		if (answer== 'y'){
			cout<<"what is the value of the 'x' value of the concentrated load in Newtons.  positive values are pointed away from the wall support or first pin located @ x=0"<<endl;
			cin>>F2x;
			cout<<"what is the value of the 'y' value of the concentrated load in Newtons.  positive values are pointed up in the oppisite direction of gravity"<<endl;
			cin>>F2y;
			cout<<"at what x value in meters along the cylinder is the concentrated load located?"<<endl;
			cin>>XF2;
			while (XF2<=0 or XF2>length){
				cout<<"the x value for the location of the concentrated load on the cylinder must be a positive non-zero value that is less than or equal to the lenth of the cylinder,\nenter another value"<<endl;
				cin>>XF2;
			}
		}
	}
	cout<<"is there a concentrated moment force about the 'z' axis acting on the cylinder?(y,n)"<<endl;
	cin>>answer;
	while(answer!= 'y' && answer != 'n'){
		cout<<"did not understand input, enter 'y' for yes and 'n' for no"<<endl;
		cin>>answer;
	}
	if(answer== 'y'){    //collecting values for concentrated moments on the cylinder
		cout<<"what is the value of the concentrated moment in Newton meters? positive values are rotating counterclockwise"<<endl;
		cin>>M1;
		cout<<"at what x value in meters along the cylinder is the conentrated moment located?"<<endl;
		cin>>XM1;
		while (XM1<=0 or XM1>length){
			cout<<"the x value for the location of the concentrated load on the cylinder must be a positive non-zero value that is less than or equal to the lenth of the cylinder,\nenter another value"<<endl;
			cin>>XM1;
		}
		cout<<"is there another concentrated moment force about the 'z' axis acting on the cylinder?(y,n)"<<endl;
		cin>>answer;
		while(answer!= 'y' && answer != 'n'){
			cout<<"did not understand input, enter 'y' for yes and 'n' for no"<<endl;
			cin>>answer;
		}
		if(answer== 'y'){
			cout<<"what is the value of the concentrated moment in Newton meters? positive values are rotating counterclockwise"<<endl;
			cin>>M2;
			cout<<"at what x value in meters along the cylinder is the conentrated moment located?"<<endl;
			cin>>XM2;
			while (XM2<=0 or XM2>length){
				cout<<"the x value for the location of the concentrated load on the cylinder must be a positive non-zero value that is less than or equal to the lenth of the cylinder,\nenter another value"<<endl;
				cin>>XM2;
			}
		}
	}
	cout<<"is there a rectangualr distributed load acting on the cylinder(y,n)"<<endl;
	cin>>answer;
	while(answer!= 'y' && answer != 'n'){
		cout<<"did not understand input, enter 'y' for yes and 'n' for no"<<endl;
		cin>>answer;
	}
	if(answer=='y'){               //collecting inputs for the distributed loads
		cout<<"what is the value of the distributed load in newtons per meter"<<endl;
		cin>>RDL1;
		cout<<"at what x value in meters does the distributed load begin"<<endl;
		cin>>XRL11;
		cout<<"at what x value in meters does the distributed load end"<<endl;
		cin>>XRL12;
		cout<<"is there another rectangular distributed load acting on the cylinder(y,n)"<<endl;
		while(answer!= 'y' && answer != 'n'){
			cout<<"did not understand input, enter 'y' for yes and 'n' for no"<<endl;
			cin>>answer;
		}
		if(answer=='y'){
			cout<<"what is the value of the distributed load in newtons per meter"<<endl;
			cin>>RDL2;
			cout<<"at what x value in meters does the distributed load begin"<<endl;
			cin>>XRL21;
			cout<<"at what x value in meters does the distributed load end"<<endl;
			cin>>XRL22;
		}
	}
	cout<<"is there a torsion force about the 'x' axis acting on the cylinder(y,n)"<<endl;
	cin>>answer;
	while(answer!= 'y' && answer != 'n'){
		cout<<"did not understand input, enter 'y' for yes and 'n' for no"<<endl;
		cin>>answer;
	}
	if(answer=='y'){
		cout<<"what is the value of the torsion force about the 'x' axis in Newton meters? positive values are clockwise"<<endl;
		cin>>TF1;
		cout<<"at what x value in meters along the cylinder is the torsion force acting?"<<endl;
		cin>>XTF1;
		cout<<"is there another torsion force about the 'x' axis acting on the cylinder?(y,n)"<<endl;
		cin>>answer;
		while(answer!= 'y' && answer != 'n'){
			cout<<"did not understand input, enter 'y' for yes and 'n' for no"<<endl;
			cin>>answer;
		}
		if(answer=='y'){
			cout<<"what is the value of the torsion force about the 'x' axis in Newton meters? positive values are clockwise"<<endl;
			cin>>TF2;
			cout<<"at what x value in meters along the cylinder is the torsion force acting?"<<endl;
			cin>>XTF2;
		}
	}
	FRT=TF1+TF2;
	FRX=(F1x+F2x)*(0-1);
	FRY=(F1y+F2y+(RDL1*(XRL12-XRL11))+(RDL2*(XRL22-XRL21)))*(0-1);
	FRM=((F1y*XF1)+(F2y*XF2)+((RDL1*(XRL12-XRL11))*(XRL11+((XRL12-XRL11)/2)))+((RDL2*(XRL22-XRL21))*(XRL11+((XRL12-XRL11)/2))))*(0-1);
	double ABNS=0, ABNSM=0, ABSS=0, ABSSM=0, BBNS=0, BBNSM=0, BBSS=0, BBSSM=0, maxstress=0, maxstrain=0;
	double localVF=0, localMF=0, localTF=0, localAF=0, maxstressxlocation=0, maxstrainxlocation=0, maxstresslocation=0, maxstrainlocation=0;
	for(double localx=0; localx<=length;localx+=.01){
		localVF=FRY;
		localMF=FRM+(FRY*(0-localx));
		localTF=FRT;
		localAF=FRX;
		if(XF1<=localx){
			localVF+=F1y;
			localMF+=(F1y*(XF1-localx));
			localAF+=F1x;
		}
		if(XF2<=localx){
			localVF+=F2y;
			localMF+=(F2y*(XF2-localx));
			localAF+=F2x;
		}
		if(XTF1<=localx){
			localTF+=TF1;
		}
		if(XTF2<=localx){
			localTF+=TF2;
		}
		if(XRL11<=localx){
			if(XRL12<=localx){
				localMF+=(RDL1*(XRL12-XRL11)*((XRL11+((XRL12-XRL11)/2))-localx));
				localVF+=(RDL1*(XRL12-XRL11));
			}
			else{
				localMF+=(RDL1*(localx-XRL11)*((XRL11+((localx-XRL11)/2))-localx));
				localVF+=(RDL1*(localx-XRL11));
			}
		}
		if(XRL21<=localx){
			if(XRL22<=localx){
				localMF+=(RDL2*(XRL22-XRL21)*((XRL21+((XRL22-XRL21)/2))-localx));
				localVF+=(RDL2*(XRL22-XRL21));
			}
			else{
				localMF+=(RDL2*(localx-XRL21)*((XRL21+((localx-XRL21)/2))-localx));
				localVF+=(RDL2*(localx-XRL21));
			}
		}
		if(XM1<=localx){
			localMF+=M1;
		}
		if(XM2<=localx){
			localMF+=M2;
		}
		if(localAF<0){
			localAF=localAF*-1;
		}
		if(localVF<0){
			localVF=localVF*-1;
		}
		if(localMF<0){
			localMF=localMF*-1;
		}
		if(localTF<0){
			localTF=localTF*-1;
		}
		ABNS=((localAF)/CSarea)+(localMF*momentconstant);
		ABSS=localTF*torsionconstant;
		BBNS=localAF/CSarea;
		BBSS=(localTF*torsionconstant)+(localVF*transverseconstant);
		ABNSM=(ABNS/2)+sqrt(pow(ABNS/2,2)+pow(ABSS,2));
		ABSSM=sqrt(pow(ABNS/2,2)+pow(ABSS,2));
		BBNSM=(BBNS/2)+sqrt(pow(BBNS/2,2)+pow(BBSS,2));
		BBSSM=sqrt(pow(BBNS/2,2)+pow(BBSS,2));
		if(ABNSM>maxstress){
			maxstress=ABNSM;
			maxstressxlocation=localx;
			maxstresslocation=1;
		}
		if(ABSSM>maxstrain){
			maxstrain=ABSSM;
			maxstrainxlocation=localx;
			maxstrainlocation=1;
		}
		if(BBNSM>maxstress){
			maxstress=ABNSM;
			maxstressxlocation=localx;
			maxstresslocation=2;
		}
		if(BBSSM>maxstrain){
			maxstrain=ABSSM;
			maxstrainxlocation=localx;
			maxstrainlocation=2;
		}
	}
	cout<<"The reaction force at the wall in the 'y' direction is "<<FRY<<"N"<<endl;
	cout<<"The reaction force at the wall in the 'x' direction is "<<FRX<<"N"<<endl;
	cout<<"The reaction torsion force about the 'x' axis at the wall is "<<FRT<<"Nm"<<endl;
	cout<<"The reaction moment force about the 'z' axis at the wall is "<<FRM<<"Nm"<<endl;
	cout<<"The max stress in the cylinder is "<<maxstress<<"Pa at "<<maxstressxlocation<<"meters from the wall"<<endl;
	cout<<"The max strain in the cylinder is "<<maxstrain<<"Pa at "<<maxstrainxlocation<<"meters from the wall"<<endl;
	if(maxstresslocation==1){
		cout<<"the max stress is located on the top or bottom of the cylinder"<<endl;	
	}
	if(maxstresslocation==2){
		cout<<"the max strain is located on the left or right side of the cylinder"<<endl;	
	}
	if(maxstrainlocation==1){
		cout<<"the max strain is located on the top or bottom of the cylinder"<<endl;	
	}
	if(maxstrainlocation==2){
		cout<<"the max strain is located on the left or right side of the cylinder"<<endl;	
	}
}
