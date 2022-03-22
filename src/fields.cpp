

#include "fields.hpp"


namespace dt

{


Fields::Fields(std::string a_fieldsString, std::string a_delimiter, size_t a_numOfFields)

: m_fieldsVec()

, m_delimiter(a_delimiter)

{

    m_fieldsVec.reserve(a_numOfFields);

    fillVec(a_fieldsString += m_delimiter);

}


std::string const& Fields::operator[](size_t a_index) const

{

    //TODO- EXCEPTION FOR INVALID INDEX

    return m_fieldsVec[a_index];

}


std::vector<std::string>& Fields::getFields()

{

    return m_fieldsVec;

}


size_t Fields::numOfFields() const

{

    return m_fieldsVec.size();

}


//private:

void Fields::fillVec(std::string& a_fieldsString)

{        

    size_t pos = 0;

    std::string fieldName;

    while ((pos = a_fieldsString.find(m_delimiter)) != std::string::npos)

    {

        fieldName = a_fieldsString.substr(0, pos);

        m_fieldsVec.push_back(fieldName);

        a_fieldsString.erase(0, pos + m_delimiter.length());

    }

}


}//namespace dt

