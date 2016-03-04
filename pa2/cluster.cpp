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
    
}
//constructor LNode


/**
 * Copy constructor, must set all member variables of  to
 * the current Point's member variables.
 */

Cluster::Cluster(const Cluster& diffCluster){
    __size=diffCluster.__size;
    __points=diffCluster.__points;
    
    
    
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
    //    /* The list is empty? */
    //    pHead
    //    if (_pHead == NULL) {
    //        /* the same to create a new list with a given value */
    //        _pTail = _pHead = new Node(val);
    //    }
    //    else
    //    {
    //        /* Append the new node to the tail */
    //        _pTail->_pNext = new Node(val);
    //        /* Update the tail pointer */
    //        _pTail = _pTail->_pNext;
    //    }
    // call copy constructor for point
    Point *p2 = new Point(p1);
    // create LNode
    LNode *newNode = new LNode (*p2,__points);
    if ( __points != NULL)
    {
        // append LNode to our points list
        LNode prevNode = __points[getSize()-1];
        prevNode.next = newNode;
        
        
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
    LNode *current = &__points[0];
    LNode *next = current->next;
    //LNode *first = current;
    while (next != NULL) {
        
        if (next->point == p1){
            //de-attach point from our link list
            delete next;
            next = current->next;
        }
        else {
            current = next;
            next = next->next;
        }
    }
    
    
    return p1;
}


/*
 
 
 
 
 */











