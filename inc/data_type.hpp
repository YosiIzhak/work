

#ifndef DATA_TYPE_HPP

#define DATA_TYPE_HPP


#include <string>

#include <cstdlib>

#include "fields.hpp"


namespace dt

{


class DataType

{


public:

    DataType(){};

    virtual std::string const& getDataByField(std::string a_fieldName) const = 0;

    virtual std::string const& operator[](std::string a_fieldName) const = 0;


private:

    DataType& operator=(DataType const& a_dataType);

    DataType(DataType const& a_dataType);

    

};


}//namespace dt


#endif//DATA_TYPE_HPP

