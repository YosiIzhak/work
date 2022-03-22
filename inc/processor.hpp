

#ifndef PROCESSOR_HPP

#define PROCESSOR_HPP


#include <map>

#include "data_type.hpp"

#include "mutex.hpp"

#include "agg_data.hpp"

#include "agg_data_group.hpp"


namespace processor

{


template<typename K, typename F>

//K= key, 

//F- aggregate function- require: void operator()(T& a_newData, AggregatData& a_aggData) 

class Processor

{

public:

    Processor(size_t a_size);

    void upsert(K const& a_key, dt::DataType const* a_newData, dt::Fields const& a_aggFieldsNames, F a_AggregatFunc = dt::Aggregate());

    std::pair<bool, dt::AggData<F> const* > get(K const& a_key) const;

    std::string const& getByFiled(K const& a_key,std::string a_fildName) const;

private:

    size_t hashFunc(K const& a_key) const;


private:

    std::map<size_t, dt::AggDataGroup<K,F>* > m_data;

    size_t m_size;

};


}//namespace processor


#include "./inl/processor.hxx"


#endif//PROCESSOR_HPP

