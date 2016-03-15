//
//  cluster.cpp
//  PA2
//
//  Created by Abdulrahman Alkaabi on 3/3/16.
//  Copyright © 2016 Abdulrahman Alkaabi. All rights reserved.
//

#include <stdio.h>
#include "Cluster.h"

using namespace Clustering;


/**
 * Default constructor
 */
Cluster::Cluster(){
    __size = 0;
    __points = nullptr;
    
    
}
Clustering::LNode::LNode():
next(),
point(){};




//constructor LNode
Clustering::LNode::LNode(const Point &p, LNodePtr n):
next (n),
point (p){};




/**
 * Copy constructor, must set all member variables of  to
 * the current Point's member variables.
 */

Cluster::Cluster(const Cluster& diffCluster){
    __size=diffCluster.__size;
    LNode *tempValues = new LNode [diffCluster.getSize()];
    for (int i = 0; i < diffCluster.getSize(); i ++)
        tempValues[i] = diffCluster.__points[i];
    __points = tempValues;
    
    
    
    
}


/**
 * Override the assignment operator
 */

Cluster& Cluster::operator=(const Cluster &otherCluster){
    
    __size=otherCluster.__size;
    __points=otherCluster.__points;
    
    return *this;
    
}

/**
 * Destructor
 */
Cluster::~Cluster(){
    //    LNodePtr current;
    //    while (__points != nullptr) {
    //        current = __points;
    //        __points = current->next;
    //
    //        delete current;
    //    }
    
}


int Cluster::getSize()const {
    
    
    return __size;
}
bool Clustering::operator==(const Cluster& c1, const Cluster& c2){
    bool eq =true;
    if(c1.getSize() != c2.getSize())
    {
        eq = false;
        for (int i = 0; i<c1.getSize(); i++) {
            //                double temp = p1.getValue(i);
            //                if (temp != p2.getValue(i)) {
            //                    bo = false;
            //                    break;
            //                }
            
            LNode cl1=c1.__points[i];
            LNode cl2=c2.__points[i];
            if (cl1.point != cl2.point)
            {
                eq = false;
                
            }
            else if (cl1.next != cl2.next)
            {
                eq = false;
            }
            
        }
        
    }
    
    return eq;
    
}

void Cluster::add(const Point& p1){
    std::cout<< "after add"<<std::endl;
    LNodePtr newNode = new LNode (p1, __points);
    printf("%p\n", &__points);
    if ( __points != NULL)
    {
        printf("HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n\n\n\n");
        std::cout<< getSize() <<std::endl;
        // append LNode to our points list
        LNodePtr prevNode = new LNode (__points[getSize()-1]);
        std::cout<< "after prevnod assignment"<<std::endl;
        prevNode->next = newNode;
        std::cout<< "after prevnod next"<<std::endl;
        
    }
    else {
        __points = newNode;
        
    }
    
    // set our next node to be null
    newNode->next = NULL;
    
    // increment size
    ++__size;
    
}
const Point& Cluster ::remove(const Point& p1){
    std::cout<< "after remove\n\n\n"<<std::endl;
    if ( __points) {
        LNodePtr current = __points;
        LNodePtr next = current->next;
        //LNode *first = current;
        while (next != NULL) {
            
            if (next->point == p1){
                //de-attach point from our link list
                delete next;
                // --__size;
                next = current->next;
            }
            else {
                current = next;
                next = next->next;
            }
        }
        
        return p1;
    }
    __size--;
    return p1;
}



/*
 
 
 
 
 */











