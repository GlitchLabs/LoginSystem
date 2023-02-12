//
//  Login.hpp
//  Login System
//
//  Created by Dakir Thompson on 2/4/23.
//

#ifndef Login_hpp
#define Login_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#endif /* Login_hpp */

class Login//Should this be static? only one per program?
{
public:
    Login();
    void start(void);
private:
    std::string m_username;
    std::string m_password;
    std::string m_file = "/Users/dakirthompson/Glitch Labs/userInfoFile.txt";
    bool m_LoggedIn = false;
    bool m_correctUserName = false;
    bool m_correctPassWord = false;
private://Private methods
    void getInfo();
    void saveInfo();
    void verifyNewUser(std::string uInfo);
    
};
