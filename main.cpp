#include <cstdint>

#include <glm/glm.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Example glm unit test")
{
    using namespace glm;

    auto forward = vec3{0, 0, -1};
    auto up = vec3{0, 1, 0};
    auto right = vec3{1, 0, 0};
    
    auto cross_product = cross(forward, up);

    REQUIRE(right.x == cross_product.x);
    REQUIRE(right.y == cross_product.y);
    REQUIRE(right.z == cross_product.z);
}
