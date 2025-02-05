#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <stdexcept>
#include <move.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class MovingObjectMock: public IMovingObject
{
    public:
    
    MOCK_METHOD(vector, get_location, ());
    MOCK_METHOD(void, set_location, (vector));
    MOCK_METHOD(vector, get_velocity, ());
};

TEST(move, simple_move)
{
    std::shared_ptr <MovingObjectMock> moveobj = std::make_shared<MovingObjectMock>();
    Move movecmd(moveobj);

    EXPECT_CALL( *moveobj, get_location()).WillOnce(Return(vector(12, 5)));
    EXPECT_CALL( *moveobj, get_velocity()).WillOnce(Return(vector(-7, 3)));
    EXPECT_CALL( *moveobj, set_location(vector(5, 8)));

    movecmd.Execute();
}

TEST(move, move2_getlockation_error)
{
    std::shared_ptr <MovingObjectMock> moveobj = std::make_shared<MovingObjectMock>();
    Move movecmd(moveobj);

    ON_CALL( *moveobj, get_location()).WillByDefault(Throw("get_lockation failed"));
 
    EXPECT_ANY_THROW( movecmd.Execute() );
}

TEST(move, move3_getvelocity_error)
{
    std::shared_ptr <MovingObjectMock> moveobj = std::make_shared<MovingObjectMock>();
    Move movecmd(moveobj);
    
    ON_CALL( *moveobj, get_location()).WillByDefault(Return(vector(0,0)));
    ON_CALL( *moveobj, get_velocity()).WillByDefault(Throw("get_velocityfailed"));
 
    EXPECT_ANY_THROW( movecmd.Execute() );
}

TEST(move, move4_setloc_error)
{
    std::shared_ptr <MovingObjectMock> moveobj = std::make_shared<MovingObjectMock>();
    Move movecmd(moveobj);

    EXPECT_CALL( *moveobj, get_location()).WillOnce(Return(vector(12, 5)));
    EXPECT_CALL( *moveobj, get_velocity()).WillOnce(Return(vector(-7, 3)));
    ON_CALL( *moveobj, set_location ).WillByDefault(Throw("set_locationerror"));

    EXPECT_ANY_THROW( movecmd.Execute() );
}
