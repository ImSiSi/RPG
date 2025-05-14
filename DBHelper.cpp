#include "DBHelper.h"
#include <mysqlx/xdevapi.h>
#include <iostream>

class DBHelper::Impl {
public:
    Impl(): 
    session(new mysqlx::Session("localhost", 33060, "root", "qwqw60109")),
    schema(session->getSchema("testDatabase")),
    table(schema.getTable("user")){}

    ~Impl() {
        delete session;
    }

    int login(const std::string& account, const std::string& password) {
        try {
            int id;
            mysqlx::RowResult result = table.select("id")
                .where("account = :acc AND password = :pwd")
                .bind("acc", account)
                .bind("pwd", password)
                .execute();

            mysqlx::Row row = result.fetchOne();
            if(!row.isNull()){
                return row[0];
            }
            return -1;
        } catch (const mysqlx::Error& err) {
            std::cerr << "Login Error: " << err.what() << std::endl;
            return -1;
        }
    }

    bool signup(const std::string& account, const std::string& password) {
        try {
            mysqlx::RowResult check = table.select("account")
                .where("account = :acc")
                .bind("acc", account)
                .execute();

            if (check.count() > 0) {
                std::cout<<"帳號已存在"<<std::endl;
                return false; // 帳號已存在
            }

            table.insert("account", "password")
                .values(account, password)
                .execute();

            return true;
        } catch (const mysqlx::Error& err) {
            std::cerr << "Signup Error: " << err.what() << std::endl;
            return false;
        }
    }
    std::vector<std::string> getCharacter(const std::string& account, const std::string& password){
        try{
            int user_id = login(account, password);
            mysqlx::Table playerTable = schema.getTable("player");
            mysqlx::RowResult result = playerTable.select("id", "name", "job", "level")
                .where("user_id = :user_id")
                .bind("user_id", user_id)
                .execute();
            std::vector<std::string> vec;
            for(mysqlx::Row row : result){
                vec.push_back(std::to_string(row[0].get<int>()));
                vec.push_back(row[1].get<std::string>());
                vec.push_back(row[2].get<std::string>());
                vec.push_back(std::to_string(row[3].get<int>()));
            }
            return vec;
        }
        catch(const mysqlx::Error& err){
            std::cerr<< "loading error" << err.what()<<std::endl;
        }
        return {};
    }

private:
    mysqlx::Session* session;
    mysqlx::Schema schema;
    mysqlx::Table table;
};

// --- DBHelper Public API ---

DBHelper::DBHelper() {
    impl = new Impl();
}

DBHelper::~DBHelper() {
    delete impl;
}

int DBHelper::login(const std::string& account, const std::string& password) {
    return impl->login(account, password);
}

bool DBHelper::signup(const std::string& account, const std::string& password) {
    return impl->signup(account, password);
}
std::vector<std::string> DBHelper::getCharacter(const std::string& account, const std::string& password){
    return impl->getCharacter(account, password);
}