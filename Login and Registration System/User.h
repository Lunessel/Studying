#ifndef USER_H
#define USER_H

class User
{
public:
    User(std::string name="", std::string password="skleroz", int age=0, std::string interest=""):
            m_name(name), m_password(password),m_age(age), m_interest(interest)
    {
    }
    friend std::ostream& operator<< (std::ostream &out,const User &user)
    {
        if(user.m_name!="")
            out << user.m_name << " " << user.m_password << " " << user.m_age << " " << user.m_interest;
        else out << "";
        return out;
    }
    friend std::ostream& operator<< (std::ostream &out,const std::string str)
    {
        out << str;
        return out;
    }
    friend std::istream& operator>> (std::istream &in,User &user)
    {
        in >> user.m_name;
        in >> (User &) " ";
        in >> user.m_age;
        in >> (User &) " ";
        in >> user.m_interest;
        return in;
    }
    const void Print()
    {
        std::cout << m_name << " " << m_age << " " << m_interest << "\n";
    }
private:
    std::string m_name;
    int m_age;
    std::string m_interest;
    std::string m_password;
};

#endif
