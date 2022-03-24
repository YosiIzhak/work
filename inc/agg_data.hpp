

#ifndef AGG_DATA_HPP

#define AGG_DATA_HPP


#include <string>

#include <map>

#include <cstdlib>

#include "cdr.hpp"

#include "fields.hpp"

#include "data_type.hpp"


namespace dt

{


typedef std::map<std::string, std::string> AggregatData; 


struct Aggregate

{

   void operator()(DataType* a_newData, AggregatData& a_aggData);  

};


template<typename F>

//require:

//F: void operator()(DataType& a_newData, AggregatData& a_aggData)  

class AggData

{

public:

    AggData(DataType const* a_newData, Fields const& a_aggFieldsNames, F a_AggregatFunc = Aggregate());

    std::string const& operator[](std::string a_fieldName) const;

    std::string getDataByField(std::string const& a_fieldName);

    void addData(DataType const* a_newData);


private:    

    void initialAggData(size_t a_numOfFields);


private:

    mutable AggregatData m_aggData;

    Fields const& m_fields;

    F m_AggregatFunc;

    std::string m_notFound;

};


}//namespace dt


#include "agg_data.hxx"


#endif//AGG_DATA_HPP

