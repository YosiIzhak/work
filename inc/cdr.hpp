

#ifndef CDR_HPP

#define CDR_HPP


#include <string>

#include <map>

#include "fields.hpp"

#include "data_type.hpp"


namespace cdr

{


class Cdr: public dt::DataType

{


public:

    Cdr(std::string a_newCdrString, dt::Fields const& a_fieldsNames, std::string const& a_delimiter);

    std::string const& getDataByField(std::string a_fieldName) const;

    std::string const& operator[](std::string a_fieldName) const;


private:

    void insertByFild(std::string& a_newCdrString);  

  

private:

    mutable std::map<std::string, std::string> m_data;

    dt::Fields const& m_fields;

    std::string const& m_delimiter;

};


}//namespace cdr


#endif//CDR_HPP

