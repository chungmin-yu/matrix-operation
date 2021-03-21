#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"

class matrix33 
{  

	public:
		/* data members */
		float mat[3][3];
		bool T=false;
		
	public:
		/* constructors */
		// default constructor -- don't do anything with it
		matrix33();
		
		// constructor with initializing vector3 
		matrix33(vector3 &v1, vector3 &v2, vector3 &v3);
		
		// constructor with initializing matrix33
		matrix33(const matrix33 &m);
		
	public:
		/* Operators */
		
		// access element
		
		matrix33               &operator =  (const matrix33 &m);
		matrix33               &operator += (const matrix33 &m);
		matrix33               &operator -= (const matrix33 &m);
		matrix33               &operator *= (float f);
		matrix33               &operator /= (float f);
		friend bool           operator == (const matrix33 &a, const matrix33 &b);
		friend bool           operator != (const matrix33 &a, const matrix33 &b);
		friend matrix33        operator - (const matrix33 &a);
		friend matrix33        operator + (const matrix33 &a, const matrix33 &b);
		friend matrix33        operator - (const matrix33 &a, const matrix33 &b);
		friend matrix33        operator * (const matrix33 &a,const matrix33 &b);
		friend matrix33        operator * (const matrix33 &m, float f);
		friend matrix33        operator / (const matrix33 &m, float f);
		float*                operator [] (const int x);
		
	public:
		 /* Methods */
	
		 // set values (e.g. x = xIn, ...)
		 //void set(float xIn, float yIn, float zIn);
		
		 // calculate determinant
		 float determinant();
	
		  // print matrix using std::cout
		 void printMatrix() ;
		 
		 void identity();
		 
		 matrix33 invert();

};

#endif
