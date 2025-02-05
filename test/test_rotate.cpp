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

TEST(rotate, getdirection_error)
{
    std::shared_ptr <RotatingObjectMock> rotateobj = std::make_shared<RotatingObjectMock>();
    Rotate rotatecmd(rotateobj);

    ON_CALL( *rotateobj, get_direction()).WillByDefault(Throw("get_direction failed"));
 
    EXPECT_ANY_THROW( rotatecmd.Execute() );
}

TEST(rotate, getrotation_speed_error)
{
    std::shared_ptr <RotatingObjectMock> rotateobj = std::make_shared<RotatingObjectMock>();
    Rotate rotatecmd(rotateobj);

    ON_CALL( *rotateobj, get_rotation_speed()).WillByDefault(Throw("get_rotation_speed failed"));
 
    EXPECT_ANY_THROW( rotatecmd.Execute() );
}

TEST(rotate, set_direction_error)
{
    std::shared_ptr <RotatingObjectMock> rotateobj = std::make_shared<RotatingObjectMock>();
    Rotate rotatecmd(rotateobj);

    ON_CALL( *rotateobj, set_direction(_)).WillByDefault(Throw("set_direction failed"));
 
    EXPECT_ANY_THROW( rotatecmd.Execute() );
}