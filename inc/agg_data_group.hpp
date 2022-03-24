

#ifndef AGG_DATA_GROUP_HPP

#define AGG_DATA_GROUP_HPP


#include "data_type.hpp"

#include "mutex.hpp"

#include "fields.hpp"

#include "agg_data.hpp"


namespace dt

{


template<typename K, typename F>

//K= key type, 

//F- aggregate function- require: void operator()(dt::DataType& a_newData, AggregatData& a_aggData) 

class AggDataGroup

{

public:

    AggDataGroup(Fields const& a_aggFieldsNames);

    void upsert(K const& a_key, dt::DataType const* a_newData, F a_AggregatFunc = Aggregate());

    std::pair<bool, dt::AggData<F> const*> get(K const& a_key) const;


private:

    std::map<K, dt::AggData<F>* > m_data;

    mutable mt::Mutex m_mutex; 

    Fields const& m_fields;

};


}//namespace dt


#include "agg_data_group.hxx"


#endif//AGG_DATA_GROUP_HPP

