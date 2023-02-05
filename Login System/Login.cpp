//
//  Login.cpp
//  Login System
//
//  Created by Dakir Thompson on 2/4/23.
//

#include "Login.hpp"

Login::Login()
{
    std::cout << "Login system created\n";
}

void Login::start()
{
    std::string un;
    std::string pw;
    int answer = 0;
    std::cout << "Login System engaged\n";
    std::cout << "Enter 1 to login enter  Or Enter 2 to register" <<std::endl;
    std::cin >>answer;
    switch(answer)
    {
        case 1://Login of current user
            std::cout << " you entered " << answer <<" To login what is your credentials? "<<std::endl;
            std::cout <<"Enter username: ";
            std::cin >> un;
            std::cout << "Enter Password: ";
            std::cin >> pw;
            std::cout << "\n username is : " <<un << " password is : " << pw <<std::endl;
            break;
        case 2://registration of new user
            std::cout << " Input: " << answer << " Welcome new user" <<std::endl;
            std::cout <<"Enter username: ";
            std::cin >>un;
            std::cout << "Enter Password: ";
            std::cin>>pw;
            std::cout << "username is : " <<un << " password is : " << pw <<std::endl;
            m_username = un;
            m_password = pw;
            saveInfo();
            break;
        default:
            std::cout << " you entered an invalid "<<std::endl;
            break;
    }
}
void Login::saveInfo()
{
    std::ofstream userInfoFile;
    userInfoFile.open("userInfoFile.txt", std::ios::app);
    std::string userInfo = m_username + ":" + m_password;
    std::cout << "\n what is going into the file :" << userInfo << std::endl;
    userInfoFile << userInfo;
    userInfoFile.close();
    std::ifstream readUserInfo;
    readUserInfo.open("userInfoFile.txt", std::ios::in);
    std::string dataFromFile;
    readUserInfo >> dataFromFile;
    std::cout << "What comes out of the file: "<< dataFromFile <<std::endl;
    readUserInfo.close();
}
    
void Login::getInfo()
{
    //steps
    //step1 open file
    std::fstream inputfile;
    inputfile.open("userInfoFile.txt", std::ios::in);
    std::string fileData;
    while(!inputfile.eof())
    {
        
        std::getline("userInfoFile.txt", fileData,':');
        std::cout << fileData<<std::endl;
    }
    //inputfile.get
    //step 2 check if you can read file
    //step 3 separate the un from pw by the :
    //step 4 check if the separation worked
    //step 5 store them in a some kind of map un is key pw is value
}
