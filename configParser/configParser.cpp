#include "configParser.hpp"


#ifdef DEBUG_MODE
    #include <iostream>
#endif // DEBUG_MODE

namespace configParser {
    void Parser::erase(std::string key) {
        if (data.count(key) == 0) return;
        data.erase(key);
    }

    void Parser::clear() {
        data.clear();
    }

    bool Parser::parseFromFile(const std::string &file_name) {
        std::ifstream file(file_name.c_str());
        if (!file.is_open()) return false;
        while(!file.eof()) {
            std::string temp;
            std::getline(file,temp);

            parse(temp);
        }
        file.close();
        return true;
    }

    void Parser::parseFromString(const std::string &data) {
        std::stringstream stream(data);
        while(!stream.eof()) {
            std::string temp;
            std::getline(stream,temp);

            parse(temp);
        }
    }

    bool Parser::writeToFile(const std::string &file_name) {
        std::ofstream file(file_name.c_str());

        if (!file.is_open()) return false;
        file.clear();

        for (auto &x : data) {
            file << x.first << " = " << x.second << std::endl << std::endl;
        }

        file.close();

        return true;
    }

    void Parser::writeToString(std::string &data) {
        std::stringstream stream;
        for (auto &x : this->data) {
            stream << x.first << " = " + x.second << std::endl << std::endl;
        }

        data = stream.str();
    }

    void Parser::parse(std::string line) {
        // Gregorio's magics. Não leia em caso de dengue.
        if (line.find_first_not_of(" \t\n") == line.npos) return;
        std::string key,value;
        key = line.substr(line.find_first_not_of(" \t"),line.npos);
        if (key.at(0) == '#') return;
        key = key.substr(0,key.find_first_of(" =\t"));
        line.erase(0,line.find_first_of('=') + 1);
        value = line.substr(line.find_first_not_of(' '),line.npos);
        value = value.substr(0,value.find_last_not_of(" \t;") + 1);

        data[key] = value;

        #ifdef DEBUG_MODE
            std::cout << key << " => " << value << "!\n";
        #endif
    }





    void Parser::read(std::string key, bool                 &value) {
        if (data.count(key) == 0) return;
        value = (data[key] == "yes")?(true):(false);
    }

    void Parser::read(std::string key, unsigned int         &value) {
        if (data.count(key) == 0) return;
        value = std::stoul(data[key]);
    }

    void Parser::read(std::string key, int                  &value) {
        if (data.count(key) == 0) return;
        value = std::stoi(data[key]);
    }

    void Parser::read(std::string key, long unsigned int    &value) {
        if (data.count(key) == 0) return;
        value = std::stoull(data[key]);
    }
    void Parser::read(std::string key, long int             &value) {
        if (data.count(key) == 0) return;
        value = std::stol(data[key]);
    }
    void Parser::read(std::string key, float                &value) {
        if (data.count(key) == 0) return;
        value = std::stof(data[key]);
    }
    void Parser::read(std::string key, double               &value) {
        if (data.count(key) == 0) return;
        value = std::stod(data[key]);
    }
    void Parser::read(std::string key, std::string          &value) {
        if (data.count(key) == 0) return;
        value = data[key];
    }




    void Parser::write(std::string key,const  std::string   &value) {
        data[key] = value;
    }

    void Parser::write(std::string key,bool value) {
        data[key] = (value)?("yes"):("no");
    }

    template void Parser::write(std::string key,unsigned int     );
    template void Parser::write(std::string key,int              );
    template void Parser::write(std::string key,unsigned long int);
    template void Parser::write(std::string key,long int         );
    template void Parser::write(std::string key,float            );
    template void Parser::write(std::string key,double           );

    template<class T>
        void Parser::write(std::string key,T value) {
            data[key] = std::to_string(value);
        }

};
