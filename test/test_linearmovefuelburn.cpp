//тест движения по прямой со сжиганием топлива

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <mock_icommand.h>
#include <mock_icommandqueue.h>
#include <mock_icommand.h>
#include <iexception.h>

#include <macrocommand.h>
#include <burnfuelcommand.h>
#include <checkfuelcommand.h>
#include <commandexception.h>
#include <move.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class FuelObjectMockForTestBurn: public IFuelObject
{
    public:
    
    MOCK_METHOD(fuel, getFuel, ());
    MOCK_METHOD(void, setFuel, (fuel));
    MOCK_METHOD(fuel, getFuelConsumption, ());
};

class MovingObjectMockForTestBurn: public IMovingObject
{
    public:
    
    MOCK_METHOD(vector, get_location, ());
    MOCK_METHOD(void, set_location, (vector));
    MOCK_METHOD(vector, get_velocity, ());
};

TEST(movefuel, normal)
{
    std::shared_ptr <FuelObjectMockForTestBurn> obj = std::make_shared<FuelObjectMockForTestBurn>();
    std::shared_ptr<CMockCommandQueue> testqueue = std::make_shared<CMockCommandQueue>();
    std::shared_ptr<CheckFuelCommand> pcheckfuel = std::make_shared<CheckFuelCommand>(obj);
    std::shared_ptr<BurnFuelCommand> pburnfuel = std::make_shared<BurnFuelCommand>(obj);
        std::shared_ptr <MovingObjectMockForTestBurn> moveobj = std::make_shared<MovingObjectMockForTestBurn>();
    std::shared_ptr<Move> pmovecmd = std::make_shared<Move>(moveobj);

    MacroCommand macro(testqueue);
    
    EXPECT_CALL( *testqueue, GetCommand() )
        .WillOnce(Return( pcheckfuel))
        .WillOnce(Return( pmovecmd))
        .WillOnce(Return( pburnfuel))
        .WillOnce(Return( nullptr));

    EXPECT_CALL( *obj, getFuel()).WillRepeatedly(Return(fuel(12)));
    EXPECT_CALL( *obj, getFuelConsumption()).WillRepeatedly(Return(fuel(3)));
    EXPECT_CALL( *obj, setFuel(fuel(9)));

    EXPECT_CALL( *moveobj, get_location()).WillOnce(Return(vector(12, 5)));
    EXPECT_CALL( *moveobj, get_velocity()).WillOnce(Return(vector(-7, 3)));
    EXPECT_CALL( *moveobj, set_location(vector(5, 8)));
 

    macro.Execute();
}

