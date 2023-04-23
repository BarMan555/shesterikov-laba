#include <functions/figures3d.h>
#include <gtest/gtest.h>

// TEST 3
TEST(Figure3dTest, FigureSquare_BALL) {
    Figure* figure = new BALL(2);
    EXPECT_NEAR(figure->get_square_figure(), 50.264, 0.01);
}

// TEST 4
TEST(Figure3dTest, FigureVolume_BALL) {
    Figure* figure = new BALL(2);
    EXPECT_NEAR(figure->get_volume_figure(), 33.509, 0.01);
}

// TEST 5
TEST(Figure3dTest, FigureSquare_CYLINDER) {
    Figure* figure = new CYLINDER(1, 4);
    EXPECT_NEAR(figure->get_square_figure(), 31.415, 0.01);
}

// TEST 6
TEST(Figure3dTest, FigureVolume_CYLINDER) {
    Figure* figure = new CYLINDER(1, 4);
    EXPECT_NEAR(figure->get_volume_figure(), 12.566, 0.01);
}

// TEST 7
TEST(Figure3dTest, FigureSquare_PARALLELEPIPED) {
    Figure* figure = new PARALLELEPIPED(1, 4, 7);
    EXPECT_NEAR(figure->get_square_figure(), 78, 0.01);
}

// TEST 8
TEST(Figure3dTest, FigureVolume_PARALLELEPIPED) {
    Figure* figure = new PARALLELEPIPED(1, 4, 7);
    EXPECT_NEAR(figure->get_volume_figure(), 28, 0.01);
}

// TEST 9
TEST(SpaceTest, Space_Comp) {
    Space space;
    EXPECT_EQ(space.get_size(), 0);
}

// TEST 10
TEST(SpaceTest, Space_Add) {
    Space space;
    Figure* figure1 = new BALL(3);
    Figure* figure2 = new PARALLELEPIPED(2, 2, 2);
    space.add_figure(figure1->clone(), 0);
    space.add_figure(figure2->clone(), 1);
    EXPECT_NEAR(space[0]->get_square_figure(), 113.094, 0.01);
    EXPECT_NEAR(space[1]->get_volume_figure(), 8, 0.01);
}

// TEST 11
TEST(SpaceTest, Space_Delete1) {
    Space space;
    Figure* figure1 = new BALL(1);
    Figure* figure2 = new CYLINDER(2, 4);
    Figure* figure3 = new PARALLELEPIPED(1, 5, 7);
    space.add_figure(figure1->clone(), 0);
    space.add_figure(figure2->clone(), 1);
    space.add_figure(figure3->clone(), 2);

    space.delete_figure(1);
    EXPECT_NEAR(space[1]->get_volume_figure(), 35, 0.01);
}

// TEST 12
TEST(SpaceTest, Space_Delete2) {
    Space space;
    Figure* figure1 = new BALL(1);
    Figure* figure2 = new CYLINDER(2, 4);
    Figure* figure3 = new PARALLELEPIPED(1, 5, 7);
    space.add_figure(figure1->clone(), 0);
    space.add_figure(figure2->clone(), 1);
    space.add_figure(figure3->clone(), 2);

    space.delete_figure(0);
    EXPECT_NEAR(space[1]->get_volume_figure(), 35, 0.01);
}

// TEST 13
TEST(SpaceTest, Figure_Max_Volume_Test) {
    Space space;
    Figure* figure1 = new BALL(10); // 4188.666
    Figure* figure2 = new CYLINDER(5, 10); // 785.375
    Figure* figure3 = new PARALLELEPIPED(3, 4, 5); //60
    space.add_figure(figure1->clone(), 0);
    space.add_figure(figure2->clone(), 1);
    space.add_figure(figure3->clone(), 2);

    EXPECT_NEAR(space[space.get_figure_with_max_volume()]->get_volume_figure(), 4188.666, 0.01);
}