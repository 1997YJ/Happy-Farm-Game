#include"Wip.h"

wip::wip():index(0), produceTime(0), nowProduceTime(0), produceCounter(Time()), T(Time())
{
}
wip::wip(int i, int t)
{
    index = i;
    produceTime = t;
    T.Start();
    nowProduceTime = 0;
    produceCounter.Start();
}
bool wip::produce()
{
    if (nowProduceTime < this->produceTime){
        produceCounter.End();
        if (produceCounter.Pass() >= 1){
            nowProduceTime++;
            produceCounter.Start();
        }return false;
    }else{
        return true;
    }
}

void wip::assign(int i, int t){
    index = i;
    produceTime = t;
    T.Start();
    nowProduceTime = 0;
    produceCounter.Start();
}

void wip::reset(){
    index = 0;
    produceTime = 0;
    T=Time();
    nowProduceTime = 0;
    produceCounter=Time();
    
}



