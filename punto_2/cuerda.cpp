#include <iostream>
#include <math.h>

using namespace std;

const float T=40.0;
const float p=10.0;
const float L=100.0;
const float c=sqrt(T/p);
const int nt=2000;
const int nx=400;
const float dx=L/nx;
const float dt=0.1;//0.6*dx/c;
const float r2=pow(dt*c/dx,2);
float x[nx];
float u_in[nx];
float u_fut[nx];
float u_past[nx];
float u_pres[nx];
void evolve(void);

int main()
{
	
	x[0]=0.0;
	cout << x[0]<< " ";
	for(int i=1;i<nx;i++)
	{
		x[i]=x[0]+i*dx;
		cout <<x[i]<<" ";
	}
	cout << endl;
	//Condiciones de frontera
	for(int j=0;j<nt;j++)
	{
		u_in[0]=0;
		u_in[nx-1]=0;
		u_fut[0]=0;
		u_fut[nx-1]=0;
	}
	//Condiciones iniciales
	for(int i=0;i<nx;i++)
	{
		if(x[i]<=0.8*L)
		{
			u_in[i]=1.25*x[i]/L;
		}
		else if(x[i]>0.8*L)
		{
			u_in[i]=5-(5*x[i]/L);
		}
	}
	
	for(int i=1;i<nx-1;i++)
	{
		u_fut[i]=u_in[i] + (r2/2.0)*(u_in[i+1] - 2.0*u_in[i] + u_in[i-1]);
	}

	evolve();
	return 0;
}


void evolve(void)
{
	for(int i=0;i<nx;i++)
	{
		cout <<u_in[i]<<" ";
	}
	cout << endl;
	for(int i=0;i<nx;i++)
	{
		u_past[i]=u_in[i];
		u_pres[i]=u_fut[i];
	}
	
	for(int j=0;j<nt;j++)
	{
		for(int i=1;i<nx-1;i++)
		{
			u_fut[i]=(2.0*(1-r2))*u_pres[i] - u_past[i] + r2*(u_pres[i+1] + u_pres[i-1]);
		}
		for(int i=0;i<nx;i++)
		{
			cout << u_pres[i]<< " ";
			u_past[i]=u_pres[i];
			u_pres[i]=u_fut[i];
		}
		cout << endl;
	}
	
	
}

