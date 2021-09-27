#include "pch.h"
#include "Note.h"
#include "gtest/gtest.h"

TEST(Note, ConstructorWorks) {
    Note note;
    ASSERT_EQ(note.GetEditable(), false);
}


class NoteTest : public ::testing::Test {

public:
    virtual void SetUp() {
        newnote = Note();
    }

    Note newnote;

};

TEST_F(NoteTest, GettersAndSetters){

    newnote.SetTitle("Hi");
    newnote.SetText("Unit Testing");

    ASSERT_EQ("Hi", newnote.GetTitle());
    ASSERT_EQ("Unit Testing", newnote.GetText());
    ASSERT_EQ(0, newnote.GetEditable());

    newnote.SetEditable(1);
    ASSERT_EQ(1, newnote.GetEditable());

  
}

