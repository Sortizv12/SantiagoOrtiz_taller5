#include <iostream>
#include <math.h>

using namespace std;

const float dt = 0.006;
const float t_i=0.0;
const float t_f=3000.0;
const int n=(t_f-t_i)/dt;
const float a=1/(2*sqrt(2));
const float eps=0.001;
float q1[n];
float q2[n];
float p1[n];
float p2[n];
float t[n];
float k1,k2,k3,k4;
float l1,l2,l3,l4;
float m1,m2,m3,m4;
float n1,n2,n3,n4;
void evolucion_rk4(void);
float p1_punto(float q1);
float p2_punto(float q1,float q2);
int main()
{
	t[0]=0.0;
	for(int i=1;i<n;i++)
	{
		t[i]= t[0] + dt*i;	
	}
	

	//Condiciones iniciales
	q1[0]=a;
	p1[0]=0;
	q2[0]=-a;
	p2[0]=0;
	evolucion_rk4();
	for(int i=0;i<n;i++)
	{
		cout<<q1[i]<< endl;	
	}
	for(int i=1;i<n;i++)
	{
		if((q1[i-1]<0)and(q1[i]>0))
		{
			cout << q2[i] << " "<< p2[i]<< endl;
		}
		else if((q1[i-1]>0) and (q1[i]<0))
		{
			cout << q2[i] << " "<< p2[i]<< endl;
		}			
	}
	return 0;
	
}
float p1_punto(float q1)
{
	float num=-2*q1;
	float denom=pow((4*pow(q1,2))+pow(eps,2),1.5);
	return num/denom;
}

float p2_punto(float q1,float q2)
{
	float num1=q1-q2;
	float num2=q1+q2;
	float denom1=pow(pow(q1-q2,2)+pow(eps/2,2),1.5);
	float denom2=pow(pow(q1+q2,2)+pow(eps/2,2),1.5);
	return (num1/denom1)-(num2/denom2);
}

void evolucion_rk4(void)
{
	float k1_q1,k2_q1,k3_q1,k4_q1;
	float k1_q2,k2_q2,k3_q2,k4_q2;
	float k1_p1,k2_p1,k3_p1,k4_p1;
	float k1_p2,k2_p2,k3_p2,k4_p2;
	for(int i=1;i<n;i++)
	{
		//Primer paso
		k1_q1=dt*p1[i-1];
		k1_p1=dt*p1_punto(q1[i-1]);
		k1_q2=dt*p2[i-1];
		k1_p2=dt*p2_punto(q1[i-1],q2[i-1]);

		//Segundo paso
		k2_q1=dt*(p1[i-1]+ k1_q1/2);
		k2_p1=dt*p1_punto(q1[i-1]+ k1_p1/2);
		k2_q2=dt*(p2[i-1]+ k1_q2/2);
		k2_p2=dt*p2_punto(q1[i-1]+ k1_p1/2 ,q2[i-1]+ k1_p2/2);

		//Tercer paso
		k3_q1=dt*(p1[i-1]+ k2_q1/2);
		k3_p1=dt*p1_punto(q1[i-1]+ k2_p1/2);
		k3_q2=dt*(p2[i-1]+ k2_q2/2);
		k3_p2=dt*p2_punto(q1[i-1]+ k2_p1/2,q2[i-1]+ k2_p2/2);
		
		//Cuarto paso
		k4_q1=dt*(p1[i-1]+ k3_q1);
		k4_p1=dt*p1_punto(q1[i-1]+ k3_p1);
		k4_q2=dt*(p2[i-1]+ k3_q2);
		k4_p2=dt*p2_punto(q1[i-1]+k3_p1,q2[i-1]+k3_p2);

		q1[i]=q1[i-1] + (1.0/6.0)*(k1_q1 + 2*k2_q1 + 2*k3_q1 + k4_q1);
		p1[i]=p1[i-1] + (1.0/6.0)*(k1_p1 + 2*k2_p1 + 2*k3_p1 + k4_p1);
		q1[i]=q1[i-1] + (1.0/6.0)*(k1_q2 + 2*k2_q2 + 2*k3_q2 + k4_q2);
		q1[i]=q1[i-1] + (1.0/6.0)*(k1_p2 + 2*k2_p2 + 2*k3_p2 + k4_p2);
	}
		
}
