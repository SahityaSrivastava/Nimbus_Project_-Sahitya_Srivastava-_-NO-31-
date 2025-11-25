
#include <stdio.h>
//security camera
int main(){
    
    // temp to check sudden temperature changes 
    // nv to turn on night vision of camera 
    // br to see the lumins of the surrondings
    // status camera On/Off
    // power to store power consumption
    // uptime for total runnig time
    //tc to check if thier is any sudden temp change 
    
    struct camera{
    
    int temp[4]; 
    int nv[4];
    int status; 
    int tc[4];
    int br[4];
    float power;
    int uptime;
    
    };
    
    struct camera c;
   
   // innitilizing power, status and uptime to remove garbage value
   
   c.status=0;
   c.uptime=0;
   c.power=0;
 
   //temperature for 4 Hours
    for(int i=0;i<=3;i++){
    printf("Enter temperature for Time %d:00 Hours to %d:00 Hours :",i,(i+1));
    scanf("%d",&c.temp[i]);
    }
   
   //lumins for 4 hours
    for(int i=0;i<=3;i++){
    printf("Enter Lumins for Time %d:00 Hours to %d:00 Hours :",i,(i+1));
    scanf("%d",&c.br[i]);
    }
     
     printf("\n"); //extra space;
   
    //checking lumix for 4 hours in order to turn on night vision 
    for(int i=0;i<=3;i++){
        c.nv[i]=0;
        if(c.br[i]<300){
            c.nv[i]=1;
        }
    }
    //checking temperature in order to turn on camera 
    for(int i=0;i<=3;i++){
        c.tc[i]=0;
        if(c.temp[i]>55  || c.temp[i]<25){
            c.tc[i]=1;
        }
    }
    
    // checking tc and nv in order to turn on camera 
    for (int i=0;i<=3;i++){
        if(c.tc[i]==1 || c.nv[i]==1){
            c.status=1;
        }
    }

    // finding uptime and power consumption
    for (int i=0;i<=3;i++){
        
        //checking uptime 
        if(c.tc[i]==1 || c.nv[i]==1){
            c.uptime = c.uptime+1;
        }
       
       //checking power consumtion
       if(c.tc[i]==1 && c.nv[i]==1){
           c.power=c.power+0.50+0.25;  // 0.50 units for camera & 0.25 units for night vision
           }                            
           
           else if(c.tc[i]==1){
               c.power=c.power+0.50;
           }
           else if(c.nv[i]==1){
            c.power=c.power+0.25;
           }
    }
    
    
    
    //printing output 
    
    printf("-------------STATUS OF CAMERA-------------\n\n");
    for(int i=0;i<=3;i++){
        if(c.tc[i]==1 && c.nv[i]==1){
            printf("Camera Turned on in %d to %d Hours due to change in temperature and low light\n",i,(i+i));
        }
        else if (c.tc[i]==1){
             printf("Camera Turned on in %d to %d Hours due to change in temperature \n",i,(i+i));
        }
        else if(c.nv[i]==1){
            printf("Camera Turned on in %d to %d Hours due to change in low light\n",i,(i+i));
        }
    }
    printf("\n");
    printf("TOTAL POWER CONSUMPTION : %.2f Units\n",c.power);
      printf("TOTAL POWER UPTIME OF CAMERA : %d3 Hours\n",c.uptime);
    return 0;

}
