#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
 #include<stdlib.h>
 #include<iomanip>




using namespace std;

const string FILENAME = "student.txt";
const int nums_max = 100;


struct Student{
    string id;
    string name;
    string sex;
    string profession;
    string Class;
    string dormitoryId;
    string nativePlace;//����
    string number;
    string QQ;
    string wechat;
};
struct mangeSys{
    struct Student student[nums_max];
    int nums;
};



void item();
mangeSys init();
void insert(mangeSys &ms);
void find(mangeSys &ms);
void delete_student(mangeSys &ms);
void alert(mangeSys &ms);
void output_list(mangeSys &ms);
void sort(mangeSys &ms);
void writes(mangeSys &ms);




int main(){
 
    mangeSys mangeSystem;

    bool tag = true;
    while(tag){
        
         system("cls");
        item();
        int num;
        cout<<"���������Ϲ�������Ӧ����"<<endl;
        cin>>num;
        switch (num)
        {
        case 1:
            insert(mangeSystem);
            break;
        case 2:
            find(mangeSystem);
            break;
        case 3:
            delete_student(mangeSystem);
            break;
        case 4:
            alert(mangeSystem);
            break;
        case 5:
            output_list(mangeSystem);
            break;
        case 6:
            sort(mangeSystem);
            output_list(mangeSystem);
            break;
        case 7:
            cout<<"bye!"<<endl;
            writes(mangeSystem);
            tag = false;//ֹͣwhileѭ��
            break;
        case 8:
            mangeSystem = init();//ʵ��
            
            break;
        }

        system("pause");
    }
    
}

//�˵�����
void item(){
    cout<<"��ӭ����ͨѶ¼����ϵͳ������������ʵ�ֹ�������Ӧ������"<<endl;
    cout<<"1:�����ϵ��"<<endl;
    cout<<"2:��ѯ��ϵ��"<<endl;
    cout<<"3:ɾ����ϵ��"<<endl;
    cout<<"4:�޸���ϵ����Ϣ"<<endl;
    cout<<"5:�����ϵ����Ϣ"<<endl;
    cout<<"6:��ѧ������"<<endl;
    cout<<"7:�˳�����"<<endl;
    cout<<"8:��ʼ��"<<endl;
}
//��ʼ������
mangeSys init(){
    ifstream inputFile(FILENAME);

    if (!inputFile.is_open()) {
        cout << "��ʼ��ʧ�ܣ�������"<<endl;
        mangeSys output;
        return output;
    }else{
        cout<<"��ʼ���ɹ���"<<endl;
    }

    vector<Student> ms;
    string line;
    
    //��ÿ�е�������ȡ��student�ṹ����
    while(getline(inputFile,line)){
        istringstream iss(line);
        Student ms1;
        
        if(iss >> ms1.id >>ms1.name>>ms1.sex>>ms1.profession>>ms1.Class>>ms1.dormitoryId>>ms1.nativePlace>>ms1.number>>ms1.QQ>>ms1.wechat){
            ms.push_back(ms1);
        }else{
            cout<<"�ָ����"<<endl;
        }

    }

    
    mangeSys output ;
    output.nums = ms.size();
    
    for (int i = 0;i < std::min(output.nums, nums_max);++i) {
        output.student[i] = ms[i];
    }

    inputFile.close();

    return output;
}

//���뺯��
void insert(mangeSys &ms){
    int tag = ms.nums;
    ms.nums++;
    string myid;
    string myname;
    string mysex;
    string myprofession;
    string myClass;
    string mydormitoryId;
    string mynativePlace;//����
    string mynumber;
    string myQQ;
    string mywechat;
    
    cout<<"������ѧ��"<<endl;
    cin>>myid;

    for(int i =0 ;i<tag;i++){
        if(myid == ms.student[i].id){
            cout<<"����ʧ�ܣ�ѧ���Ѵ��ڣ�"<<endl;
            ms.nums--;
            
            return ;
        }
    }


    ms.student[tag].id = myid;
    cout<<"����������"<<endl;
    cin>>myname;
    ms.student[tag].name = myname;
    cout<<"�������Ա�"<<endl;
    cin>>mysex;
    ms.student[tag].sex = mysex;
    cout<<"������רҵ"<<endl;
    cin>>myprofession;
    ms.student[tag].profession = myprofession;
    cout<<"������༶"<<endl;
    cin>>myClass;
    ms.student[tag].Class = myClass;
    cout<<"�����������"<<endl;
    cin>>mydormitoryId;
    ms.student[tag].dormitoryId = mydormitoryId;
    cout<<"�����뼮��"<<endl;
    cin>>mynativePlace;
    ms.student[tag].nativePlace = mynativePlace;
    cout<<"�������ֻ���"<<endl;
    cin>>mynumber;
    ms.student[tag].number = mynumber;
    cout<<"������QQ��"<<endl;
    cin>>myQQ;
    ms.student[tag].QQ = myQQ;
    cout<<"������΢�ź�"<<endl;
    cin>>mywechat;
    ms.student[tag].wechat = mywechat;

    cout<<"��ӳɹ���"<<endl;
}

//��ѯ����
void find(mangeSys &ms){
    string id;
    cout<<"������ѧ��"<<endl;
    cin>>id;
    bool tag = false;//��¼��ѯ״̬
    for(int i = 0;i<ms.nums;i++){
        if(id == ms.student[i].id){
            tag = true;
            cout<<"ѧ��:"<<ms.student[i].id<<endl;
            cout<<"����:"<<ms.student[i].name<<endl;
            cout<<"�Ա�:"<<ms.student[i].sex<<endl;
            cout<<"רҵ:"<<ms.student[i].profession<<endl;
            cout<<"�༶:"<<ms.student[i].Class<<endl;
            cout<<"�����:"<<ms.student[i].dormitoryId<<endl;
            cout<<"����:"<<ms.student[i].nativePlace<<endl;
            cout<<"�ֻ���:"<<ms.student[i].number<<endl;
            cout<<"QQ��:"<<ms.student[i].QQ<<endl;
            cout<<"΢�ź�:"<<ms.student[i].wechat<<endl;
        }
    }
    if(!tag){
        cout<<"��Ǹ��û�в�ѯ�����ˣ�"<<endl;
    }
}
//ɾ������
void delete_student(mangeSys &ms){
    ms.nums--;
    string id;
    cout<<"������Ҫɾ����ϵ�˵�ѧ��"<<endl;
    cin>>id;
    int tag;//��¼Ҫɾ����λ��
    bool tags = true;
    for(int i = 0;i<=ms.nums;i++){
        if(id == ms.student[i].id){
            tag = i;
            tags = false;
        }
    }

    if(tags){
        cout<<"����ѧ������ɾ��ʧ�ܣ�"<<endl;
        return;
    }



    for(int i = tag ;i<ms.nums;i++){
        ms.student[i] = ms.student[i+1];
    }
    Student student;
    ms.student[ms.nums] = student;

    cout<<"ɾ���ɹ�!"<<endl;


}
//�޸���Ϣ
void alert(mangeSys &ms){
    string id;
    cout<<"������Ҫ�޸���Ϣ����ϵ��ѧ��"<<endl;
    cin>>id;
    int tag;//��¼Ҫ�޸ĵ�λ��
    bool tags = true;
    for(int i = 0;i<=ms.nums;i++){
        if(id == ms.student[i].id){
            tag = i;
            tags = false;
        }
    }

    if(tags){
        cout<<"����ѧ������ɾ��ʧ�ܣ�"<<endl;
        return;
    }

    string myid;
    string myname;
    string mysex;
    string myprofession;
    string myClass;
    string mydormitoryId;
    string mynativePlace;//����
    string mynumber;
    string myQQ;
    string mywechat;
    
    cout<<"�������޸ĺ�ѧ��"<<endl;
    cin>>myid;
    for(int i =0 ;i<tag;i++){
        if(myid == ms.student[i].id){
            cout<<"�޸�ʧ�ܣ�ѧ���Ѵ��ڣ�"<<endl;
            return ;
        }
    }
    ms.student[tag].id = myid;
    cout<<"�������޸ĺ�����"<<endl;
    cin>>myname;
    ms.student[tag].name = myname;
    cout<<"�������޸ĺ��Ա�"<<endl;
    cin>>mysex;
    ms.student[tag].sex = mysex;
    cout<<"�������޸ĺ�רҵ"<<endl;
    cin>>myprofession;
    ms.student[tag].profession = myprofession;
    cout<<"�������޸ĺ�༶"<<endl;
    cin>>myClass;
    ms.student[tag].Class = myClass;
    cout<<"�������޸ĺ������"<<endl;
    cin>>mydormitoryId;
    ms.student[tag].dormitoryId = mydormitoryId;
    cout<<"�������޸ĺ󼮹�"<<endl;
    cin>>mynativePlace;
    ms.student[tag].nativePlace = mynativePlace;
    cout<<"�������޸ĺ��ֻ���"<<endl;
    cin>>mynumber;
    ms.student[tag].number = mynumber;
    cout<<"�������޸ĺ�QQ��"<<endl;
    cin>>myQQ;
    ms.student[tag].QQ = myQQ;
    cout<<"�������޸ĺ�΢�ź�"<<endl;
    cin>>mywechat;
    ms.student[tag].wechat = mywechat;

    cout<<"�޸ĳɹ���"<<endl;

}


void output_list(mangeSys &ms){
   
    // �����ͷ
    std::cout << std::internal << std::setw(15) << "ID"
              << std::internal << std::setw(15) << "Name"
              << std::internal << std::setw(15) << "Sex"
              << std::internal << std::setw(15) << "Profession"
              << std::internal << std::setw(15) << "Class"
              << std::internal << std::setw(15) << "Dormitory ID"
              << std::internal << std::setw(15) << "Native Place"
              << std::internal<< std::setw(15) << "Number"
              << std::internal << std::setw(15) << "QQ"
              << std::internal << std::setw(15) << "WeChat" << std::endl;

    // ����������
    for (int i = 0;i < ms.nums;i++) {
        std::cout << std::internal << std::setw(15) << ms.student[i].id
                  << std::internal << std::setw(15) << ms.student[i].name
                  << std::internal << std::setw(15) << ms.student[i].sex
                  << std::internal << std::setw(15) << ms.student[i].profession
                  << std::internal << std::setw(15) << ms.student[i].Class
                  << std::internal << std::setw(15) << ms.student[i].dormitoryId
                  << std::internal<< std::setw(15) << ms.student[i].nativePlace
                  << std::internal << std::setw(15) << ms.student[i].number
                  << std::internal << std::setw(15) << ms.student[i].QQ
                  << std::internal << std::setw(15) << ms.student[i].wechat
                  << std::endl;
    }

}

void swapms(Student &st1, Student &st2){
    Student st;
    st = st1;
    st1 = st2;
    st2 = st;
}

//������
void sort(mangeSys &ms){
    
    for(int i = 0;i<ms.nums;i++){
        for(int j = 0;j<ms.nums - i -1;j++){
            long long int a = stoi(ms.student[j].id);
            long long int b = stoi(ms.student[j+1].id);

            if(a>b){
                swap(ms.student[j],ms.student[j+1]);
            }
        }
    }
}
//д�뺯��
void writes(mangeSys &ms){
    ofstream outputfile(FILENAME);

    if(outputfile.is_open()){
        for(int i = 0;i<ms.nums;i++){
            outputfile<<ms.student[i].id<<' '<<
            ms.student[i].name<<" "<<
            ms.student[i].sex<<" "<<
            ms.student[i].profession<<" "<<
            ms.student[i].Class<<" "<<
            ms.student[i].dormitoryId<<" "<<
            ms.student[i].nativePlace<<" "<<
            ms.student[i].number<<" "<<
            ms.student[i].QQ<<" "<<
            ms.student[i].wechat<<endl;
            
        }
        outputfile.close();
            cout<<"ͨѶ¼�����ѱ��棡"<<endl;
    }else{
        cout<<"ͨѶ¼���ݱ���ʧ�ܣ�"<<endl;
    }
    
    
}