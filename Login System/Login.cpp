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
            std::cout << "\n username is : " <<un << " ----      password is : " << pw <<std::endl;
            m_username = un;
            m_password = pw;
            getInfo();
            std::cout<< "m_correctUserName " << m_correctUserName << "\nm_CorrectPassword " <<m_correctPassWord <<std::endl;
            if(m_correctUserName == true && m_correctPassWord == true)
            {
                m_LoggedIn = true;
                std::cout << "you are Logged in\n";
            }
            else
            {
                std::cout << "You are still not logged in\n";
            }
            break;
        case 2://registration of new user
            std::cout << " Input: " << answer << " Welcome new user" <<std::endl;
            std::cout <<"Enter username: ";
            std::cin >>un;
            std::cout << "Enter Password: ";
            std::cin>>pw;
            std::cout << "username is : \n" <<un << " password is : " << pw <<std::endl;
            m_username = un;
            m_password = pw;
            saveInfo();
            break;
        default:
            std::cout << " you entered an invalid "<<std::endl;
            break;
    }
}
void Login::saveInfo(){
    std::ofstream userInfoFile;
    userInfoFile.open(m_file, std::ios::app);
    std::string userInfo = m_username + ":" + m_password;
    std::cout << "\n what is going into the file :" << userInfo << std::endl;
    userInfoFile << userInfo;
    userInfoFile << "\n";
    userInfoFile.close();
    std::ifstream readUserInfo;
    readUserInfo.open(m_file, std::ios::in);
    std::string dataFromFile;
    while( !readUserInfo.eof() )
    {
        readUserInfo >> dataFromFile;
       // std::cout << "What comes out of the file: "<< dataFromFile <<std::endl;
    }
    readUserInfo.close();
    std::cout << "verifying your login info\n";
    verifyNewUser(userInfo);
}
    
void Login::getInfo(){
    std::cout <<"looking for your info"<<std::endl;
    std::ifstream fileReader;
    std::string fileData;
    fileReader.open(m_file, std::ios::in);
    if ( fileReader.is_open() )
    {
        if(!fileReader.eof())
        {
            while(!fileReader.eof())
            {
                fileReader >> fileData;
                verifyNewUser(fileData);
            }
        }
        else
        {
            std::cout << "File is empty\n";
        }
    }
    else
    {
        std::cout << "The file is not open maybe does not exist\n";
        std::ofstream fileCreater;
        fileCreater.open(m_file);
        fileCreater.close();
        getInfo();
    }
}
void Login::verifyNewUser(std::string uInfo)
{
    std::string lsUserName;
    std::string lsPassWord;
    std::string::size_type delim = uInfo.find(":");
    std::ifstream fileReader;
    fileReader.open(m_file);
    //std::cout << uInfo.find(":") << "\n";
    lsUserName = uInfo.substr( 0, delim );
    lsPassWord = uInfo.substr( ++delim );
    std::cout << lsPassWord<<std::endl;
    if(lsUserName == m_username)
    {
        //std::cout << "you gave us " << m_username << " and we found " << lsUserName << " that matched\n\n";
        m_correctUserName = true;
    }
    if(lsPassWord == m_password)
    {
        //std::cout << "you gave us " << m_password << " and we found " << lsPassWord << " that matched\n\n";
        m_correctPassWord = true;
    }
    if(m_correctUserName == true && m_correctPassWord == true)
    {
        m_LoggedIn = true;
        std::cout<< m_username<<" you are logged in"<<std::endl;
        
    }
    fileReader.close();
}
