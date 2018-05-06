#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

const float L=5.0;
const float l=2.0;
const float d=1.0;
const float h=5.0/512.0;
const float Vo=100.;
const int n=L/h; 
const int N=2*pow(n,2);
const int w=1.5;
float V[n][n];
float Vold[n][n];
float Vnew[n][n];
float Ex[n][n];
float Ey[n][n];
float x[n];
float y[n];
void solveLaplaceEq(void);
void calculateField(void);

int main()
{
	//Se forman los arreglos de posicion	
	x[0]=0;
	y[0]=0;
	cout << x[0]<< " ";
	for(int i=1;i<n;i++)
	{
		x[i]=x[0]+ i*h;
		y[i]=y[0]+ i*h;
		cout << x[i]<< " ";
	}
	cout << endl;
	//Condiciones de frontera
	for(int i=0;i<n;i++)
	{
		V[i][0]=0;
		V[i][n-1]=0;
		V[0][i]=0;
		V[n-1][i]=0;
	
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if((x[i]>1.5)&&(x[i]<3.5))
			{
				 
				if(j==307)				
				{
					
					V[i][j]=-Vo/2;
				}
				
				else if(j==204)
				{
					
					V[i][j]=Vo/2;
				}
			}
			else 
			{
				V[i][j]=0.0;
			}
		}	
	}
	//Se resuelven las ecuaciones
	solveLaplaceEq();
	calculateField();
	return 0;
}

//Metodo que resuelve la ecuacion de Laplace con el metodo de relajacion
void solveLaplaceEq(void)
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			Vnew[i][j]=V[i][j];
			
		}
			
	}
	
	for(int k=0;k<6000;k++)
	{	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				Vold[i][j]=Vnew[i][j];
			
			}
			
		}
	
		for(int i=1;i<n-1;i++)
		{
			for(int j=1;j<n-1;j++)
			{			
				Vnew[i][j]=Vold[i][j] + w*((0.25*(Vold[i+1][j]+Vold[i][j+1]+Vnew[i-1][j]+Vnew[i][j-1]))- Vold[i][j]);
			}		
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<n;j++)
			{
				if((x[i]>1.5)&&(x[i]<3.5))
				{
				
					if(j==307)				
					{
					
						V[i][j]=-Vo/2;
					}
				
					else if(j==204)
					{
					
						V[i][j]=Vo/2;
					}
				}
			
			}	
		}	
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<Vnew[i][j]<<" ";
			
		}
		cout << endl;
	}
}

//Metodo que calcula el campo electrico a partir del potencial
void calculateField(void)
{
	
	for(int i=1;i<n;i++)
	{
		
		for(int j=1;j<n;j++)
		{
			Ex[i][j]=-(Vnew[i][j]-Vnew[i-1][j])/h;
			Ey[i][j]=-(Vnew[i][j]-Vnew[i][j-1])/h;
		}
		
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<Ex[i][j]<<" ";
			
		}
		cout << endl;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<Ey[i][j]<<" ";
			
		}
		cout << endl;
	}





}











