

#ifndef FIELDS_HPP

#define FIELDS_HPP


#include <string>

#include <cstdlib>

#include <vector>

#include <map>


namespace dt

{


class Fields

{

public:

   Fields(std::string a_fields, std::string a_delimiter, size_t a_numOfFields = 16);

   std::string const& operator[](size_t a_index) const;

   //FOR CHANGING THE FIELDS

   std::vector<std::string>& getFields();

   size_t numOfFields() const;


private:

    void fillVec(std::string& a_fieldsString);


private:

    std::vector<std::string> m_fieldsVec;

    std::string m_delimiter;

};


}//namespace dt


#endif//FIELDS_HPP

