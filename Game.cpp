#include"Character.h"
#include"DBHelper.h"
#include<iostream>
#include<cstdlib>
#include<mysqlx/xdevapi.h>

int main(){
    std::cout<<"Welcome to the game"<<std::endl;
    std::string check ;
    DBHelper sql;
    while(check != "A" && check != "B"){
        std::cout<<"A Log in       B sign up"<<std::endl;
        std::cin>>check;
    }
    std::string account;
    std::string password;
    while(check == "B"){
        std::cout<<"Account : ";
        std::cin>>account;
        std::cout<<"Password : ";
        std::cin>>password;
        if(sql.signup(account, password) == true){
            std::cout<<"註冊成功"<<std::endl
                    <<"請登入"<<std::endl;
            check = "A";
            break;
        }
        std::cout<<"Something is wrong, please try again"<<std::endl;
    }
    while(check == "A"){
        std::cout<<"Account : ";
        std::cin>>account;
        std::cout<<"Password : ";
        std::cin>>password;
        int id = sql.login(account, password);
        while(sql.login(account, password) == -1){
            std::cout<<"帳號或密碼錯誤, 請再試一次"<<std::endl;
            std::cout<<"Account : ";
            std::cin>>account;
            std::cout<<"Password : ";
            std::cin>>password;
            id = sql.login(account, password);
        }
        std::cout<<"登入成功"<<std::endl;
        break;
        
    }
    std::vector<std::string> vec = sql.getCharacter(account, password);
    std::cout<<"角色名稱 : "<<vec[1]<< "  職業 : "<< vec[2]<< "  等級 : " << vec[3]; 
    
    
    return 0;
}