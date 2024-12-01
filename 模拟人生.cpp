#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int hp( int,int );
int mood( int,int );
int mp( int,int );
int old_mp( int,int );
int m,p=0,t=0;
int main(){
    do{ 
    int life=0,left_life=100; //初始化寿命  //假设剩余寿命为100
    srand(unsigned(time(0))); //增加随机数
    while(left_life>0){
    	if(life<15){
    		mood(m,life);
    		if(p!=0||t!=0) cout<<"但你并不知道发生了什么"<<endl;		
		}
    	else if(life>=15&&life<=60){
    		mood(m,life);
            if(p==1){
        	    cout<<"你抑郁了，";
        	    left_life=hp(m,left_life);	
		    }
		    else if(t==1){
		    	cout<<"你欣喜若狂,";
		    	left_life=mp(m,left_life);
			}
            else if(p==2||t==2) cout<<"但对你没有影响"<<endl;
		}
		else if(life>60){
			mood(m,life);
			if(p==1){
				cout<<"你抑郁了，";
        	    left_life=hp(m,left_life);
			}
			else if(t==1){
				cout<<"你欣喜若狂，";
				left_life=old_mp(m,left_life);
			}
			else if(p==2||t==2) cout<<"但对你没有影响"<<endl;
		}
		if(left_life!=0){
		    life++; //成功活过了1年
		    left_life--;
	    }
        p=0,t=0;
        while(cin.get()=='\r') continue;
    }
    cout<<"你死了"<<endl;
    cout<<"你活了"<<life<<"岁"<<endl;
    cout<<"人最宝贵的是生命，因为它只有一次，请珍惜你自己的人生"<<endl;
    cout<<"按空格键继续，按ctrl+z退出"<<endl;
    }while(cin.get()!=EOF);
    cout<<"本轮游戏已结束，谢谢您的游玩,请按空格键退出";
    if(cin.get()=='\r') return 0;
}
int mood( int m,int life ){
    m=rand()%3; //判断是否遭遇不顺心的事
    if (m==0){
    	::p=rand()%2+1;/*遭遇不顺心的事后是否有消耗寿命的想法*/
    	cout<<"第"<<life<<"岁，你遭遇变故,";
	} 
	else if(m==1) cout<<"第"<<life<<"岁，无事发生"<<endl;
	else{
		::t=rand()%2+1;/*遭遇顺心的事后心情如何*/ 
		cout<<"第"<<life<<"岁，好事降临,"; 
	} 
    return 0;
}
int hp( int m, int left_life ){
    m=rand()%101; //想法严重程度
    if (m==0){
        left_life=0; //你自杀了
        cout<<"选择自杀"<<endl;
    }
    else if(m<=50){
	    left_life--; //你放肆了
	    cout<<"肆意酗酒玩乐"<<endl;
    }
    else cout<<"但最终忍住了"<<endl;
    return left_life;
}
int mp( int m, int left_life ){
	m=rand()%101;
	if(m==0){
		left_life++; //你锻炼了 
		cout<<"决心锻炼自己"<<endl; 
	}
	else if(m<=50){
		left_life--; //你饮酒了 
		cout<<"饮酒作乐"<<endl;
	}
	else cout<<"但并没有做什么改变"<<endl;
	return left_life;
}
int old_mp( int m, int left_life ){
	m=rand()%2;
	if(m==0){
		left_life--; //你饮酒了
		cout<<"饮酒作乐"<<endl; 
	}
	else cout<<"但并没有做什么改变"<<endl;
	return left_life;
}
