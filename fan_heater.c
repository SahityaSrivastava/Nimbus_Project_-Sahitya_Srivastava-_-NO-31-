#include <stdio.h>

/*
FAN

variables i have used --
    temp - to check temperature
    humidity - to check humidity
    occ - to check occupancy
    fanspeed - to set fan speed
    status - to check if fan is 'on' or 'off'
    power - to know power consumption
    uptime - to know total running time of fan
    manual - to check if user want to override the default


HEATER

variable used --
    temp - to check temperature
    occ - to check occupancy
    manual - to check if user to override the default
    mode - heater will be off, at medium or at high
    status - to check if heater is 'on' or 'off'
    power - to know power consumption
    uptime - to know total running time of heater

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

struct heater{
    float temp[4];
    int occ[4];
    int manual[4];
    int mode[4];
    int status[4];
    float power;
    int uptime;
};

struct fan a;
struct heater h;

int main()
{
    //----------FAN CODE START----------    
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

    for(int i=0;i<4;i++){
        if(a.status[i]==1){
            printf("Fan is ON from %d to %d with speed %d\n",i,i+1,a.fanspeed[i]);

        }

    }    

    printf("Total Fan Uptime: %d hours\n",a.uptime);
    printf("Total power used: %.2f units\n",a.power);

    //----------FAN CODE END----------  



    //----------HEATER CODE START----------  

    h.power=0;
    h.uptime=0;

    //input
    for(int i=0;i<4;i++){
        printf("Enter temperature for hour %d to %d: ",i,i+1);
        scanf("%f",&h.temp[i]);

        printf("Enter occupancy (1=present,0=absent) for hour %d to %d: ",i,i+1);
        scanf("%d",&h.occ[i]);

        printf("Manual override??? (1=yes,0=no) for hour %d to %d: ",i,i+1);
        scanf("%d",&h.manual[i]);

    }

    for(int i=0;i<4;i++){
        h.status[i]=0;
        h.mode[i]=0;

        if(h.manual[i]==1){
            printf("Enter heater mode (0=off, 1=medium, 2=high) for hour %d to %d (0-3): ",i,i+1);
            scanf("%d",&h.mode[i]);
        }

        else{
            if(h.temp[i] < 10)          
                h.mode[i] = 2;
            else if(h.temp[i] <18)     
                h.mode[i] = 1;
            else if(h.occ[i] == 1)      
                h.mode[i] = 1;
            else                        
                h.mode[i] = 0;
        }

        if(h.mode[i]>0){
            h.status[i]=1;
            h.uptime++;
        }

        //power
        if(h.mode[i]==1)
            h.power+=0.40;
        else if(h.mode[i]==2)
            h.power+=0.75;
    }

    //output
    printf("-------- HEATER STATUS --------\n");

    for(int i=0;i<4;i++){
        if(h.status[i]==1){
            printf("Heater is ON from %d to %d with Mode %d\n",i,i+1,h.mode[i]);

        }

    }    

    printf("Total Heater Uptime: %d hours\n",h.uptime);
    printf("Total power used: %.2f units\n",h.power);


    //----------HEATER CODE END----------  

    return 0;
    

}
