#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Note.h"

class NoteTest : public ::testing::Test {

protected:
    virtual void SetUp() {
        note.setText("Hello World");
        note.setTitle("Test");
        note.setEditable(0);
    }

    Note note;
};

TEST_F(NoteTest, Getters) {

    Note note;
    ASSERT_EQ("Hello World", note.getText());
    ASSERT_EQ("Test", note.getText());
    ASSERT_EQ(0, note.getEditable());
}

