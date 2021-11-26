#ifndef REALISATION_H
#define REALISATION_H

#define HEAD_USER_DB "E:\\Programing\\LogAndRegDB\\users.txt"
#define LIST_OF_USERS "E:\\Programing\\LogAndRegDB\\db_users\\"

class Realisation {
public:
    Realisation() = default;
    static User Login()
    {
        std::string name,password;
        std::cout << "Enter your name:";
        std::cin >> name;
        std::cout << "Enter your password:";
        std::cin >> password;

        std::ifstream infile(HEAD_USER_DB);
        std::string line,current_word;
        while (std::getline(infile, line))
        {
            std::istringstream iss(line);
            std::vector<std::string> result;
            for(std::string s;iss>>s;)
            {
                result.push_back(s);
            }

            if(result[0]==name & result[1]==password) return {result[0], result[1], std::stoi(result[2]),result[3]};
        }
        std::cout << "user don't found";
        return {};
    }
    User Register()
    {
        m_data_base.open(HEAD_USER_DB, std::ios::app);
        std::string name,password,interest;
        int age;
        std::cout << "enter your name:";
        std::cin >> name;
        std::cout << "enter your password:";
        std::cin >> password;
        std::cout << "enter your age:";
        std::cin >> age;
        std::cout << "enter your interest:";
        std::cin >> interest;
        User temp(name,password, age,interest);
        m_data_base << temp << "\n";
        m_data_base.close();

        m_data_base.open(LIST_OF_USERS + name + ".txt", std::ios::app);
        m_data_base.close();
        return temp;
    }


private:
    std::ofstream m_data_base;
};


#endif
