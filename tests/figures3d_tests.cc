#include <functions/figures3d.h>
#include <gtest/gtest.h>
 
// TEST 1
TEST(Figure3dTest, Figure_Comp1) {
    Figure3D figure;
    EXPECT_EQ(figure.get_type(), BALL);
}

// TEST 2
TEST(Figure3dTest, Figure_Comp2) {
    Figure3D figure = Figure3D(PARALLELEPIPED, 1, 4, 7);
    EXPECT_EQ(figure.get_type(), PARALLELEPIPED);
}

// TEST 3
TEST(Figure3dTest, FigureSquare_BALL) {
    Figure3D figure = Figure3D(BALL, 2);
    EXPECT_NEAR(figure.get_square_figure(), 50.264, 0.01);
}

// TEST 4
TEST(Figure3dTest, FigureVolume_BALL) {
    Figure3D figure = Figure3D(BALL, 2);
    EXPECT_NEAR(figure.get_volume_figure(), 33.509, 0.01);
}

// TEST 5
TEST(Figure3dTest, FigureSquare_CYLINDER) {
    Figure3D figure = Figure3D(CYLINDER, 1, 4);
    EXPECT_NEAR(figure.get_square_figure(), 31.415, 0.01);
}

// TEST 6
TEST(Figure3dTest, FigureVolume_CYLINDER) {
    Figure3D figure = Figure3D(CYLINDER, 1, 4);
    EXPECT_NEAR(figure.get_volume_figure(), 12.566, 0.01);
}

// TEST 7
TEST(Figure3dTest, FigureSquare_PARALLELEPIPED) {
    Figure3D figure = Figure3D(PARALLELEPIPED, 1, 4, 7);
    EXPECT_NEAR(figure.get_square_figure(), 78, 0.01);
}

// TEST 8
TEST(Figure3dTest, FigureVolume_PARALLELEPIPED) {
    Figure3D figure = Figure3D(PARALLELEPIPED, 1, 4, 7);
    EXPECT_NEAR(figure.get_volume_figure(), 28, 0.01);
}

// TEST 9
TEST(SpaceTest, Space_Comp) {
    Space space;
    EXPECT_EQ(space.get_count(), 0);
}

// TEST 10
TEST(SpaceTest, Space_Add) {
    Space space;
    Figure3D figure1(BALL, 3);
    Figure3D figure2(PARALLELEPIPED, 2, 2, 2);
    space.add_figure(figure1, 0);
    space.add_figure(figure2, 1);
    EXPECT_NEAR(space[0].get_square_figure(), 113.094, 0.01);
    EXPECT_NEAR(space[1].get_volume_figure(), 8, 0.01);
}

// TEST 11
TEST(SpaceTest, Space_Delete1) {
    Space space;
    Figure3D figure1(BALL, 1);
    Figure3D figure2(CYLINDER, 2, 4);
    Figure3D figure3(PARALLELEPIPED, 1, 5, 7);
    space.add_figure(figure1, 0);
    space.add_figure(figure2, 1);
    space.add_figure(figure3, 2);

    space.delete_figure(1);
    EXPECT_NEAR(space[1].get_volume_figure(), 35, 0.01);
}

// TEST 12
TEST(SpaceTest, Space_Delete2) {
    Space space;
    Figure3D figure1(BALL, 1);
    Figure3D figure2(CYLINDER, 2, 4);
    Figure3D figure3(PARALLELEPIPED, 1, 5, 7);
    space.add_figure(figure1, 0);
    space.add_figure(figure2, 1);
    space.add_figure(figure3, 2);

    space.delete_figure(0);
    EXPECT_NEAR(space[1].get_volume_figure(), 35, 0.01);
}