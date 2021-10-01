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

TEST_F(CollectionTest, MoveNoteWorkingCorrectly) {

    std::vector <Collection> collezioni;
    
    Collection c1;
    Collection c2;

    collezioni.push_back(c1);
    collezioni.push_back(c2);

    Note note1;
    note1.SetTitle("Test1");
   
    Note note2;
    note2.SetTitle("Test2");
   
    c1.Add(note1, 0);
    c1.Add(note2, 0);

    Note note3 = collezioni[0].Search("Test2");
    EXPECT_TRUE(collezioni[1].MoveTo(note3));

}

TEST_F(CollectionTest, MoveWorkingCorrectly) {

    Collection* pointer = new Collection("Pointer");

    std::vector <Collection> collezioni;

    Collection c1("Random1");
    Collection c2("Random2");

    collezioni.push_back(c1);
    collezioni.push_back(c2);

    std::vector <Note> notes;

    Note note1;
    note1.SetTitle("Test1");

    Note note2;
    note2.SetTitle("Test2");

    notes.push_back(note1);
    notes.push_back(note2);

    EXPECT_FALSE(pointer->Move("Test1", "Random1", 0, notes, collezioni));
    EXPECT_TRUE(pointer->Move("Test2", "Random2", 1, notes, collezioni));
    EXPECT_FALSE(pointer->Move("Test3", "Random3", 1, notes, collezioni));

}


