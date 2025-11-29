#include "fan.h"
#include <stdio.h>
/*FAN

variables i have used --
    temp - to check temperature
    humidity - to check humidity
    occ - to check occupancy
    fanspeed - to set fan speed
    status - to check if fan is 'on' or 'off'
    power - to know power consumption
    uptime - to know total running time of fan
    manual - to check if user want to override the default
    */

struct fan{
    float temp[4];
    int humidity[4];
    int occ[4];
    int fanspeed[4];
    int status[4];
    float power;
    int uptime;
    int manual[4];
};

struct fan a;

void runFan(){
    a.power=0;
    a.uptime=0;

    //input
    for(int i=0;i<4;i++){
        printf("Enter temperature for hour %d to %d: ",i,i+1);
        scanf("%f",&a.temp[i]);

        printf("Enter hummidity for hour %d to %d: ",i,i+1);
        scanf("%d",&a.humidity[i]);

        printf("Enter occupancy (1=present,0=absent) for hour %d to %d: ",i,i+1);
        scanf("%d",&a.occ[i]);

        printf("Manual override??? (1=yes,0=no) for hour %d to %d: ",i,i+1);
        scanf("%d",&a.manual[i]);

    }

    for(int i=0;i<4;i++){
        a.status[i]=0;
        a.fanspeed[i]=0;

        if(a.manual[i]==1){
            printf("Enter fan speed for hour %d to %d (0-3): ",i,i+1);
            scanf("%d",&a.fanspeed[i]);
            a.status[i]=(a.fanspeed[i]>0);
        }

        else{
            if(a.temp[i] > 35)          
                a.fanspeed[i] = 3;
            else if(a.temp[i] > 30)     
                a.fanspeed[i] = 2;
            else if(a.humidity[i] > 70) 
                a.fanspeed[i] = 1;
            else if(a.occ[i] == 1)      
                a.fanspeed[i] = 1;
            else                        
                a.fanspeed[i] = 0;
        }

        if(a.fanspeed[i]>0){
            a.status[i]=1;
            a.uptime++;
        }

        //power
        if(a.fanspeed[i]==1)
            a.power+=0.20;
        else if(a.fanspeed[i]==2)
            a.power+=0.35;
        else if(a.fanspeed[i]==3)
            a.power+=0.50;
    }

    //output
    printf("-------- FAN STATUS --------\n");
    printf("Fan is running...\n");

    for(int i=0;i<4;i++){
        if(a.status[i]==1){
            printf("Fan is ON from %d to %d with speed %d\n",i,i+1,a.fanspeed[i]);

        }

    }    

    printf("Total Fan Uptime: %d hours\n",a.uptime);
    printf("Total power used: %.2f units\n",a.power);

}
