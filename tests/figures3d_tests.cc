#include <functions/figures3d.h>
#include <gtest/gtest.h>

// BALL: 4 * PI * pow(_radius, 2),
//  (4. / 3) * (PI * pow(_radius, 3))
// 
// CYLINDER: 2 * PI * _radius * (_radius + _height),
//  PI * pow(_radius, 2) * _height
// 
// PARALLELEPIPED: 2 * (_line1 * _line2 + _line1 * _line3 + _line2 * _line3),
//  _line1 * _line2 * _line3

using namespace std;

// TEST 1
TEST(Figure3dTest, Figure_Square) {
    auto figure1 = make_shared<Ball>(2);
    auto figure2 = make_shared<Cylinder>(1, 4);
    auto figure3 = make_shared<Parallelepiped>(1, 4, 7);

    EXPECT_NEAR(figure1->get_square_figure(), 4 * PI * 2 * 2, 0.01);
    EXPECT_NEAR(figure2->get_square_figure(), 2 * PI * 1 * (1 + 4), 0.01);
    EXPECT_NEAR(figure3->get_square_figure(), 2 * (1 * 4 + 1 * 7 + 4 * 7), 0.01);
}

// TEST 2
TEST(Figure3dTest, Figure_Volume) {
    auto figure1 = make_shared<Ball>(2);
    auto figure2 = make_shared<Cylinder>(1, 4);
    auto figure3 = make_shared<Parallelepiped>(1, 4, 7);

    EXPECT_NEAR(figure1->get_volume_figure(), (4. / 3) * (PI * 2 * 2 * 2), 0.01);
    EXPECT_NEAR(figure2->get_volume_figure(), PI * 1 * 1 * 4, 0.01);
    EXPECT_NEAR(figure3->get_volume_figure(), 1 * 4 * 7, 0.01);
}

// TEST 3
TEST(Figure3dTest, Figure_Swap) {
    Ball ball(3);
    Ball ball2(10);
    ball.swap(ball2);
    EXPECT_NEAR(ball2.get_square_figure(), 113.094, 0.01);

    Cylinder cylinder(3, 1);
    Cylinder cylinder2(10, 1);
    cylinder.swap(cylinder2);
    EXPECT_NEAR(cylinder2.get_square_figure(), 75.396, 0.01);

    Parallelepiped parallelepiped(1, 2, 3);
    Parallelepiped parallelepiped2(5, 6, 7);
    parallelepiped.swap(parallelepiped2);
    EXPECT_NEAR(parallelepiped2.get_volume_figure(), 6.0, 0.01);
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- //

// TEST 9
TEST(SpaceTest, Space_Size) {
    Space space;
    EXPECT_EQ(space.get_size(), 0);
}

// TEST 10
TEST(SpaceTest, Space_Add) {
    Space space;
    auto figure1 = make_shared<Ball>(3);
    auto figure2 = make_shared<Parallelepiped>(2, 2, 2);
    space.add_figure(figure1, 0);
    space.add_figure(figure2, 1);

    EXPECT_NEAR(space[0]->get_square_figure(), 113.094, 0.01);
    EXPECT_NEAR(space[1]->get_volume_figure(), 8, 0.01);
}

// TEST 11
TEST(SpaceTest, Space_Delete) {
    Space space;
    auto figure1 = make_shared<Ball>(1);
    auto figure2 = make_shared<Cylinder>(2, 4);
    auto figure3 = make_shared<Parallelepiped>(1, 5, 7);
    space.add_figure(figure1, 0);
    space.add_figure(figure2, 1);
    space.add_figure(figure3, 2);

    space.delete_figure(1);
    EXPECT_NEAR(space[1]->get_volume_figure(), 35, 0.01);
    EXPECT_EQ(space.get_size(), 2);
}

// TEST 13
TEST(SpaceTest, Figure_Max_Volume_Test) {
    Space space;
    auto figure1 = make_shared<Ball>(10); // 4188.666
    auto figure2 = make_shared<Cylinder>(5, 10); // 785.375
    auto figure3 = make_shared<Parallelepiped>(3, 4, 5); //60
    space.add_figure(figure1, 0);
    space.add_figure(figure2, 1);
    space.add_figure(figure3, 2);

    EXPECT_NEAR(space[space.get_figure_with_max_volume()]->get_volume_figure(), 4188.666, 0.01);
}