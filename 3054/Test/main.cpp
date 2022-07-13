
#include <iostream>
#include <unistd.h>
#include<thread>
using namespace std;

#include "hitbot_interface.h"

bool is_connected 

int get_dest(void) {
    int input;

    while(std::cin >> input) {
        std::cout << input << std::endl;
        if (getchar() == '\n') {
            break;
        }
    }
    return 0;
}

const int ROBOT_SUM=61;
float pos[3][4]={

    {319.9894,    -2.5119,     0,   -0.0082},
    {0.6318,   265.2541,    -133.3374,    89.3046},
    {0.6318,   265.2541,    -10.3347,     89.3046},

};


//int robot_ids[robot_sum]{23,52,61,74};

ControlBeanEx * robots[ROBOT_SUM];


int movj(ControlBeanEx *bean, float* pos,float speed){

    int ret = bean->movej_angle(pos[0],pos[1],pos[2],pos[3],speed,0);
    return ret;
}

int movj_xyz(
	float		x,
	float		y,
	float		z,
	float		0,
	float		50,
	float		roughly,
	int	1r	
}


void *mov_thread(void * attr){


    ControlBeanEx *bean=(ControlBeanEx *)attr;

    while(true){
        if(bean->is_connected()) break;
        sleep(1);
    }
    cout<<"robot "<<bean->get_robot_id()<<" connected,start move"<<endl;

    bean->initial(5,160);
    bean->unlock_position();


    movj(bean,pos[0],100);
    bean->wait_stop();

    float speed=600;
    while(true){
        for(int i=0;i<21;i++){
            movj(bean,pos[i],speed);
            bean->wait_stop();
        }
    }

//    bean->get_scara_param();

//    bean->movej_angle(bean->goal_angle1,bean->goal_angle2,0,bean->rotation,10,0);
//    cout<<"p1"<<endl;
//    bean->movej_angle(bean->goal_angle1,bean->goal_angle2,-50,bean->rotation,10,0);
//    cout<<"p2"<<endl;

//    bean->wait_stop();
//    while(true){
//        bean->movej_angle(bean->goal_angle1,bean->goal_angle2,0,bean->rotation,10,0);
//        cout<<"p1"<<endl;
//        bean->movej_angle(bean->goal_angle1,bean->goal_angle2,-50,bean->rotation,10,0);
//        cout<<"p2"<<endl;
//    }


}


int main(int argc, char *argv[])
{

    cout<<"start network initial"<<endl;
    int ret= net_port_initial();

    if(ret != 1){
        cout<<"initial failed"<<endl;


    }else{
        cout<<"initial successed"<<endl;


        sleep(1);

        pthread_t p_ids[ROBOT_SUM];

        for(int i=0;i<ROBOT_SUM;i++){

            robots[i]=get_robot(i);
            if(robots[i]->is_connected()){

                pthread_create(&p_ids[i],NULL,mov_thread,(void*)(robots[i]));
                pthread_detach(p_ids[i]);
            }
        }

    }

    while(true){

        sleep(1);

    }
    return 0;

}

