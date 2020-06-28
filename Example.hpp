#pragma once
#include <iostream>
float sum(float a, float b);

class DatabaseConnect
{
public:
   virtual bool login(std::string username, std::string password)
    {
        std::cout << "Inside databaseconnect login successful" << std::endl;
        return true;
    }
    virtual bool logout(std::string username)
    {
        std::cout << "Logout for user name " << username << "is successful " << std::endl;
        return true;
    }
   virtual  size_t fetchRecord()
    {
        return -1;
    }
};
/*We are going to test Mydatabase class, since DatabaseConnect 
is dependent on that we will create mock for that*/
class Mydatabase
{
    DatabaseConnect &m_db;

public:
    Mydatabase(DatabaseConnect & _db) : m_db(_db)
    {
    }
    bool testlogin(std::string username, std::string pass)
    {

        std::cout << "testlogin called " << std::endl;
        if (m_db.login(username, pass)==true)
        {
            std::cout << "success" << std::endl;
            return true;
        }
        else
        {
            std::cout << "login failed " << std::endl;
            return false;
        }
        return false;
    }
    bool testlogout(std::string username)
    {
        if (m_db.logout(username))
        {
            std::cout << "logout sucess " << std::endl;
        }
        else
        {
            std::cout << "logout failed " << std::endl;
        }
    }

    size_t testRecord()
    {
        return m_db.fetchRecord();
    }
};