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
    string nativePlace;//籍贯
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
        cout<<"请输入以上功能所对应数字"<<endl;
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
            tag = false;//停止while循环
            break;
        case 8:
            mangeSystem = init();//实例
            
            break;
        }

        system("pause");
    }
    
}

//菜单函数
void item(){
    cout<<"欢迎来到通讯录管理系统！请输入您想实现功能所对应的数字"<<endl;
    cout<<"1:添加联系人"<<endl;
    cout<<"2:查询联系人"<<endl;
    cout<<"3:删除联系人"<<endl;
    cout<<"4:修改联系人信息"<<endl;
    cout<<"5:输出联系人信息"<<endl;
    cout<<"6:按学号排序"<<endl;
    cout<<"7:退出程序"<<endl;
    cout<<"8:初始化"<<endl;
}
//初始化函数
mangeSys init(){
    ifstream inputFile(FILENAME);

    if (!inputFile.is_open()) {
        cout << "初始化失败，请重试"<<endl;
        mangeSys output;
        return output;
    }else{
        cout<<"初始化成功！"<<endl;
    }

    vector<Student> ms;
    string line;
    
    //将每行的数据提取到student结构体中
    while(getline(inputFile,line)){
        istringstream iss(line);
        Student ms1;
        
        if(iss >> ms1.id >>ms1.name>>ms1.sex>>ms1.profession>>ms1.Class>>ms1.dormitoryId>>ms1.nativePlace>>ms1.number>>ms1.QQ>>ms1.wechat){
            ms.push_back(ms1);
        }else{
            cout<<"分割错误"<<endl;
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

//插入函数
void insert(mangeSys &ms){
    int tag = ms.nums;
    ms.nums++;
    string myid;
    string myname;
    string mysex;
    string myprofession;
    string myClass;
    string mydormitoryId;
    string mynativePlace;//籍贯
    string mynumber;
    string myQQ;
    string mywechat;
    
    cout<<"请输入学号"<<endl;
    cin>>myid;

    for(int i =0 ;i<tag;i++){
        if(myid == ms.student[i].id){
            cout<<"插入失败，学号已存在！"<<endl;
            ms.nums--;
            
            return ;
        }
    }


    ms.student[tag].id = myid;
    cout<<"请输入姓名"<<endl;
    cin>>myname;
    ms.student[tag].name = myname;
    cout<<"请输入性别"<<endl;
    cin>>mysex;
    ms.student[tag].sex = mysex;
    cout<<"请输入专业"<<endl;
    cin>>myprofession;
    ms.student[tag].profession = myprofession;
    cout<<"请输入班级"<<endl;
    cin>>myClass;
    ms.student[tag].Class = myClass;
    cout<<"请输入宿舍号"<<endl;
    cin>>mydormitoryId;
    ms.student[tag].dormitoryId = mydormitoryId;
    cout<<"请输入籍贯"<<endl;
    cin>>mynativePlace;
    ms.student[tag].nativePlace = mynativePlace;
    cout<<"请输入手机号"<<endl;
    cin>>mynumber;
    ms.student[tag].number = mynumber;
    cout<<"请输入QQ号"<<endl;
    cin>>myQQ;
    ms.student[tag].QQ = myQQ;
    cout<<"请输入微信号"<<endl;
    cin>>mywechat;
    ms.student[tag].wechat = mywechat;

    cout<<"添加成功！"<<endl;
}

//查询函数
void find(mangeSys &ms){
    string id;
    cout<<"请输入学号"<<endl;
    cin>>id;
    bool tag = false;//记录查询状态
    for(int i = 0;i<ms.nums;i++){
        if(id == ms.student[i].id){
            tag = true;
            cout<<"学号:"<<ms.student[i].id<<endl;
            cout<<"姓名:"<<ms.student[i].name<<endl;
            cout<<"性别:"<<ms.student[i].sex<<endl;
            cout<<"专业:"<<ms.student[i].profession<<endl;
            cout<<"班级:"<<ms.student[i].Class<<endl;
            cout<<"宿舍号:"<<ms.student[i].dormitoryId<<endl;
            cout<<"籍贯:"<<ms.student[i].nativePlace<<endl;
            cout<<"手机号:"<<ms.student[i].number<<endl;
            cout<<"QQ号:"<<ms.student[i].QQ<<endl;
            cout<<"微信号:"<<ms.student[i].wechat<<endl;
        }
    }
    if(!tag){
        cout<<"抱歉！没有查询到此人！"<<endl;
    }
}
//删除函数
void delete_student(mangeSys &ms){
    ms.nums--;
    string id;
    cout<<"请输入要删除联系人的学号"<<endl;
    cin>>id;
    int tag;//记录要删除的位置
    bool tags = true;
    for(int i = 0;i<=ms.nums;i++){
        if(id == ms.student[i].id){
            tag = i;
            tags = false;
        }
    }

    if(tags){
        cout<<"输入学号有误，删除失败！"<<endl;
        return;
    }



    for(int i = tag ;i<ms.nums;i++){
        ms.student[i] = ms.student[i+1];
    }
    Student student;
    ms.student[ms.nums] = student;

    cout<<"删除成功!"<<endl;


}
//修改信息
void alert(mangeSys &ms){
    string id;
    cout<<"请输入要修改信息的联系人学号"<<endl;
    cin>>id;
    int tag;//记录要修改的位置
    bool tags = true;
    for(int i = 0;i<=ms.nums;i++){
        if(id == ms.student[i].id){
            tag = i;
            tags = false;
        }
    }

    if(tags){
        cout<<"输入学号有误，删除失败！"<<endl;
        return;
    }

    string myid;
    string myname;
    string mysex;
    string myprofession;
    string myClass;
    string mydormitoryId;
    string mynativePlace;//籍贯
    string mynumber;
    string myQQ;
    string mywechat;
    
    cout<<"请输入修改后学号"<<endl;
    cin>>myid;
    for(int i =0 ;i<tag;i++){
        if(myid == ms.student[i].id){
            cout<<"修改失败，学号已存在！"<<endl;
            return ;
        }
    }
    ms.student[tag].id = myid;
    cout<<"请输入修改后姓名"<<endl;
    cin>>myname;
    ms.student[tag].name = myname;
    cout<<"请输入修改后性别"<<endl;
    cin>>mysex;
    ms.student[tag].sex = mysex;
    cout<<"请输入修改后专业"<<endl;
    cin>>myprofession;
    ms.student[tag].profession = myprofession;
    cout<<"请输入修改后班级"<<endl;
    cin>>myClass;
    ms.student[tag].Class = myClass;
    cout<<"请输入修改后宿舍号"<<endl;
    cin>>mydormitoryId;
    ms.student[tag].dormitoryId = mydormitoryId;
    cout<<"请输入修改后籍贯"<<endl;
    cin>>mynativePlace;
    ms.student[tag].nativePlace = mynativePlace;
    cout<<"请输入修改后手机号"<<endl;
    cin>>mynumber;
    ms.student[tag].number = mynumber;
    cout<<"请输入修改后QQ号"<<endl;
    cin>>myQQ;
    ms.student[tag].QQ = myQQ;
    cout<<"请输入修改后微信号"<<endl;
    cin>>mywechat;
    ms.student[tag].wechat = mywechat;

    cout<<"修改成功！"<<endl;

}


void output_list(mangeSys &ms){
   
    // 输出表头
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

    // 输出表格内容
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

//排序函数
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
//写入函数
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
            cout<<"通讯录数据已保存！"<<endl;
    }else{
        cout<<"通讯录数据保存失败！"<<endl;
    }
    
    
}