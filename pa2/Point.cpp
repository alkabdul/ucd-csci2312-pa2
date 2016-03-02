//
//  Point.cpp
//  PA2
//
//  Created by Abdulrahman Alkaabi on 2/22/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
#include "Point.h"

using namespace Clustering;

/*
 * Single argument constructor that sets the dimensions of the point
 */
unsigned int Point::__idGen=0;

Point::Point(int dimensions){
    __dim=dimensions;
  	 // id generator
    __id=Point::__idGen;
    Point::__idGen++;
    __values = new double [__dim]();
    
}

/**
 * Two argument constructor that sets both the dimensions and
 * the values for each dimension of the point
 **/
Point::Point (int dimensions, double* values){
 __dim=dimensions;
 __values=values;
    Point::__idGen++;
  __values = new double [__dim]();
 }
 
 /**
 * Copy constructor, must set all member variables of  to
 * the current Point's member variables.
 */

Point::Point (const Point& diffPoint){
    __dim=diffPoint.__dim;
    __values=diffPoint.__values;
    __id=diffPoint.__id;
    
    
}

/**
 * Override the assignment operator
 */

Point& Point::operator=(const Point &otherPoint){
 
 __dim=otherPoint.__dim;
 __values=otherPoint.__values;
    __id=otherPoint.__id;
 
 return *this;
 
 }
 /**
 * Destructor
 */
Point::~Point(){
    
    
}

/**
 * Calculates the distance between two n-dimensional points
 */
 double Point::distanceTo(const Point &otherPoint)const{
 //variable to return
 double distance=0.0;
 
 //variable for intermediate calculations
 double sum=0.0;
 
 //apply Pythagorean theroem: distance^2=Sum of i to n (deltaXi^2)
 for(int i =0; i<getDims(); i++){
        double difference=__values[i]-otherPoint.__values[i];
        sum += pow(difference,2.0);
     
    }
     distance = sqrt(sum);

 
 return distance;
 
 
 }
 
 /**
 * Getter and setter implementations
 */
int Point::getId() const {
	return __id;
 }

/**
 * Returns the dimension of the point
 */
int Point::getDims() const{
    return __dim;
}

/**
 * Sets the value of a particular dimension
 * I.e. myValues[2]=4.3
 */
void Point::setValue(int position, double value){
    __values[position] = value;
 
	
 }
 
 /**
 * Return the value at the given position
 */
double Point::getValue(int position) const{
    
    return __values[position];
    

 }

/***OPERATORS****/

Point& Point::operator*=(double value){
    for (int i = 0; i< __dim; i++){
        
         __values[i] *= value;
        
    }

 return *this;
 
 }
 
 Point& Point::operator/=(double value){
     for (int i = 0; i< __dim; i++){
         
         __values[i] /= value;
         
     }

 return *this;
 }
 
 const Point Point::operator*(double value) const{
     for (int i = 0; i< __dim; i++){
         __values[i] *= value;
         
     }
     
     
     return *this;
     
 }
 const Point Point::operator/(double value) const{
     for (int i = 0; i< __dim; i++){
         
         __values[i] /= value;
         
         

 }
 
     return *this;
 }


double& Point::operator[](int index){
    
    
    return  __values[index];
    
 
 }
 
 /******FRIENDS******/
Point & Clustering::operator +=( Point &p1, const Point &p2 ){
    for ( int i = 0; i<p1.getDims(); i++){
        double temp = p1.getValue(i);
        temp += p2.getValue(i);
    p1.setValue(i,temp);
        
    }
    
    return p1;
}

Point & Clustering::operator -=( Point &p1, const Point &p2 ){
    
for ( int i = 0; i<p1.getDims(); i++){
    double temp = p1.getValue(i);
    temp -= p2.getValue(i);
    p1.setValue(i,temp);
    
}

return p1;


}

const Point Clustering::operator+(const Point& p1, const Point& p2){
      Point pt(p1);
     for ( int i = 0; i<p1.getDims(); i++){
         double temp = p1.getValue(i);
         temp += p2.getValue(i);
         pt.setValue(i,temp);
     }
     return pt;
 
 
 }
const Point Clustering::operator-(const Point& p1, const Point& p2){
     
         Point pt(p1);
         for ( int i = 0; i<p1.getDims(); i++){
             double temp = p1.getValue(i);
             temp -= p2.getValue(i);
             pt.setValue(i,temp);
         }
         return pt;
     
 
 }

bool Clustering::operator==(const Point& p1, const Point& p2){
    
     bool bo = false;
    if (p1.__id == p2.__id){
    if (p1.getDims() == p2.getDims()){
        bo = true;
        for ( int i = 0; i<p1.getDims(); i++){
            double temp = p1.getValue(i);
            if(temp != p2.getValue(i)){
                bo = false;
                break;
            }
}
    }
        }
     return bo;
     
    
}
bool Clustering::operator!=(const Point& p1, const Point& p2){
 
 /*    bool bo = false;
    if (p1.__id != p2.__id){
        if (p1.getDims() != p2.getDims()){
            
    
     for ( int i = 0; i<p1.getDims(); i++){
         double temp = p1.getValue(i);
         if(temp != p2.getValue(i)){
             bo = true;
             break;
         }
     }
        }
     }
     return bo;*/
    return !(p1==p2);

 
 }
 
bool Clustering:: operator<(const Point& p1, const Point& p2){
     
     bool bo = true;
     bool boEq= true;
     for ( int i = 0; i<p1.getDims(); i++){
         double temp = p1.getValue(i);
         if(temp > p2.getValue(i)){
             bo = false;
             }
         else if(temp == p2.getValue(i)){
             boEq = false;
         }
         
     }
     
     if (boEq == true)
     {
         return false;
     }
         
     return bo;

     
 
 }
 bool Clustering:: operator>(const Point& p1, const Point& p2){
     
     bool bo = true;
      bool boEq= true;
     for ( int i = 0; i<p1.getDims(); i++){
         double temp = p1.getValue(i);
         if(temp < p2.getValue(i)){
             bo = false;
         }
     else if(temp == p2.getValue(i)){
         boEq = false;
     
        }
     }
if (boEq == true){
    return false;
    }


     return bo;

 }
bool Clustering:: operator<=(const Point& p1, const Point& p2){
     
     bool bo = true;
     bool boEq= true;
     for ( int i = 0; i<p1.getDims(); i++){
         double temp = p1.getValue(i);
         if(temp > p2.getValue(i)){
             bo = false;
         }
         else if(temp == p2.getValue(i)){
             boEq = false;
         }
         
     }
    
     
     return (bo||boEq);

 
     
 }
bool Clustering:: operator>=(const Point& p1, const Point& p2){
     bool bo = true;
     bool boEq= true;
     for ( int i = 0; i<p1.getDims(); i++){
         double temp = p1.getValue(i);
         if(temp < p2.getValue(i)){
             bo = false;
         }
         else if(temp == p2.getValue(i)){
             boEq = false;
         }
         
     }
     
     
     return (bo||boEq);
     

 
 }