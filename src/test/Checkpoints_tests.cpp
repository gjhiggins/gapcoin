// Copyright (c) 2011-2013 The Bitcoin Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{

    uint256 p14738 = uint256("0xce083f91261ea327c2e3b855ba3df7bb696010fec985ab8b5c699b5df3edcd27");
    uint256 p42132 = uint256("0x945512bd3775afec9be70503302f230c3d5f678305fcc7225c3a6ca754ce296c");
    BOOST_CHECK(Checkpoints::CheckBlock(14738, p14738));
    BOOST_CHECK(Checkpoints::CheckBlock(42132, p42132));

    
    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(14738, p42132));
    BOOST_CHECK(!Checkpoints::CheckBlock(42132, p14738));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(14738+1, p42132));
    BOOST_CHECK(Checkpoints::CheckBlock(42132+1, p14738));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 42132);
}    

BOOST_AUTO_TEST_SUITE_END()
