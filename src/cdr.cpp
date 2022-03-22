#include "cdr.hpp"

#include <cstdlib>


namespace cdr

{


Cdr::Cdr(std::string a_newCdrString, dt::Fields const& a_fieldsNames, std::string const& a_delimiter)

: m_data()

, m_fields(a_fieldsNames)

, m_delimiter(a_delimiter)

{

    insertByFild(a_newCdrString += m_delimiter);

    //convertFileds();

}


std::string const& Cdr::getDataByField(std::string a_fieldName) const

{

    //TODO: add exception if invalid a_fieldName

    return m_data[a_fieldName];

}


std::string const& Cdr::operator[](std::string a_fieldName) const

{

    //TODO: add exception if invalid a_fieldName

    return m_data[a_fieldName];

}

//TODO- CHECK IF CTOR NEED MUTEX?
void Cdr::insertByFild(std::string& a_newCdrString)

{

    size_t pos = 0;

    size_t i = 0;

    std::string fieldData;

    while ((pos = a_newCdrString.find(m_delimiter)) != std::string::npos)

    {

        fieldData = a_newCdrString.substr(0, pos);

        m_data.insert(std::pair<std::string, std::string>(m_fields[i], fieldData));

        a_newCdrString.erase(0, pos + m_delimiter.length());

        ++i;

    }

}


}//namespace cdr