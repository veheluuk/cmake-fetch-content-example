cmake_minimum_required(VERSION 3.20)

project(cmake_fetch_content_test CXX)

include(FetchContent) # once in the project to include the module

add_executable(
  cmake_fetch_content_test
  "main.cpp"
)

FetchContent_Declare(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_TAG bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/0.9.9.8
)

FetchContent_MakeAvailable(glm)

FetchContent_Declare(
	catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG 05e10dfccc28c7f973727c54f850237d07d5e10f #v3.5.2
)

FetchContent_MakeAvailable(catch2)

target_link_libraries(
	cmake_fetch_content_test
	PRIVATE
	glm::glm
	Catch2::Catch2
	Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(cmake_fetch_content_test)
