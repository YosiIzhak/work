

#ifndef PROCESSOR_HXX

#define PROCESSOR_HXX


namespace processor

{


template <typename K, typename F>

Processor<K,F>::Processor(size_t a_size)

: m_data()

, m_size(a_size)

{}


template <typename K, typename F>

void Processor<K,F>::upsert(K const& a_key, dt::DataType const* a_newData, dt::Fields const& a_aggFieldsNames, F a_AggregatFunc)

{

    size_t groupKey = hashFunc(a_key) % m_size;


    auto it = m_data.find(groupKey);


    if(it == m_data.end())

    {

        dt::AggDataGroup<K,F>* group = new dt::AggDataGroup<K,F>(a_aggFieldsNames);

        m_data[groupKey] = group;

        group->upsert(a_key,a_newData, a_AggregatFunc);

    }

    else

    {

        auto group =  m_data[groupKey]; 

        group->upsert(a_key,a_newData, a_AggregatFunc);  

    }   

}


template <typename K, typename F>

std::pair<bool, dt::AggData<F> const* > Processor<K,F>::get(K const& a_key) const

{

    size_t groupKey = hashFunc(a_key) % m_size;


    auto it = m_data.find(groupKey);


    return (it->second)->get(a_key);   

}



template <typename K, typename F>

std::string const& Processor<K,F>::getByFiled(K const& a_key,std::string a_fildName) const

{

    auto aggData = get(a_key);


    if(aggData.first)

    {

        return (*(aggData.second))[a_fildName];

    }

    else

    {

        return std::string("");

    }

}


//private:

template <typename K, typename F>

size_t Processor<K,F>::hashFunc(K const& a_key) const

{

    return std::hash<std::string>{}(a_key);

}


}//namespace processor



#endif//PROCESSOR_HXX

