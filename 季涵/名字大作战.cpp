#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
int rushu,choose1,choose2,choose3;
int doint1 ;
struct people{
    int atk,ddf,hp,iq,su;
    string name;
    int zhan,go;
    int now_hp,zd;
    bool used,dead;
    int defen;
    int score;
    bool atk_used,ddf_used;
    int BOSs;
    int Tour_Skill,ma_bi; 
}a[1001];

void voids(void);
bool panduan(void);
void pugong(int,int);              //��ͨ���� 
void xiaolifeidao(int,int);        //���ܣ�С��ɵ� 
void huoqiushu(int,int);           //���ܣ�ʵ����ɱ���� 
void kuangbao(int);                //���ܣ����� 
void leijishu(int,int);            //���ܣ��׻��� 
void tiebishu(int);                //���ܣ������� 
void bingdongshu(int,int);         //���ܣ��������� 
void color(string);                //��ɫϵͳ----- 
void zhandui(int);                 //ս��ϵͳ----- (һ��ս��&���ְ� 
void zhandui_xun(int);             //ս��ϵͳ----- (����ս��&ս������&ս�Ӽӳ�
void zhandui_xun2(int,int);        //ͬ�� 
void zhandui_skill(int);           //ս��ϵͳ----- (����ս��&ս�Ӽ��� 
void wuqi_main(int);               //����ϵͳ������ 
void changqiongzhan(int,int);      //���ܣ����ն 
void huifushu(int);                //���ܣ��ָ���
void shixueyiji(int,int);          //���ܣ���Ѫһ�� 
void beici(int,int);               //���ܣ�����
void Slowsay(string);              //����Ż� 
void moshi1(void);                 //��Ҷ�սģʽ 
bool check(int);
bool comp1(people,people);
bool comp2(people,people);
void moshi2_boss();
void BOSS(int);
bool check2();
void peoples();
void BOSS_skill7(int);                //����Tour ר������ 
void dead();
void BOSS_skill8(int);                //ʥ�｣ʥ  ר������
void write1 () ;
int main () ;

void write1 () {
    system("cls");
    Slowsay ("���һ�θ��£�2021/9/29\n");
    Slowsay ("������Ҫ���ݣ�\n(1) ����BOSS ����Tour \n(2) ����BOSS ʥ�｣ʥ");
    Sleep (2500);
    main (); 
}

void BOSS_skill8(int j){
    Sleep(500);
    if(a[rushu+1].Tour_Skill==3){
        color("Y");cout<<"--ǧ�����سɽ���--"<<endl;Sleep(500);color("W");
        cout<<a[rushu+1].name<<"ʹ����---��---";color("R");cout<<"ʥ��֮���������Ĺ�â";color("W");cout<<"-----"<<endl;
        for(int l=1;l<=5;l++){Sleep(800);int shanghai=rand()%100+100;
            if(check2()==true) break;
            if(l==1){color("B");cout<<"��һʽ---ʥ��֮��";}
            else if(l==2){color("R");cout<<"�ڶ�ʽ---ʥ��֮��";}
            else if(l==3){color("G");cout<<"����ʽ---ʥ��֮��";}
            else if(l==4){color("Y");cout<<"����ʽ---ʥ��֮��";}
            else if(l==5){color("C");cout<<"����ʽ---ʥ��֮��";}
            int ffff=rand()%rushu+1;
            while(true){
                ffff=rand()%rushu+1;if(a[ffff].now_hp>0) break;
            }a[ffff].now_hp-=shanghai;voids();
            cout<<endl;color("W");cout<<"���"<<a[ffff].name<<"�ܵ���"<<shanghai<<" ���˺���Ŀǰʣ��Ѫ����";color("Y");cout<<a[ffff].now_hp;color("W");cout<<"/";color("C");cout<<a[ffff].hp<<endl;color("W");

        }
        a[rushu+1].Tour_Skill=0;
    }
    else{
        int fff; 
        while (true){
             fff = rand ();
             if (fff % 3 != 2) break;
             else if (fff % 3 == 2 && doint1 == 0) break;
        }
        if (fff % 4 == 0){
            cout<<a[rushu+1].name<<"ʹ����-----";color("C");cout<<"��ʥն��";color("W");cout<<"-----(S������)!"<<endl;
            int shanghai=a[rushu+1].atk-a[j].ddf+rand()%50;
            a[rushu+1].Tour_Skill++;
            a[j].now_hp-=shanghai;voids();
            cout<<"���"<<a[j].name<<"�ܵ���";color("R");cout<<shanghai;color("W");cout<<"���˺���Ŀǰʣ��Ѫ����";cout<<a[j].now_hp;color("W");cout<<"/";color("C");cout<<a[j].hp<<endl;color("W");
        }
        else if (fff % 4 == 1){
            a [rushu+1].Tour_Skill ++;
            cout << a [rushu + 1].name << "ʹ����-----"; color ("Y"); cout << "���з籩"; color ("W"); cout << "-----(S������)��" << endl;
            int aaa = 13 + (fff % 5);
            for (int i = 1;i <= aaa;i ++){
                Sleep (150); 
                int shanghai = 20 + rand ()% 10;
                while (true){
                    j = rand () % rushu + 1; if (a [j].now_hp > 0) break; 
                }
                cout << "���" << a [j].name << "�ܵ��� " ; color ("R"); cout << shanghai ; color ("W"); cout << " ���˺���" ;
                a [j].now_hp -= shanghai ; voids (); 
                cout << " Ŀǰʣ��Ѫ����" ; color ("Y"); cout << a [j].now_hp ; color ("W"); cout << "/"; color ("C"); cout << a[j].now_hp; color ("W"); cout << endl; 
            } 
        }   
        else if (fff % 4 == 2){
            a [rushu+1].Tour_Skill ++;
            cout << a [rushu + 1].name << "ʹ����-----"; color ("B"); cout << "��ʥ����" ; color ("W"); cout << "-----(S������)!" << endl ;
            cout << "����ֵÿ�غϻظ� 8%������3�غϣ�" <<endl;
            Sleep (500);
            doint1 = 3;
        }
        else if (fff % 4 == 3){
            a [rushu + 1].Tour_Skill ++;
            cout << " ";
        }
    }
} 

void dead(){
    for(int i=1;i<=rushu;i++){
        if(a[i].dead==false&&a[i].now_hp<=0)
            cout<<endl<<"��� "<<a[i].name<<" ����������"<<endl;
            a[i].dead=true;
    }
}

void BOSS_skill7(int j){
    Sleep(500);
    if(a[rushu+1].Tour_Skill==4){
        cout<<a[rushu+1].name<<" �Ѿ���ȡ���㹻�����񾫻���ʹ�����ˣ���"<<endl;Sleep(500);
        for(j=1;j<=rushu;j++){
            if(a[j].now_hp<=0) continue;
            int shanghai=max(128,a[j].now_hp/2);a[j].now_hp-=shanghai;voids();
            cout<<a[j].name<<"�ܵ���"<<shanghai<<"���˺�,Ŀǰʣ��Ѫ����"; color("Y");cout<<a[j].now_hp;color("W");cout<<"/";color("C");cout<<a[j].hp<<endl;
        }
        a[rushu+1].Tour_Skill=0;
    } 
    else{
        int fff=rand()%10000;
        while(true){
            if(fff%5==0&&a[rushu+1].now_hp==a[rushu+1].hp) fff=rand()%10000;
            else break;
        }
        if(fff%5==0){
            cout<<a[rushu+1].name<<"ʹ����-----";color("B");cout<<"������ȡ";color("W");cout<<"-----(S������)��"<<endl;int get=min(500,(a[rushu+1].hp-a[rushu+1].now_hp)*3/10);
            cout<<a[rushu+1].name<<"�ָ�������ʧ����ֵ��30%---(���500)---";color("G");cout<<"---"<<get; color("W");cout<<"   ������"<<endl;Sleep(1200);
            cout<<"Ŀǰ"<<a[rushu+1].name<<"ʣ������ֵΪ��";color("Y");cout<<"   "<<a[rushu+1].now_hp;color("W");cout<<"/";color("R");cout<<a[rushu+1].hp<<endl;color("W"); 
            a[rushu+1].Tour_Skill++;Sleep(500);color("C");
            cout<<endl<<a[rushu+1].name<<" ������1�����񾫻���Ŀǰ���񾫻�:" <<a[rushu+1].Tour_Skill<<"  !!"<<endl;color("W"); 
        }
        else if(fff%5==1||fff%5==2){
            cout<<a[rushu+1].name<<"ʹ����-----";color("B");cout<<"����һն";color("W");cout<<"-----(S������)��"<<endl;
            int shanghai=a[rushu+1].atk/2+a[rushu+1].iq*3/4-a[j].ddf*3/2+rand()%30;
            cout<<a[j].name<<"�ܵ���";
            color("R");cout<<shanghai;color("W");cout<<"���˺��������������һ�غ�ֹͣ�ж���"<<endl;
            a[j].used=true;a[j].now_hp-=shanghai;voids();
            Sleep(500); a[rushu+1].Tour_Skill++;
            cout<<a[j].name<<"Ŀǰʣ��Ѫ��:";cout<<"  ";color("Y");cout<<a[j].now_hp;color("W");cout<<"/";color("C");cout<<a[j].hp<<endl;color("W");
            Sleep(500);color("C");
            cout<<a[rushu+1].name<<" ������1�����񾫻���Ŀǰ���񾫻�:" <<a[rushu+1].Tour_Skill<<"  !!"<<endl;color("W");  
        }
        else if(fff%5==3){
            cout<<a[rushu+1].name<<"ʹ����-----";color("B");cout<<"�����׵�";color("W");cout<<"-----(S������)��"<<endl;
            for(int l=1;l<=3;l++){
                while(true){
                    j=rand()%rushu+1;
                    if(a[j].now_hp>0) break;
                } 
                Sleep(350); 
                int shanghai=a[rushu+1].iq-a[j].ddf*3/2+rand()%20;a[j].now_hp-=shanghai;voids();
                cout<<"���"<<a[j].name<<"�ܵ���";color("R");cout<<shanghai;color("W");cout<<"���˺�!Ŀǰʣ��Ѫ���� ";color("Y");cout<<a[j].now_hp;color("W");cout<<"/";color("C");cout<<a[j].hp<<endl;color("W");
            }
            a[rushu+1].Tour_Skill++;
            cout<<a[rushu+1].name<<" ������1�����񾫻���Ŀǰ���񾫻�:" <<a[rushu+1].Tour_Skill<<"  !!"<<endl;color("W");  
        }
        else if(fff%5==4){
            cout<<a[rushu+1].name<<"ʹ����-----";color("B");cout<<"�����Ʋ�";color("W");cout<<"-----(S������)!"<<endl;
            cout<<"�����˻����  ";color("Y");cout<<"���  ";color("W");cout<<"״̬������3�غϣ�����"<<endl;
            for(int i=1;i<=rushu;i++){
                if(a[i].now_hp>0)
                    a[i].ma_bi=3;
            }
            a[rushu+1].Tour_Skill++;
            cout<<a[rushu+1].name<<" ������1�����񾫻���Ŀǰ���񾫻�:" <<a[rushu+1].Tour_Skill<<"  !!"<<endl;color("W");  
        }
    }
}

void peoples(){
    Slowsay("��������սBOSS������\n");cin>>rushu;
        for(int i=1;i<=rushu;i++){
            Slowsay("���������");cout<<i;Slowsay("�����֣�\n");
            cin>>a[i].name;
            if(check(i)==false){
                while(true){Slowsay("�����ظ����������������");cout<<i;Slowsay("�����֣�\n");cin>>a[i].name;if(check(i)==true) break;else continue;}
            }   
        }
}

bool check2(){
    for(int i=1;i<=rushu;i++)
        if(a[i].now_hp>0)
            return false;
    return true;
}

void BOSS(int p){
    if(p==1){
        a[rushu+1].name="����";a[rushu+1].atk=200;a[rushu+1].ddf=120;a[rushu+1].iq=200;a[rushu+1].hp=1000;a[rushu+1].now_hp=1000;a[rushu+1].su=10;
    }else if(p==2){
        a[rushu+1].name="�۾���ɽ";a[rushu+1].atk=120;a[rushu+1].ddf=155;a[rushu+1].iq=30;a[rushu+1].hp=2500;a[rushu+1].now_hp=2500;a[rushu+1].su=10;
    }else if(p==3){
        a[rushu+1].name="а��satan";a[rushu+1].atk=300;a[rushu+1].ddf=65;a[rushu+1].iq=325;a[rushu+1].hp=1000;a[rushu+1].now_hp=1000;a[rushu+1].su=10;
    }else if(p==7){
        a[rushu+1].name="����Tour";a[rushu+1].atk=250;a[rushu+1].ddf=108;a[rushu+1].iq=250;a[rushu+1].hp=3000;a[rushu+1].now_hp=3000;a[rushu+1].su=10;a[rushu+1].BOSs=7;
    }else if(p==8){
        a[rushu+1].name="ʥ�｣ʥ";a[rushu+1].atk=300;a[rushu+1].ddf=85;a[rushu+1].iq=20;a[rushu+1].hp=3500;a[rushu+1].now_hp=3500;a[rushu+1].su=10;a[rushu+1].BOSs=8;
    } 
}

void moshi2_boss(){
    int choosex,choosep;
    Slowsay("��ӭ������սBOSSģʽ�������������ܵ���Ű���������Ͽ�У�\n��ѡ��BOSS�Ѷ�\n");
    while(true){
        Slowsay("(1) ���Ѷ�\n(2) ��ս�Ѷ�\n(3) �����Ѷ�\n(4) ج���Ѷ�\n");
        cin>>choosex;
        if(choosex==1||choosex==2||choosex==3||choosex==4) break;
        system("cls");
    }
    if(choosex==1){
        system("cls");
        Slowsay("��ѡ����[��ͨ�Ѷ�]����\n");
        Sleep(500);
        peoples();
        Slowsay("\n��ѡ������Ҫ��ս��BOSS\n");
        Slowsay("(1) ����\n(2) �۾���ɽ\n(3) а��Satan\n");
        cin>>choosep;
        if(choosep==1) BOSS(1);
        else if(choosep==2) BOSS(2);
        else if(choosep==3) BOSS(3);
    }
    else if(choosex==2){
        system("cls");
        Slowsay("��ѡ����[��ս�Ѷ�]����\n");
        Sleep(500);
        peoples();
        Slowsay("\n��ѡ������Ҫ��ս��BOSS\n");
        Slowsay("(1) ����\n(2) �Ͻ�����\n(3) ������\n");
        cin>>choosep;
        if(choosep==1) BOSS(4);
        else if(choosep==2) BOSS(5);
        else if(choosep==3) BOSS(6);
    }
    else if(choosex==3){
        system("cls");
        Slowsay("��ѡ����[�����Ѷ�]����\n");
        Sleep(500);
        peoples();
        Slowsay("\n��ѡ������Ҫ��ս��BOSS\n");
        Slowsay("(1) ����Tour\n(2) ʥ�｣ʥ\n(3) �Ͻ�ִ����\n");
        cin>>choosep;
        if(choosep==1) BOSS(7);
        else if(choosep==2) BOSS(8);
        else if(choosep==3) BOSS(9);
    }
    for(int i=1;i<=rushu;i++){
            a[i].atk=rand()%50+70;
            a[i].ddf=rand()%30+50;
            a[i].hp=rand()%200+500;
            a[i].su=rand()%10+1;
            a[i].iq=rand()%40+70;
            a[i].zhan=a[i].atk*16+a[i].ddf*18+a[i].hp*3+a[i].su*5+a[i].iq*15;
            a[i].now_hp=a[i].hp;
        }
    for(int i=1;i<=rushu;i++) zhandui(i);
    for(int i=1;i<=rushu;i++){
        if(a[i].zd==0) continue;
        else zhandui_xun(i);
    }
    for(int i=1;i<=rushu;i++) a[i].zhan=a[i].atk*16+a[i].ddf*18+a[i].hp*3+a[i].su*5+a[i].iq*15;
    a[rushu+1].zhan=a[rushu+1].atk*16+a[rushu+1].ddf*18+a[rushu+1].hp*3+a[rushu+1].su*5+a[rushu+1].iq*15;
    for(int i=1;i<=rushu+1;i++){
        Sleep(500);
        cout<<endl;
        if(i==rushu+1){
            cout<<"BOOS-----"<<a[i].name<<" ��������ս������Ϊ��"<<endl;Sleep(500); 
            cout<<"����:"<<a[i].atk<<"  ����:"<<a[i].ddf<<"  ����:"<<a[i].hp<<"  �ٶ�:"<<a[i].su<<"  ����:"<<a[i].iq<<endl;Sleep(500);
            cout<<a[i].name<<"ս����Ϊ:"<<a[i].zhan;
            cout<<endl;
            break;
        } 
        cout<<"���"<<i<<"�������ǣ�"<<a[i].name<<endl;Sleep(500);
        cout<<"����:"<<a[i].atk<<"  ����:"<<a[i].ddf<<"  ����:"<<a[i].hp<<"  �ٶ�:"<<a[i].su<<"  ����:"<<a[i].iq<<endl;Sleep(500);
        cout<<a[i].name<<"ս����Ϊ:"<<a[i].zhan;
        cout<<endl;
    }
    cout<<"\n\n";
    Slowsay("\n����1����������\n");int u;cin>>u;
    if(u==2) rushu++; 
    cout<<"����˳��\n";
    for(int i=1;i<=rushu;i++){
        cout<<"No."<<i<<" "<<a[i].name<<"\n";
    }int j,k=0;
    system("cls");
    cout<<endl<<"----���񹲷�"<<endl;
    Sleep(500);
    cout<<"                     �������----"<<endl;
    Sleep(500);
    cout<<"ս����ʼ��������������������������������"<<endl; Sleep(500); 
    while(true){
        for(int i=1;i<=rushu+1;i++){
            if(a[i].used==true){a[i].used=false;continue;}
            if(a[i].ma_bi>0){
                a[i].ma_bi--;a[i].now_hp-=50;voids();
                cout<<endl<<"���"<<a[i].name<<"���� ��� ״̬���յ���";color("B");cout<<50;color("W");cout<<" ���˺���Ŀǰʣ��Ѫ����";color("Y");cout<<a[i].now_hp;color("W");cout<<"/";color("C");cout<<a[i].hp<<endl<<endl;color("W");
            }
            if (i == rushu +1 && doint1 > 0){
                Sleep (250);
                cout << endl;
                int shanghai = (int) a [rushu + 1].hp * 0.08;a [rushu + 1].now_hp += shanghai ; voids ();
                cout << a [rushu + 1].name << "�ָ���" ; color ("G"); cout << shanghai; color ("W"); cout << " ������ֵ!  Ŀǰʣ������ֵ��" ; color ("Y"); cout << a [rushu + 1].now_hp ; color ("W"); cout << "/"; color ("C"); cout << a [rushu + 1].hp ; color ("W");
                doint1 --; 
                cout << endl;
            }
            if(a[i].now_hp<=0) continue;
            cout<<endl;
            if(i!=rushu+1) j=rushu+1;
            else if(i==rushu+1){
                while(true){j=rand()%rushu+1;if(a[j].now_hp>0) break;}
            }
            int fff=rand()%12000;
            if(a[rushu+1].now_hp<=0){k=1;break;}
            else if(check2()==true){k=1;break;}
            if(i==rushu+1&&a[i].BOSs==7) BOSS_skill7(j);
            else if(i==rushu+1&&a[i].BOSs==8) BOSS_skill8(j);
            else{
                while(true){
                    if(fff%10==4&&a[i].atk_used==true) fff=rand()%12000;
                    else if(fff%10==5&&a[i].ddf_used==true) fff=rand()%12000;
                    else if((fff%10==8||fff%10==9)&&a[i].now_hp==a[i].hp) fff=rand()%12000;
                    else break;
                }
                if(fff%10==1) pugong(i,j);
                if(fff%10==0) xiaolifeidao(i,j);
                else if(fff%10==2) huoqiushu(i,j);
                else if(fff%10==3) leijishu(i,j);
                else if(fff%10==4) kuangbao(i);
                else if(fff%10==5) tiebishu(i);
                //else if(fff%10==6) bingdongshu(i,j);
                else if(fff%10==7||fff%10==6) changqiongzhan(i,j);
                else if(fff%10==8) huifushu(i);
                else if(fff%10==9) shixueyiji(i,j);
            }
            cout<<endl;
            dead();
        }
        if(a[rushu+1].now_hp<=0||check2()==true) break;
    }
    Slowsay("-----ս������������-----\n");
    if(a[rushu+1].now_hp<=0) Slowsay("����ǻ�ʤ!\n");
    else if(check2()==true) Slowsay("BOSS��ʤ!\n");
}

bool comp2(people x,people y){
    return x.score>y.score;}

void voids (){
    for(int i=1;i<=rushu+1;i++){
        if(a[i].now_hp>=a[i].hp) a[i].now_hp=a[i].hp;
        else if(a[i].now_hp<=0) a[i].now_hp=0;
    }
}

bool panduan(){
    int f=0;
    for(int i=1;i<=rushu;i++)
        if(a[i].now_hp<=0)
            f++;
    if(f==rushu-1) return true;
    else return false;
}

bool comp(people x, people y){
return x.su>y.su;}

bool check(int i){
    if(i==1) return true; 
    for(int s=1;s<=i-1;s++){
        if(a[s].name == a[i].name)
            return false;
    } 
    return true;
}

void moshi1(void){
    Slowsay("���������������2~10001��\n");
    cin>>rushu;
    for(int i=1;i<=rushu;i++){
        Slowsay("���������");cout<<i;Slowsay("�����֣�\n");
        cin>>a[i].name;
        if(check(i)==false){
            while(true){Slowsay("�����ظ����������������");cout<<i;Slowsay("�����֣�\n");cin>>a[i].name;if(check(i)==true) break;else continue;}
        }   
    }
    for(int i=1;i<=rushu;i++){
        a[i].atk=rand()%50+70;
        a[i].ddf=rand()%30+50;
        a[i].hp=rand()%200+400;
        a[i].su=rand()%10+1;
        a[i].iq=rand()%40+70;
        a[i].zhan=a[i].atk*16+a[i].ddf*18+a[i].hp*3+a[i].su*5+a[i].iq*15;
        a[i].now_hp=a[i].hp;
    }
    for(int i=1;i<=rushu;i++){
        Sleep(500);
        cout<<endl;
        cout<<"���"<<i<<"�������ǣ�"<<a[i].name<<endl;Sleep(500);
        cout<<"����:"<<a[i].atk<<"  ����:"<<a[i].ddf<<"  ����:"<<a[i].hp<<"  �ٶ�:"<<a[i].su<<"  ����:"<<a[i].iq<<endl;Sleep(500);
        cout<<a[i].name<<"ս����Ϊ:"<<a[i].zhan;
        cout<<endl;
    }
    zhandui(1);zhandui(2);
    for(int i=1;i<=rushu;i++){
        if(a[i].zd==0) continue;
        else zhandui_xun(i);
    }
    cout<<"\n\n";
    Slowsay("����1����������0�˳�\n");
    cin>>choose1;
    if(choose1==0) cout<<"����!!"<<endl;
    else{
        system("cls");
        cout<<"������ʼ����ȴ�3�롣����"<<endl;
        Sleep(500); cout<<"3......"<<endl;
        Sleep(500); cout<<"2......"<<endl;
        Sleep(500); cout<<"1......"<<endl;
        cout<<"��ʼ!!"<<endl<<endl<<endl;
    }
    int max_su=0;
    for(int i=1;i<=rushu;i++) max_su=max(max_su,a[i].su);
    sort(a+1,a+rushu+1,comp);
    cout<<"����˳��\n";
    for(int i=1;i<=rushu;i++){
        cout<<"No."<<i<<" "<<a[i].name<<"\n";
    }
    int ko=rand()%rushu+1;
    Sleep(500);
    cout<<endl<<endl<<a[ko].name<<"�����յ�����ʥף����ȫ���Լ�10%!"<<endl;
    a[ko].atk+=a[ko].atk/10;
    a[ko].ddf+=a[ko].ddf/10;
    a[ko].hp+=a[ko].hp/10;
    a[ko].iq+=a[ko].iq/10;
    a[ko].now_hp=a[ko].hp;
    system("cls");
    cout<<endl<<"----���񹲷�"<<endl;
    Sleep(500);
    cout<<"                     �������----"<<endl;
    Sleep(500);
    cout<<"ս����ʼ����������������������������������"<<endl; 
    //system("cls");
    Sleep(500);
    int pko=0;
    while(panduan()==false){
        for(int i=1;i<=rushu;i++){
            if(a[i].used==true){a[i].used=false;continue;}
            if(a[i].now_hp<=0) continue;
            cout<<endl<<endl;
            int fff=rand(),j;
            while(true){j=rand()%rushu+1;if(j!=i&&a[j].now_hp>0) break;}
            //cout<<fff<<endl;
            while(true){
                if(fff%10==4&&a[i].atk_used==true) fff=rand()%12000;
                else if(fff%10==5&&a[i].ddf_used==true) fff=rand()%12000;
                else if((fff%10==8||fff%10==9)&&a[i].now_hp==a[i].hp) fff=rand()%12000;
                else break;
            }
            if(fff%10==1) pugong(i,j);
            if(fff%10==0) xiaolifeidao(i,j);
            else if(fff%10==2) huoqiushu(i,j);
            else if(fff%10==3) leijishu(i,j);
            else if(fff%10==4) kuangbao(i);
            else if(fff%10==5) tiebishu(i);
            else if(fff%10==6) bingdongshu(i,j);
            else if(fff%10==7) changqiongzhan(i,j);
            else if(fff%10==8) huifushu(i);
            else if(fff%10==9) shixueyiji(i,j);
            cout<<endl;
            if(panduan()==true){
                Sleep(500); 
                cout<<"\n\n";
                cout<<"ս��������"<<endl;
                Slowsay("------------------�÷ֱ�-------------------\n");int kol;
                for(int f=1;f<=rushu;f++)
                    if(a[f].now_hp>0) kol=f;
                Slowsay("��ʤ��-------");cout<<a[kol].name<<"!!!  �÷֣�"<<a[kol].score<<"\n";
                Slowsay("-------------------------------------------\n"); Sleep(500);
                sort(a+1,a+1+rushu,comp2);
                for(int f=1;f<=rushu;f++){
                        Sleep(250);
                        cout<<"���֣�"<<a[f].name<<"   �÷֣�"<<a[f].score<<endl; 
                }
            }
        }   
    }
    for(int i=1;i<=rushu;i++){
        a[i].zhan=a[i].atk*16+a[i].ddf*18+a[i].hp*3+a[i].su*5+a[i].iq*15;
        Sleep(500);
        cout<<endl;
        cout<<"���"<<i<<"�������ǣ�"<<a[i].name<<endl;
        cout<<"����:"<<a[i].atk<<"  ����:"<<a[i].ddf<<"  ����:"<<a[i].hp<<"  �ٶ�:"<<a[i].su<<"  ����:"<<a[i].iq<<endl;
        cout<<a[i].name<<"ս����Ϊ:"<<a[i].zhan;
        cout<<endl;
    }
    Slowsay("\n����1����������");int pop;cin>>pop;
    system("cls");
    moshi1();
}

void Slowsay(string s){
    for(int i=0;s[i];i++){
        cout<<s[i];
        Sleep(10);
    }
}

void shixueyiji(int i,int j){
    Sleep(500);
    int shanghai=a[i].atk*3/2+rand()%15;
    shanghai-=a[j].ddf*2/3;
    if(shanghai<=40) shanghai=40+rand()%15;
    cout<<a[i].name<<" ʹ����-----";color("Y");cout<<"��Ѫһ��";color("W");cout<<"-----(A������)"<<endl;
    a[j].now_hp-=shanghai;
    a[i].now_hp+=shanghai/2;
    Sleep(500);
    cout<<a[j].name<<"���ܵ��������������";color("R");cout<<shanghai<<endl;color("W");
    cout<<a[i].name<<" ��Ѫ�� �ָ���";color("G");cout<<shanghai/2<<endl;color("W");
    Sleep(450);cout<<"Ŀǰ����ʣ��Ѫ��-----    ";voids();
    color("G");cout<<a[i].now_hp;color("W");cout<<"/"<<" ";color("Y");cout<<a[i].hp;color("W"); 
    color("G");cout<<a[j].now_hp;color("W");cout<<"/"<<" ";color("Y");cout<<a[j].hp;color("W");
    a[i].score+=shanghai*3/2;
    a[j].score+=shanghai/3;
}

void huifushu(int i){
    Sleep(500);
    int shanghai=a[i].iq+a[i].atk/2;
    cout<<a[i].name<<"ʹ����-----";color("B");cout<<"�ָ���";color("W");cout<<"-----(B������)"<<endl;
    a[i].now_hp+=shanghai;
    Sleep(900);
    cout<<"�ָ���";color("G");cout<<shanghai;color("W");cout<<"����Ѫ��!";voids();
    cout<<"Ŀǰ"<<a[i].name<<"ʣ��Ѫ��-----    ";color("G");cout<<a[i].now_hp;color("W");cout<<"/";color("Y");cout<<a[i].hp;color("W");
    a[i].score+=shanghai;
}

void changqiongzhan(int i,int j){
    Sleep(500);
    cout<<"-----";
    color("R");cout<<"�񼼽���";color("W");cout<<"-----"<<endl; 
    Sleep(500);
    color("Y"); cout<<"-��-"<<endl;Sleep(500);
    color("G"); cout<<"-��-"<<endl;Sleep(500);
    color("B"); cout<<"-��-"<<endl;Sleep(500);
    color("C") ;cout<<"-��-"<<endl;Sleep(500);
    int shanghai=a[i].atk+a[i].iq+rand()%20;
    cout<<a[i].name<<" ʹ����-----";
    color("Y");cout<<"���ն��";color("W");cout<<"-----";color("R");cout<<"(�񼶼���)";color("W");cout<<"-----\n"; 
    Sleep(800);
    color("Y");cout<<"���Ǹ��£���֮һն��˺�Ѳ�񷣡"<<endl;color("W");
    Sleep(580);
    shanghai-=a[j].ddf;
    if(shanghai<=50) shanghai=50+rand()%20;
    a[j].now_hp-=shanghai;
    cout<<a[j].name<<"���ܵ���";
    color("R");cout<<shanghai;color("W");
    cout<<" ���˺���--------" <<endl;voids();
    cout<<"Ŀǰ "<<a[j].name<<"��ʣ��Ѫ��-----";cout<<a[j].now_hp;color("W");cout<<"/"<<" ";color("Y");cout<<a[j].hp;color("W");
    a[i].score+=shanghai;
    a[j].score+=shanghai/3;
} 

void zhandui(int i){
    if(a[i].name=="xiongxingzhuang"){a[i].zd=1;}
    else if(a[i].name=="lizewen"){a[i].zd=2;} 
    else if(a[i].name=="maozedong"||a[i].name=="�����ͬ־"||a[i].name=="�¶���ͬ־"){a[i].zd=3;}
    else if(a[i].name=="satan") a[i].zd=4;
    else if(a[i].name=="god_down") a[i].zd=5;
    else if(a[i].name=="power") a[i].zd=6;
    else if(a[i].name=="zengchiye") a[i].zd=7;
    else if(a[i].name=="bangbangchui") a[i].zd=8;
} 

void zhandui_xun(int i){
    color("R");
    Sleep(500);
    cout<<endl;
    cout<<"��������ս��___ϵͳ������"<<endl;color("W");
    Sleep(500);
    for(int j=1;j<=100;j++){
        if(a[i].zd==j){
            zhandui_xun2(j,i);
            break;
        }
    }
}

void zhandui_xun2(int j,int i){
    cout<<a[i].name<<"   ----    ";
    if(j==1){color("R");cout<<"priority_queue_ս��";} 
    else if(j==2){color("BULE");cout<<"Sir_ս��";}
    else if(j==3){color("Y");cout<<"����֮��_ս��";}
    else if(j==4){color("R");cout<<"��������_SSRPOWER(BOSS����)";}
    else if(j==5){color("R");cout<<"��������_SSRPOWER(BOSS����)";}
    else if(j==6){color("C");cout<<"��������__ʥ��(BOSS����)";}
    else if(j==7){color("Y");cout<<"����&����";}
    else if(j==8){color("Y");cout<<"����&����";}
    color("W");
    Sleep(500);
    cout<<"-----"<<endl;
    Sleep(500);
    cout<<"ս�����⼼��  �� ";
    if(j==1){color("C");cout<<"�ȷ�����-----Ч��:���ȳ���һ��"<<endl;a[i].su+=10;a[i].atk+=120;a[i].iq+=120;a[i].now_hp+=2000;a[i].hp+=2000;a[i].ddf+=50;} 
    else if(j==2){color("B");cout<<"��ʿ������-----Ч��:����������(����������)"<<endl;a[i].atk+=15;}
    else if(j==3){color("B");cout<<"ũ�������-----Ч��:������������"<<endl;a[i].hp+=80;a[i].now_hp+=80;}
    else if(j==4){color("R");cout<<"BUG_BOSS_�޷�սʤ����----Ч����ȫ�������ӣ�"<<endl;a[i].now_hp+=1200;a[i].iq+=45;a[i].atk+=40;a[i].su+=5;a[i].ddf+=10;a[i].hp+=1200;}
    else if(j==5){color("R");cout<<"����--��ʥף��-- ^^^��Ч�������������ӣ�ȫ���Խ���"<<endl;a[i].atk=a[i].atk*3;a[i].ddf-=5;a[i].now_hp+=200;a[i].su+=10;a[i].iq+=120;a[i].hp+=200;}
    else if(j==6){color("B");cout<<"��������-----Ч���������������ӣ�����������"<<endl;a[i].hp+=1500;a[i].now_hp+=1500;a[i].ddf+=100;a[i].iq+=20;}
    else if(j==7){color("G");cout<<"��";color("R");cout<<"λ";color("Y");cout<<"��";color("C");cout<<"ѹ";color("B");cout<<"-----Ч����ȫ���Դ������ǿ";
                 a[i].hp+=12000;a[i].now_hp+=5000;a[i].atk+=2600;a[i].iq+=3000;a[i].ddf+=1000;a[i].su+=100;}
    else if(j==8){color("G");cout<<"��";color("R");cout<<"λ";color("Y");cout<<"��";color("C");cout<<"ѹ";color("B");cout<<"-----Ч����ȫ���Դ������ǿ";
                 a[i].hp+=30000;a[i].now_hp+=30000;a[i].atk+=1000;a[i].iq+=1000;a[i].ddf+=3000;}
    color("W");
    cout<<endl;
}

void color(string i){
    if(i=="B")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    else if(i=="W")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    else if(i=="R")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    else if(i=="Y")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    else if(i=="G")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    else if(i=="C")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
    //else if(i=="MAGENTA");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_R | FOREGROUND_B);
}

void bingdongshu(int i,int j){
    Sleep(500);
    int shanghai=a[i].iq+rand()%10;
    shanghai-=a[j].ddf*5/4;
    if(shanghai<=20) shanghai=20+rand()%10;
    a[j].now_hp-=shanghai;
    cout<<a[i].name<<" ʹ����----";
    color("B");cout<<"��������";color("W");
    cout<<"----��A�����ܣ�"<<endl;
    a[j].used=true;
    Sleep(500);
    cout<<a[j].name<<" ��ħ�����������ˣ��»غ��޷��ж���"<<endl;
    Sleep(500);
    cout<<"ͬʱ�ܵ���";
    color("R"); cout<<shanghai;color("W");
    cout<<" ��";voids();
    color("G");cout<<"ħ���˺�";color("W");cout<<endl;cout<<"Ŀǰ"<<a[j].name<<"ʣ��Ѫ��----"; 
    cout<<a[j].now_hp;color("W");cout<<"/"<<" ";color("Y");cout<<a[j].hp;color("W");
    a[i].score+=shanghai*3/2;
}

void tiebishu(int i){
    Sleep(500);
    int get_atk=a[i].iq/5+rand()%10;
    a[i].ddf+=get_atk;
    cout<<a[i].name<<" ʹ����----";
    color("B");cout<<"������";color("W");
    cout<<"----��B�����ܣ�"<<endl;
    Sleep(500);
    cout<<a[i].name<<" ����������";
    color("R");cout<<get_atk;color("W");
    cout<<" �㣡Ŀǰ��������"<<a[i].ddf<<endl;
    a[i].score+=get_atk*2;
    a[i].ddf_used=true;
}

void kuangbao(int i){
    Sleep(500);
    int get_atk=a[i].iq/3+rand()%10;
    a[i].atk+=get_atk;
    a[i].iq+=get_atk/3;
    cout<<a[i].name<<" ʹ����----";
    color("B");cout<<"����";color("W");
    cout<<"----��B�����ܣ�"<<endl;
    cout<<a[i].name<<" ����������";
    color("R");cout<<get_atk;color("W");
    cout<<" �㣡Ŀǰ��������"<<a[i].atk<<endl;
    a[i].score+=get_atk*2;
    a[i].atk_used=true;
}

void leijishu(int i,int j){
    Sleep(500);
    int shanghai=a[i].iq*3/8;
    int nice=rand()%4+3;
    int resthp=0;
    cout<<a[i].name<<" ʹ����----";
    color("Y");cout<<"�׻���";color("W");
    cout<<"----��A������)��"<<endl;
    for(int p=1;p<=nice;p++){
        Sleep(500);
        for(int f=1;f<=p;f++) cout<<" ";
        int lo=shanghai-a[j].ddf/4+rand()%10;
        if(lo<=10) lo=10+rand()%10;
        a[j].now_hp-=lo;
        resthp+=lo;
        cout<<a[i].name<<" �� "<<a[j].name<<"������ˡ�";
        color("R");cout<<lo;color("W");
        cout<<"���˺���"<<endl;
        if(p==nice){
            Sleep(500);
            cout<<"�����";voids();
            color("R");cout<<resthp;color("W");
            cout<<" ���˺�\n";
            cout<<a[j].name<<" ʣ��Ѫ��-----";cout<<a[j].now_hp;color("W");cout<<"/"<<" ";color("Y");cout<<a[j].hp;color("W");
            a[i].score+=resthp*4/3;
            a[j].score+=resthp/3;
        }
    }
}

void huoqiushu(int i,int j){
    Sleep(500);
    int num=rand()%100+50;
    int shanghai=a[i].atk*9/5;
    shanghai-=a[j].ddf;
    if(shanghai<=40) shanghai=40+rand()%5;
    a[j].now_hp-=shanghai;
    cout<<a[i].name<<"ʹ����-----";
    color("R");cout<<"ʵ����ɱ����";color("W");
    cout<<"��S�����ܣ�------"<<endl;
    Sleep(500); 
    cout<<a[j].name<<"�ܵ���";
    color("R");cout<<shanghai;color("W");
    cout<<"���˺���\n"<<endl;voids();
    cout<<a[j].name<<" Ŀǰʣ��Ѫ��-----";cout<<a[j].now_hp;color("W");cout<<"/"<<" ";color("Y");cout<<a[j].hp;color("W");
    a[i].score+=shanghai;
    a[j].score+=shanghai/3;
}

void pugong(int i,int j){
    Sleep(500); 
    int num=rand()%15+5;
    int shanghai=num+a[i].atk;
    if(shanghai<a[j].ddf+15) shanghai=a[j].ddf+15;
    int lose=shanghai-a[j].ddf;
    a[j].now_hp-=lose;voids();
    cout<<a[j].name<<"�ܵ�������  ���"<<a[i].name<<"�Ĺ�����"<<endl;
    cout<<"--------------�����"<<lose<<"���˺�\nĿǰ"<<a[i].name<<"ʣ��Ѫ��-----";cout<<a[j].now_hp;color("W");cout<<"/"<<" ";color("Y");cout<<a[j].hp;color("W");
    a[i].score+=lose;
    a[j].score+=lose/3;
}

void xiaolifeidao(int i,int j){
    Sleep(500);
    int num=rand()%100+65,get;
    int shanghai;
    shanghai=a[i].atk*5/12-a[j].ddf*5/4+a[i].iq+num/8;
    if(shanghai<=20) shanghai=20+rand()%3;
    a[j].now_hp-=shanghai;
    cout<<a[i].name<<" �����ڴ����ͳ�һ��ذ�ס�����";
    Sleep(500);
    cout<<"�����ؼ�,--------";
    color("G");cout<<"С��ɵ�";color("W");
    cout<<"---------������C�����ܣ�"<<endl;
    Sleep(500);
    cout<<a[i].name<<"��ذ�׳��� "<<a[j].name<<" ���˹�ȥ�������" ;
    color("R");cout<<shanghai;color("W");
    cout<<"���˺�\n"<<endl;voids();
    cout<<"Ŀǰ "<<a[j].name<<" ʣ��Ѫ��-----";cout<<a[j].now_hp;color("W");cout<<"/"<<" ";color("Y");cout<<a[j].hp;color("W");
    a[i].score+=shanghai*3/2;
    a[j].score+=shanghai/2;
    Sleep(500);
    if(num%2==1){
        cout<<"--------��û�꣡  "<<a[i].name<<" ��--С��ɵ�--��C�����ܣ�������"<<endl;
         a[j].now_hp-=shanghai/2;voids();
         cout<<"--------------�����"<<shanghai/2<<"���˺�\nĿǰ"<<a[j].name<<"ʣ��Ѫ��-----"<< a[j].now_hp<<"/"<< a[j].hp<<endl;
    }
}

int main(){
    system("cls");
    srand(time(0));
    color("W");
    Slowsay("��ӭ�������ִ���ս��    -----���ߣ�Mr Egg.\n");Sleep(500);
    Slowsay("��ѡ��......\n");Sleep(500);
    while(true){
        na:;
        Slowsay("(1) ��ʼ��Ϸ\n(2) �鿴������־\n(3) ����\n(4) ��Ϸ���\n");
        cin>>choose1;
        if(choose1==1||choose1==2||choose1==3||choose1==4) break;
        else system("cls");
    }
    if(choose1==1){
        system("cls");
        Slowsay("----------��ѡ����Ϸģʽ----------\n");
        while(true){
        Slowsay("(1)  ��Ҷ�սģʽ\n(2)  ��սBOSSģʽ \n(3)  [���Ѷ�]��սϵͳ�Ŷ�ģʽ \n(4)  ����ģʽ(������) \n(5)  ����������\n");
        cin>>choose2;if(choose2>=1&&choose2<=5) break;else system("cls");
        }
        if(choose2==5){system("cls");goto na;}
        else if(choose2==1){system("cls");moshi1();}
        else if(choose2==2){system("cls");moshi2_boss();}
    }
    else if (choose1 == 2){
        write1 ();
    }
}
