#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "TestCaseCommon.h"
#include "TestCaseCommonOffline.h"
#include "TestCaseMain.h"
#include "TestCaseOffline.h"
#include "PackingSdkAll.h"
#include <gtest/gtest.h>

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
