#include <mysqlx/xdevapi.h>
#include <iostream>
#include <iomanip>    // for std::setfill, std::setw
#include <ctime>      // for std::tm

int main() {
    try {
        mysqlx::Session sess("localhost", 33060, "root", "qwqw60109");
        mysqlx::Schema db = sess.getSchema("testDatabase");

        mysqlx::Table user = db.getTable("user");
        mysqlx::RowResult result = user.select("id", "username", "mail", "DATE_FORMAT(create_time, '%Y-%m-%d %H:%i:%s')").execute();

        for (mysqlx::Row row : result) {
            int id = row[0].get<int>();
            std::string username = row[1].get<std::string>();
            std::string mail = row[2].get<std::string>();
            std::string date = row[3].get<std::string>(); // 可改這行
            std::cout << "User ID: " << id << "\n"
                      << "Username: " << username << "\n"
                      << "Mail: " << mail << "\n"
                      <<" Create time : " << date<<"\n";

        }


    } catch (const mysqlx::Error &err) {
        std::cerr << "MySQL Error: " << err.what() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "STD Exception: " << ex.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error!" << std::endl;
    }

    return 0;
}