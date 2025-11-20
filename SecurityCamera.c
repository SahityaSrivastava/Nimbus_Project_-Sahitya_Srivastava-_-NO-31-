
#include <stdio.h>
//security camera
int main(){
    
    // temp to check sudden temperature changes 
    // nigvis to turn on night vision of camera 
    // lumix to see the lumins of the surrondings
    // status camera On/Off
    // power to store power consumption
    // uptime for total runnig time
    struct camera{
    
    int temp[24]; 
    int nigvis[24];
    int status; 
    int lumix[24];
    int power;
    int uptime;
    
    };
    
    struct camera c;
    //temperature for 24 Hours
    for(int i=0;i<=23;i++){
    printf("Enter temperature for Time %d:00 Hours to %d:00 Hours ",i,(i+1));
    scanf("%d",&c.temp[i]);
    }
    //lumins for 24 hours
    for(int i=0;i<=23;i++){
    printf("Enter Lumins for Time %d:00 Hours to %d:00 Hours ",i,(i+1));
    scanf("%d",&c.lumix[i]);
    }
    //checking lumix for 24 hours in order to turn on night vision 
    for(int i=0;i<=23;i++){
    if(c.lumix[i]<300){
        c.nigvis[i]=1;
    }
    
}
return 0;
}
