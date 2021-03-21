#include "vector3.h"
#include <cmath>
#include <iostream>
using namespace std;
vector3::vector3(){}
vector3::vector3(float inX, float inY, float inZ){
	x=inX;
	y=inY;
	z=inZ;
}
vector3::vector3(const vector3 &v){
	x=v.x;
	y=v.y;
	z=v.z;
}
void vector3::set(float xIn, float yIn, float zIn){
	x=xIn;
	y=yIn;
	z=zIn;
}
float vector3::length() const{
	return sqrt(x*x+y*y+z*z);
}
void vector3::printVector3() const{
	cout<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
}

float& vector3::operator[] (unsigned int index){
	if(index<0||index>2){
		cout<<"out of range!!"<<endl;
		exit(1);
	}
	float vec[3];
	vec[0]=x;
	vec[1]=y;
	vec[2]=z;
	return vec[index];
}
const float& vector3::operator [] (unsigned int index) const{
	if(index<0||index>2){
		cout<<"Out of range!!"<<endl;
		exit(1);
	}
	float vec[3];
	vec[0]=x;
	vec[1]=y;
	vec[2]=z;
	return vec[index];
}	

vector3& vector3::operator =  (const vector3 &v){
	x=v.x;
	y=v.y;
	z=v.z;
	return *this;
}
vector3& vector3::operator += (const vector3 &v){
	x=x+v.x;
	y=y+v.y;
	z=z+v.z;
	return *this;
}
vector3& vector3::operator -= (const vector3 &v){
	x=x-v.x;
	y=y-v.y;
	z=z-v.z;
	return *this;
}
vector3& vector3::operator *= (float f){
	x=x*f;
	y=y*f;
	z=z*f;
	return *this;
}
vector3& vector3::operator /= (float f){
	x=x/f;
	y=y/f;
	z=z/f;
	return *this;
}
bool operator == (const vector3 &a, const vector3 &b){
	return (a.x==b.x)&&(a.y==b.y)&&(a.z==b.z);
}
bool operator != (const vector3 &a, const vector3 &b){
	return (a.x!=b.x)||(a.y!=b.y)||(a.z!=b.z);
}
vector3 operator - (const vector3 &a){
	vector3 temp(-1*a.x, -1*a.y, -1*a.z);
	return temp;
}
vector3 operator + (const vector3 &a, const vector3 &b){
	vector3 temp(a.x+b.x, a.y+b.y, a.z+b.z);
	return temp;
}
vector3 operator - (const vector3 &a, const vector3 &b){
	vector3 temp(a.x-b.x, a.y-b.y, a.z-b.z);
	return temp;
}
vector3 operator * (const vector3 &v, float f){
	vector3 temp(v.x*f, v.y*f, v.z*f);
	return temp;
}
vector3 operator * (float f, const vector3 &v){
	vector3 temp(f*v.x, f*v.y, f*v.z);
	return temp;
}
vector3 operator / (const vector3 &v, float f){
	vector3 temp(v.x/f, v.y/f, v.z/f);
	return temp;
}


