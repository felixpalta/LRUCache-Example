#include <gtest/gtest.h>
#include <lib.h>

TEST(Tests, ListTest) {
    ShiftableList<int> ls;
    for (auto i : {5, 4, 3, 2, 1}) {
        ls.push_front(i);
        ASSERT_EQ(ls.front(), i);
    }
    ASSERT_EQ(ls.back(), 5);
    ls.pop_back();
    ASSERT_EQ(ls.front(), 1);
    ASSERT_EQ(ls.back(), 4);
    ls.pop_back();
    ASSERT_EQ(ls.back(), 3);
    ls.push_front(0);
    ASSERT_EQ(ls.front(), 0);
    ASSERT_EQ(ls.back(), 3); // 0 1 2 3
    ASSERT_EQ(ls.size(), 4);
    auto it = ls.begin();
    for (auto i : {0, 1, 2 ,3}) {

        ASSERT_EQ(*it, i);
        std::advance(it, 1);
    }

    it = std::next(ls.begin());
    ls.move_to_head(it);
    ASSERT_EQ(it, ls.begin());
    it = ls.begin();

    for (auto i : {1, 0, 2 ,3}) {

        ASSERT_EQ(*it, i);
        std::advance(it, 1);
    }
}

TEST(DefaultTest, CacheTest) {
    LRUCache ch(2);
    ASSERT_EQ(ch.Size(), 0);
    ASSERT_EQ(ch.FindInCache("foo"), LRUCache::InvalidValue());

    ch.PutInCache("foo", 1);
    ASSERT_EQ(ch.FindInCache("foo"), 1);

    ch.PutInCache("bar", 2);
    ASSERT_EQ(ch.FindInCache("bar"), 2);
    ASSERT_EQ(ch.Size(), 2);

    ch.PutInCache("bar", 3);
    ASSERT_EQ(ch.FindInCache("bar"), 3);
    ASSERT_EQ(ch.Size(), 2);

    ch.PutInCache("foo", 0);
    ASSERT_EQ(ch.FindInCache("foo"), 0);
    ASSERT_EQ(ch.Size(), 2);

    ch.PutInCache("baz", 99);
    ASSERT_EQ(ch.FindInCache("baz"), 99);
    ASSERT_EQ(ch.FindInCache("bar"), LRUCache::InvalidValue());
    ASSERT_EQ(ch.FindInCache("foo"), 0);
    ASSERT_EQ(ch.Size(), 2);


}
