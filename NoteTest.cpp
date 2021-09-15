#include "gtest/gtest.h"
#include "../Note.h"

class NoteTest : public ::testing::Test {

protected:
    virtual void SetUp() {
        note.SetText("Hello World");
        note.SetTitle("Test");
        note.SetEditable(0);
    }

    Note note;
};

TEST_F(NoteTest, Getters) {

Note note;
ASSERT_EQ("Hello World", note.GetText());
ASSERT_EQ("Test", note.GetText());
ASSERT_EQ(0, note.GetEditable());
}

