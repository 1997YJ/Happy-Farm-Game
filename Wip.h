#ifndef Wip_h
#define Wip_h

#include <stdio.h>
#include "Time.h"

// in Factory (private)
class wip
{
public:
    int index;
    int produceTime;
    int nowProduceTime;
    Time produceCounter;
    Time T;
    
    wip();
    wip(int i, int t);
    bool produce();
    
    void assign(int i, int t);
    void reset();
    
    void equal(wip a);
};


#endif /* Wip_h */



