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
    int life=0,left_life=100; //��ʼ������  //����ʣ������Ϊ100
    srand(unsigned(time(0))); //���������
    while(left_life>0){
    	if(life<15){
    		mood(m,life);
    		if(p!=0||t!=0) cout<<"���㲢��֪��������ʲô"<<endl;		
		}
    	else if(life>=15&&life<=60){
    		mood(m,life);
            if(p==1){
        	    cout<<"�������ˣ�";
        	    left_life=hp(m,left_life);	
		    }
		    else if(t==1){
		    	cout<<"����ϲ����,";
		    	left_life=mp(m,left_life);
			}
            else if(p==2||t==2) cout<<"������û��Ӱ��"<<endl;
		}
		else if(life>60){
			mood(m,life);
			if(p==1){
				cout<<"�������ˣ�";
        	    left_life=hp(m,left_life);
			}
			else if(t==1){
				cout<<"����ϲ����";
				left_life=old_mp(m,left_life);
			}
			else if(p==2||t==2) cout<<"������û��Ӱ��"<<endl;
		}
		if(left_life!=0){
		    life++; //�ɹ������1��
		    left_life--;
	    }
        p=0,t=0;
        while(cin.get()=='\r') continue;
    }
    cout<<"������"<<endl;
    cout<<"�����"<<life<<"��"<<endl;
    cout<<"����������������Ϊ��ֻ��һ�Σ�����ϧ���Լ�������"<<endl;
    cout<<"���ո����������ctrl+z�˳�"<<endl;
    }while(cin.get()!=EOF);
    cout<<"������Ϸ�ѽ�����лл��������,�밴�ո���˳�";
    if(cin.get()=='\r') return 0;
}
int mood( int m,int life ){
    m=rand()%3; //�ж��Ƿ�������˳�ĵ���
    if (m==0){
    	::p=rand()%2+1;/*������˳�ĵ��º��Ƿ��������������뷨*/
    	cout<<"��"<<life<<"�꣬���������,";
	} 
	else if(m==1) cout<<"��"<<life<<"�꣬���·���"<<endl;
	else{
		::t=rand()%2+1;/*����˳�ĵ��º��������*/ 
		cout<<"��"<<life<<"�꣬���½���,"; 
	} 
    return 0;
}
int hp( int m, int left_life ){
    m=rand()%101; //�뷨���س̶�
    if (m==0){
        left_life=0; //����ɱ��
        cout<<"ѡ����ɱ"<<endl;
    }
    else if(m<=50){
	    left_life--; //�������
	    cout<<"�����������"<<endl;
    }
    else cout<<"��������ס��"<<endl;
    return left_life;
}
int mp( int m, int left_life ){
	m=rand()%101;
	if(m==0){
		left_life++; //������� 
		cout<<"���Ķ����Լ�"<<endl; 
	}
	else if(m<=50){
		left_life--; //�������� 
		cout<<"��������"<<endl;
	}
	else cout<<"����û����ʲô�ı�"<<endl;
	return left_life;
}
int old_mp( int m, int left_life ){
	m=rand()%2;
	if(m==0){
		left_life--; //��������
		cout<<"��������"<<endl; 
	}
	else cout<<"����û����ʲô�ı�"<<endl;
	return left_life;
}
