#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <stdexcept>
#include <rotate.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class RotatingObjectMock: public IRotatingObject
{
    public:
    
    MOCK_METHOD(direction, get_direction, ());
    MOCK_METHOD(void, set_direction, (direction));
    MOCK_METHOD(direction, get_rotation_speed, ());
};

TEST(rotate, simple_turn)
{
    std::shared_ptr <RotatingObjectMock> rotateobj = std::make_shared<RotatingObjectMock>();
    Rotate rotatecmd(rotateobj);

    EXPECT_CALL( *rotateobj, get_direction()).WillOnce(Return(direction(10)));
    EXPECT_CALL( *rotateobj, get_rotation_speed()).WillOnce(Return(direction(100)));
    EXPECT_CALL( *rotateobj, set_direction(direction(110)));

    rotatecmd.Execute();
}
