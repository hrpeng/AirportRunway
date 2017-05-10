//
//  runway.c
//
//
//  Created by Avery Brown on 2017-01-29.
//
//

#include "LQueue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>      
#include <stdlib.h>
#include <time.h>
using namespace std;




int main(void)
{
    Queue q1;
    cout << "Enter time for a plane to land (in minutes): ";
    int landtime;
    cin >> landtime;
    
    cout << "Enter time for a plane to takeOff (in minutes): ";
    int takeOffTime;
    cin >> takeOffTime;
    
    cout << "Enter landing rate (planes per hour): ";
    int landingRate;
    cin >> landingRate;
    
    cout << "Enter takeoff rate (planes per hour): ";
    int takeOffRate;
    cin >> takeOffRate;
    
    cout << "How long to run the simulation (in minutes): ";
    int simulationTime;
    cin >> simulationTime;
    
    Queue lqueue;
    Queue tqueue;
    int currenttime = 0;
    int planeNumber = 1000;
    bool runwayFree = true;
    //int runway;
    int runwaytime = 0;
    bool planeLanding = false;
    int totallanded= 0;
    int totaltakeoff = 0;
    int maxplaneslq = 0;
    
    int averagelandwait = 0;
    int averagetakeoffwait = 0;
    int maxplanestq = 0;
	int tenqueTimeSum = 0;
	int lenqueTimeSum = 0;
	int tdequeueTimeSum = 0;
	int ldequeueTimeSum = 0;
    int qtplanes = 0;
    int qlplanes = 0;
   
    
    
    while(currenttime <= simulationTime){
        
        int x = rand() % 60;
      
        int y = rand() % 60;
        
        if (planeLanding){
            if (runwaytime == landtime){
                runwayFree = true;
                planeLanding = false;
                cout << "Landing complete; "<<qlplanes<< " in queue"<< endl;
                totallanded++;
            }
        }
            else {
                if (runwaytime == takeOffTime){
                    runwayFree = true;
                    cout << "Takeoff complete; "<<qtplanes<< " in queue"<< endl;
                    totaltakeoff++;
                }
            }
        
            
            if (y < takeOffRate){
                planeNumber = planeNumber +1;
                lqueue.enqueue(planeNumber);
                qlplanes++;
                cout << "Plane " << planeNumber << " wants to takeoff; added to takeoff queue; "<<qlplanes<< " in queue"<<endl;
				tenqueueTimeSum += currenttime;
                if (qlplanes > maxplaneslq)
                    maxplanestq = qtplanes;
            }
            
            
            if (x < landingRate){
                planeNumber = planeNumber + 50;
                tqueue.enqueue(planeNumber);
                landtime++;
                
                
               if ((planeNumber % 16) == 0){
                    lqueue.move_to_front(planeNumber);
                    cout << "Priority plane " <<planeNumber<< " is on the runway due to emergency"<< endl;
               }
                
                qtplanes++;
                cout << "Plane " <<planeNumber<< " wants to land; added to landing queue; "<<qtplanes<< " in queue"<<endl;
				lenqueueTimeSum += currenttime;
                if (qlplanes > maxplaneslq)
                    maxplaneslq = qlplanes;
            }
        
      
        
            if (runwayFree)
            {   if (!lqueue.empty()){
                runwayFree = false;
                planeLanding = true;
                runwaytime = 0;
                cout << "Plane " <<planeNumber<< " is on the runway"<< endl;
				ldequeueTimeSum += currenttime;
                lqueue.dequeue();
                qlplanes--;}
            else {
                if (!tqueue.empty()){
                    runwayFree = false;
                    planeLanding = false;
                    runwaytime = 0;
                    cout << "Plane " <<planeNumber<< " is on the runway"<< endl;
					tdequeueTimeSum += currenttime;
                    tqueue.dequeue();
                    qtplanes--;
                }
                
            }}
    
    
            cout << "Time is "<< currenttime<< " minutes" << endl;
            currenttime++;
            
            runwaytime++;
    }
    
       // averagelandwait = landwait/totallanded;
       // averagetakeoffwait = takeoffwait/totaltakeoff;
        
        cout << "Maximum number of planes in landing queue was:" << maxplaneslq << endl;
        cout << "Average minutes spent waiting to land:" << averagelandwait<< endl;
        cout << "Maximum number of planes in takeoff queue was:" << maxplanestq << endl;
        cout << "Average minutes spent waiting to takeoff:" << averagetakeoffwait << endl;
		cout << "Taking-off enqueue time overall: " << tenqueTimeSum << endl;
		cout << "Landing enqueue time overall: " << enqueTimeSum << endl;
		cout << "Taking-off dequeue time overall: " << tdequeueTimeSum << endl;
		cout << "Landing dequeue time overall: " << tdequeueTimeSum << endl;
        
        cout << "End of program" << endl;
    return 0;}


