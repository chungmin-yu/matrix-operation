#include "matrix33.h"
#include <iostream>
using namespace std;

matrix33::matrix33(){
	mat[0][0]=0;
	mat[0][1]=0;
	mat[0][2]=0;
	mat[1][0]=0;
	mat[1][1]=0;
	mat[1][2]=0;
	mat[2][0]=0;
	mat[2][1]=0;
	mat[2][2]=0;
}
matrix33::matrix33(const matrix33 &m){
	mat[0][0]=m.mat[0][0];
	mat[0][1]=m.mat[0][1];
	mat[0][2]=m.mat[0][2];
	mat[1][0]=m.mat[1][0];
	mat[1][1]=m.mat[1][1];
	mat[1][2]=m.mat[1][2];
	mat[2][0]=m.mat[2][0];
	mat[2][1]=m.mat[2][1];
	mat[2][2]=m.mat[2][2];
}
matrix33::matrix33(vector3 &v1,vector3 &v2,vector3 &v3){
	mat[0][0]=v1.x;
	mat[0][1]=v2.x;
	mat[0][2]=v3.x;
	mat[1][0]=v1.y;
	mat[1][1]=v2.y;
	mat[1][2]=v3.y;
	mat[2][0]=v1.z;
	mat[2][1]=v2.z;
	mat[2][2]=v3.z;
}

matrix33& matrix33::operator = (const matrix33 &m){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			mat[i][j]=m.mat[i][j];
		}
	}
	return *this;
}
matrix33& matrix33::operator += (const matrix33 &m){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			mat[i][j]=mat[i][j]+m.mat[i][j];
		}
	}
	return *this;
}
matrix33& matrix33::operator -= (const matrix33 &m){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			mat[i][j]=mat[i][j]-m.mat[i][j];
		}
	}
	return *this;
}
matrix33& matrix33::operator *= (float f){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			mat[i][j]=mat[i][j]*f;
		}
	}
	return *this;
}
matrix33& matrix33::operator /= (float f){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			mat[i][j]=mat[i][j]/f;
		}
	}
	return *this;
}
bool operator == (const matrix33 &a,const matrix33 &b){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if(a.mat[i][j]!=b.mat[i][j]){
				return false;
			}
		}
	}
	return true;
}
bool operator != (const matrix33 &a,const matrix33 &b){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if(a.mat[i][j]!=b.mat[i][j]){
				return true;
			}
		}
	}
	return false;
}
matrix33 operator - (const matrix33 &m){
	matrix33 temp;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			temp.mat[i][j]=-1*m.mat[i][j];
		}
	}
	return temp;
}
matrix33 operator + (const matrix33 &a, const matrix33 &b){
	matrix33 temp;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			temp.mat[i][j]=a.mat[i][j]+b.mat[i][j];
		}
	}
	return temp;
}
matrix33 operator - (const matrix33 &a, const matrix33 &b){
	matrix33 temp;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			temp.mat[i][j]=a.mat[i][j]-b.mat[i][j];
		}
	}
	return temp;
}
matrix33 operator * (const matrix33 &a,const matrix33 &b){
	matrix33 temp;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			temp.mat[i][j] = a.mat[i][0]*b.mat[0][j]+a.mat[i][1]*b.mat[1][j]+a.mat[i][2]*b.mat[2][j];
		}
	}
	return temp;
}

matrix33 operator * (const matrix33 &m, float f){
	matrix33 temp;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			temp.mat[i][j]=m.mat[i][j]*f;
		}
	}
	return temp;
}
matrix33 operator / (const matrix33 &m, float f){
	matrix33 temp;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			temp.mat[i][j]=m.mat[i][j]/f;
		}
	}
	return temp;
}

float* matrix33::operator [] (const int x){
	T=true;
	return mat[x];
}

void matrix33::identity(){
	mat[0][0]=1;
	mat[1][1]=1;
	mat[2][2]=1;
}


float matrix33::determinant(){
	return (mat[0][0]*mat[1][1]*mat[2][2]+
			mat[1][0]*mat[2][1]*mat[0][2]+
			mat[2][0]*mat[0][1]*mat[1][2]-
			mat[0][2]*mat[1][1]*mat[2][0]-
			mat[1][2]*mat[2][1]*mat[0][0]-
			mat[2][2]*mat[0][1]*mat[1][0] );
}

void matrix33::printMatrix() {
	if(T){
		float tmp1, tmp2, tmp3;
		tmp1=mat[0][1];
		mat[0][1]=mat[1][0];
		mat[1][0]=tmp1;
		tmp2=mat[0][2];
		mat[0][2]=mat[2][0];
		mat[2][0]=tmp2;
		tmp3=mat[2][1];
		mat[2][1]=mat[1][2];
		mat[1][2]=tmp3;
	}
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

matrix33 matrix33::invert(){
	if(determinant()==0){
		cout<<"This matrix is singular!!"<<endl;
		exit(1);
	}
	matrix33 tmp;
	float a[3][6],m;
	int i,j,k;
	for(i=0;i<3;++i){
		for(j=0;j<6;++j){
			a[i][j]=0;
		}
	}
	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			a[i][j]=mat[i][j];
		}
	}
	for(i=0;i<3;i++){
		a[i][i+3]=1; 
	}
	for(i=0;i<2;i++){ 
		for(j=i+1;j<3;j++){ 
			m=a[j][i]/a[i][i]; 
			for(k=i;k<6;k++){
				a[j][k]-=m*a[i][k];
			}
		} 
	}	
	for(i=2;i>0;i--){ 
		for(j=i-1;j>=0;j--){ 
			m=a[j][i]/a[i][i]; 
			for(k=i;k<6;k++){
				a[j][k]-=m*a[i][k];
			}
		} 
	} 
	for(i=0;i<3;i++){ 
		m=a[i][i]; 
		for(j=0;j<6;j++){
			a[i][j]/=m; 
		} 
	}
	
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			tmp.mat[i][j]=a[i][j+3];	
		}	
	}
	
	return tmp;
}


