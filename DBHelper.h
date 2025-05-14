#ifndef DBHELPER_H
#define DBHELPER_H

#include <string>

class DBHelper {
public:
    DBHelper();
    ~DBHelper();

    int login(const std::string& account, const std::string& password);
    bool signup(const std::string& account, const std::string& password);
    std::vector<std::string> getCharacter(const std::string& account, const std::string& password);
private:
    class Impl;
    Impl* impl;
};

#endif