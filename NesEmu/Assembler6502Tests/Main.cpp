#include <gtest/gtest.h>

#include "ParsingTests.h"
#include "AssemblyCompilationTests.h"

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}