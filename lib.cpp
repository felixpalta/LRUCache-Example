#include "lib.h"



LRUCache::ValueType LRUCache::FindInCache(LRUCache::KeyType key)
{
    auto found = mHashMap.find(key);
    if (found == mHashMap.end()) {
        return InvalidValue();
    }

    auto qIter = found->second;
    mQ.move_to_head(qIter);

    return qIter->val;
}

void LRUCache::PutInCache(LRUCache::KeyType key, LRUCache::ValueType val)
{
    auto found = mHashMap.find(key);
    if (found != mHashMap.end()) {
        auto qIter = found->second;
        qIter->val = val;
        mQ.move_to_head(qIter);
        return;
    }
    if (mQ.size() == mMaxSize) {
        auto lastNode = mQ.back();
        mQ.pop_back();
        mHashMap.erase(lastNode.key);
    }
    mQ.push_front(QNode(val, key));
    mHashMap[key] = mQ.begin();
}
