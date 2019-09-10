#ifndef LIB_H
#define LIB_H

#include <list>
#include <unordered_map>

template <typename T>
class ShiftableList
{
public:
    ShiftableList() = default;
    using value_type = T;
    using ListImpl = std::list<T>;
    using ListIter = typename ListImpl::iterator;

    ListIter begin() { return ls.begin();}
    ListIter end() { return ls.end();}

    typename ListImpl::size_type size() const { return ls.size();}

    value_type front() const
    {
        return *ls.begin();
    }

    bool empty()
    {
        return ls.empty();
    }

    void push_front(value_type val)
    {
        ls.push_front(val);
    }

    void pop_back()
    {
        ls.pop_back();
    }

    value_type back() const
    {
        return ls.back();
    }

    void move_to_head(ListIter it)
    {
        if (it != ls.begin() && it != ls.end()) {
            ls.splice(ls.begin(), ls, it, std::next(it));
        }
    }
private:
    ListImpl ls;
};

class LRUCache
{
public:
    using KeyType = std::string;
    using ValueType = int;
    static constexpr ValueType InvalidValue() { return -1; }

    explicit LRUCache(int n) : mMaxSize(n) {}
    ValueType FindInCache(KeyType key);
    void PutInCache(KeyType key, ValueType val);
    size_t Size() { return mQ.size();}
private:
    struct QNode
    {
        ValueType val;
        KeyType key;
        QNode(ValueType v, KeyType k) : val(v), key(k) {}
    };

    const size_t mMaxSize;
    ShiftableList<QNode> mQ;
    std::unordered_map<KeyType, decltype(mQ.begin())> mHashMap;
};


#endif // LIB_H
