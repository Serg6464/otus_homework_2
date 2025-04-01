#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include <stdexcept>
#include <checkfuelcommand.h>

using ::testing::Throw;
using ::testing::Return;
using ::testing::AnyNumber;
using ::testing::_;

class FuelObjectMock: public IFuelObject
{
    public:
    
    MOCK_METHOD(fuel, getFuel, ());
    MOCK_METHOD(void, setFuel, (fuel));
    MOCK_METHOD(fuel, getFuelConsumption, ());
};


TEST(checkfuelcommand, readytomove)
{
    std::shared_ptr <FuelObjectMock> obj = std::make_shared<FuelObjectMock>();
    CheckFuelCommand cmd(obj);

    EXPECT_CALL( *obj, getFuel()).WillOnce(Return(fuel(12)));
    EXPECT_CALL( *obj, getFuelConsumption()).WillOnce(Return(fuel(3)));

    EXPECT_NO_THROW(cmd.Execute());
}

TEST(checkfuelcommand, fuel_error)
{
    std::shared_ptr <FuelObjectMock> obj = std::make_shared<FuelObjectMock>();
    CheckFuelCommand cmd(obj);

    EXPECT_CALL( *obj, getFuel()).WillOnce(Return(fuel(12)));
    EXPECT_CALL( *obj, getFuelConsumption()).WillOnce(Return(fuel(13)));

    EXPECT_ANY_THROW(cmd.Execute());
}

