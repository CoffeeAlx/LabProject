#include "gtest/gtest.h"
#include "../Collection.h"

class CollectionTest : public ::testing::Test {

protected:
    virtual void SetUp() {
        c.SetName("Random");
    }

    Collection c;
}


TEST_F(CollectionTest, Getter) {

    Collection c;
    ASSERT_EQ("Random", c.GetName())
}

