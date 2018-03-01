#pragma once

#include <variant>
#include "../utility.h"


/// special container for mapping from integers to Values
///
/// odd integers may be sparse in the indexing space but even one should be regrouped
/// In this structure. There is no difference between default constructor Value() and
/// nothing. Use std::option or pointers if such behavior is not acceptable.
template<typename Value>
class volmap {
    std::vector<Value> even; // owner
    std::unordered_map<u64, Value> odd; // owner
public:
    class iterator{
        typename std::vector<Value>::iterator vposbeg;
        typename std::vector<Value>::iterator vpos;
        typename std::vector<Value>::iterator vposend;
        typename std::unordered_map<u64, Value>::iterator mpos;
        friend volmap<Value>;
    public:
        using value_type = std::pair<const u64,Value&>;
        value_type operator*(){
            if(vpos == vposend) return value_type(mpos->first, mpos->second);
            else return value_type(2*(vpos - vposbeg),*vpos);
        }
        iterator& operator++(){
            if(vpos == vposend) ++mpos;
            else ++vpos;
            return *this;
        }
        bool operator ==(const iterator& oth) const{
            return vpos == oth.vpos and mpos == oth.mpos;
        }

        bool operator !=(const iterator& oth) const{
            return vpos != oth.vpos and mpos != oth.mpos;
        }
    };
    iterator begin(){
        iterator it;
        it.vposbeg = it.vpos = even.begin();
        it.vposend = even.end();
        it.mpos = odd.begin();
        return it;
    }
    iterator end(){
        iterator it;
        it.vposbeg = even.begin();
        it.vposend = it.vpos = even.end();
        it.mpos = odd.end();
        return it;
        }

  class const_iterator{
        typename std::vector<Value>::const_iterator vposbeg;
        typename std::vector<Value>::const_iterator vpos;
        typename std::vector<Value>::const_iterator vposend;
        typename std::unordered_map<u64, Value>::const_iterator mpos;
        friend volmap<Value>;
    public:
        using value_type = std::pair<const u64,const Value&>;
        value_type operator*(){
            if(vpos == vposend) return value_type(mpos->first, mpos->second);
            else return value_type(2*(vpos - vposbeg),*vpos);
        }
        const_iterator& operator++(){
            if(vpos == vposend) ++mpos;
            else ++vpos;
            return *this;
        }
        bool operator ==(const const_iterator& oth) const{
            return vpos == oth.vpos and mpos == oth.mpos;
        }

        bool operator !=(const const_iterator& oth) const{
            return vpos != oth.vpos and mpos != oth.mpos;
        }
    };
    const_iterator begin() const{
        const_iterator it;
        it.vposbeg = it.vpos = even.begin();
        it.vposend = even.end();
        it.mpos = odd.begin();
        return it;
    }
    const_iterator end() const{
        const_iterator it;
        it.vposbeg = even.begin();
        it.vposend = it.vpos = even.end();
        it.mpos = odd.end();
        return it;
        }


    using value_type = std::pair<const u64,Value>;
    void clear(){
        even.clear();
        odd.clear();
    }
    /// Insert element at index. UB if count(id) == 1
    void insert(u64 id, const Value& v ){
        if(id % 2) odd.insert(value_type(id,v));
        else {
            while (even.size() <= id/2) even.push_back(Value());
            assert(even[id/2] == Value());
            even[id/2] = v;
        }
    }

    /// Insert element at index. UB if count(id) == 1
    void insert(u64 id, Value&& v ){
        if(id % 2) odd.insert(value_type(id,std::move(v)));
        else {
            while (even.size() <= id/2) even.push_back(Value());
            even[id/2] = std::move(v);
        }
    }
    /// Get a value you know is there. UB if count(id) = 0
    Value& at(u64 id){
        if(id %2) return odd.at(id);
        else{
#ifdef NDEBUG
            return even[id/2];
#else
            auto& a = even.at(id/2);
            if (a == Value()) throw std::out_of_range("volmap at accessed Value() value");
            return a;
#endif
        }
    }

    /// Get a value you know is there. UB if count(id) = 0
    const Value& at(u64 id) const{
        if(id %2) return odd.at(id);
        else{
#ifdef NDEBUG
            return even[id/2];
#else
            auto& a = even.at(id/2);
            if (a == Value()) throw std::out_of_range("volmap at accessed Value() value");
            return a;
#endif
        }
    }

    /// Returns reference to id's position. Creates a new if needed.
    Value& operator[](u64 id){
        if(id %2) return odd[id];
        else{
            while (even.size() <= id/2) even.push_back(Value());
            return even[id/2];
        }
    }

    /// Remove object at id. UB id count(id) = 0
    void erase(u64 id){
        if(id % 2) odd.erase(id);
        else{
            assert(even.size() > id/2);
            even[id/2] = Value();
        }
    }

    /// Returns 1 id there is something at id and 0 if not.
    size_t count(u64 id){
        if(id % 2) return odd.count(id);
        else{
            if(id >= even.size()) return 0;
            else return even[id] == Value();
        }
    }

};
