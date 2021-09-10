#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Collection.h"


class CollectionTest : public ::testing::Test {

protected:
    virtual void SetUp() {
        c.setName("Random");
    }

    Collection c;
};


TEST_F(CollectionTest, Constructor) {

    Collection c;
    ASSERT_EQ("Random", c.getName());
}

