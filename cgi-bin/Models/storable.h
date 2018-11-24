#ifndef STORABLE_H
#define STORABLE_H

#include <string>

class Storable {
    public:
        Storable(const std::string& name, const std::string &address) : _name(name), _address(address) {};

        virtual ~Storable() {};
        
        virtual std::string to_string() {
            std::string res = "File: " + this->_name + " Address: " + this->_address;
            return res;
        };
        
        virtual void append(Storable* newStorable) {};

        virtual const std::string& getName() const {
            return this->_name;
        };

        virtual const std::string& getAddress() const {
            return this->_address;
        };

    private:
        std::string _name;
        std::string _address;
};  

#endif
