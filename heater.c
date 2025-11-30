#include <stdio.h>
/*
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

struct heater{
    float temp[4];
    int occ[4];
    int manual[4];
    int mode[4];
    int status[4];
    float power;
    int uptime;
};

struct heater h;

int main(){
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


    
    return 0;
}