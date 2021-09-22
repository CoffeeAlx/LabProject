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
        Collection C("UnitTesting");
    } 

    Collection C;
};

TEST_F(CollectionTest, AddNoteWorks) {

    Note note1("Cat", "Meow");
    std::cout << "ENTER 1 TO GET A SUCCESSFUL TEST" << std::endl;
    EXPECT_TRUE(C.Add(note1));

    Note note2("Dog", "Woof");
    std::cout << "ENTER 0 TO GET A SUCCESSFUL TEST" << std::endl;
    EXPECT_FALSE(C.Add(note2));

    C.EditNote("Cat");

    std::string temp = C.EditNote("Dog");
    EXPECT_NE(temp, "Woof");
}

