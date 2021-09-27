#include "pch.h"
#include "Collection.h"
#include "gtest/gtest.h"

#include <string>

TEST(Collection, ConstructorWorks) {
    Collection c("Random");
    ASSERT_EQ(c.GetName(), "Random");
}


class CollectionTest : public ::testing::Test {

public:
    virtual void SetUp() {
        C = Collection();
    } 

    Collection C;
};

TEST_F(CollectionTest, FunctionsWorkingCorrectly) {

    Note note1;
    note1.SetTitle("Test1");
    note1.SetText("Cat");

    Note note2;
    note2.SetTitle("Test2");
    note2.SetText("Dog");

    EXPECT_TRUE(C.Add(note1, 1));
    EXPECT_FALSE(C.Add(note2, 0));

    EXPECT_FALSE(C.EditNote("Test1", "Rabbit"));
    EXPECT_TRUE(C.EditNote("Test2", "Rabbit"));

    EXPECT_TRUE(C.RemoveNote("Test1"));
    EXPECT_FALSE(C.RemoveNote("Horse"));
    EXPECT_TRUE(C.RemoveNote("Test2"));

}

