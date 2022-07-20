//
// Created by apisti01 on 15/07/22.
//

#include "gtest/gtest.h"

#include "../Player.h"
#include "../Player.cpp"
#include "../GameCharacter.h"
#include "../GameCharacter.cpp"
#include "../Weapon.h"
#include "../RangedWeapon.h"


class PlayerTest : public ::testing::Test {
protected:
    void SetUp() override {
        Test::SetUp();
        player.setPosition(0, 0);
    }
    Player player {sf::Texture(), nullptr, CrabSpecie::BrownCrab};
};

TEST_F(PlayerTest, DefaultConstructor) {
    ASSERT_FALSE(player.getWeapon());

    ASSERT_EQ(player.getName(), " ");

    ASSERT_EQ(player.getCoins(), 0);

    ASSERT_EQ(player.getHp(), 8);
    ASSERT_EQ(player.getMaxHp(), 10);

    ASSERT_FLOAT_EQ(player.getArmor(), 0.2);
    ASSERT_FLOAT_EQ(player.getMaxArmor(), 0.5);

    ASSERT_FLOAT_EQ(player.getStrength(), 1.2);
    ASSERT_FLOAT_EQ(player.getMaxStrength(), 2);

    ASSERT_EQ(player.getSpeed(), 2);
    ASSERT_EQ(player.getMaxSpeed(), 3);
}

TEST_F(PlayerTest, BasicInteractions) {
    // check receive coins
    player.receiveCoins(12);
    ASSERT_EQ(player.getCoins(), 12);

    // check damage received
    player.receiveDamage(5);
    ASSERT_EQ(player.getHp(), 4);
}

TEST_F(PlayerTest, Weapon) {
    // create new melee weapon
    std::unique_ptr<Weapon> weapon1 = std::make_unique<MeleeWeapon>(10, "carlo");

    // insert the new weapon, tmp should be null cause player did not have any weapon before
    auto tmp = player.changeWeapon(std::move(weapon1));

    // check which pointer does contain a weapon
    ASSERT_EQ(weapon1, nullptr);
    ASSERT_EQ(tmp, nullptr);
    ASSERT_TRUE(player.getWeapon());

    // check type of the weapon currently wielded, should be melee
    // EXPECT_EQ(typeid(player.getWeapon()), typeid(MeleeWeapon*));

    // check if the weapon correctly return the damage dealt being melee
    ASSERT_EQ(player.getWeapon()->useWeapon(sf::Vector2f{0, 0}, sf::Vector2f{0, 0}, <#initializer#>, 0), 10);

    // create a new ranged weapon
    std::unique_ptr<Weapon> weapon2 = std::make_unique<RangedWeapon>(sf::Sprite());

    // put the new weapon on, tmp takes the old melee weapon
    tmp = player.changeWeapon(std::move(weapon2));

    // check which pointer does contain a weapon
    ASSERT_TRUE(tmp);
    ASSERT_EQ(weapon2, nullptr);
    ASSERT_TRUE(player.getWeapon());

    // check type tmp
    // EXPECT_EQ(typeid(tmp.get()), typeid(MeleeWeapon*));
    // EXPECT_TRUE(typeid(player.getWeapon()) == typeid(Weapon*));

    // check if the weapon correctly return 0 as it create a new bullet
    ASSERT_EQ(player.getWeapon()->useWeapon(sf::Vector2f{0, 0}, sf::Vector2f{0, 0}, <#initializer#>, 0), 0);
}
