/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, resetTest)
{
	Piezas tBoard;
	for(int i=0; i<BOARD_ROWS; i++){
    	for(int j=0; j<BOARD_COLS; j++){
        	tBoard.dropPiece(j);
    	}
	}
	tBoard.reset();
	for(int i=0; i<BOARD_ROWS; i++){
    	for(int j=0; j<BOARD_COLS; j++){
        	ASSERT_TRUE(tBoard.pieceAt(i,j) == Blank);
    	}
	}
}
TEST(PiezasTest, oobDropPieceTest)
{
	Piezas tBoard;
	ASSERT_TRUE(tBoard.dropPiece(-1) == Invalid);
	ASSERT_TRUE(tBoard.dropPiece(BOARD_COLS) == Invalid);
}

TEST(PiezasTest, dropPieceandTurnSwapTest)
{
	Piezas tBoard;
	tBoard.dropPiece(0);
	ASSERT_TRUE(tBoard.dropPiece(0) == O);
}

TEST(PiezasTest, oobPieceAtTest)
{
	Piezas tBoard;
	ASSERT_TRUE(tBoard.pieceAt(-1,0) == Invalid);
	ASSERT_TRUE(tBoard.pieceAt(BOARD_ROWS,0) == Invalid);
	ASSERT_TRUE(tBoard.pieceAt(0,-1) == Invalid);
	ASSERT_TRUE(tBoard.pieceAt(0,BOARD_COLS) == Invalid);
}
TEST(PiezasTest, pieceAtTest)
{
	Piezas tBoard;
	tBoard.dropPiece(0);
	ASSERT_TRUE(tBoard.pieceAt(0,0) == X);
	ASSERT_TRUE(tBoard.pieceAt(1,0) == Blank);
}

TEST(PiezasTest, gameStateUnfinishedTest)
{
	Piezas tBoard;
	ASSERT_TRUE(tBoard.gameState() == Invalid);
}

TEST(PiezasTest, gameStateTieTest)
{
	Piezas tBoard;
	for(int i=0; i<BOARD_ROWS; i++){
    	for(int j=0; j<BOARD_COLS; j++){
        	tBoard.dropPiece(j);
    	}
	}
	ASSERT_TRUE(tBoard.gameState() == Blank);
}

TEST(PiezasTest, gameStateVertWinTest)
{
	Piezas tBoard;
	for(int i=0; i<BOARD_ROWS; i++){
		tBoard.dropPiece(0);
		tBoard.dropPiece(-1);
	}
	for(int i=0; i<BOARD_ROWS; i++){
    	for(int j=1; j<BOARD_COLS; j++){
        	tBoard.dropPiece(j);
    	}
	}
	ASSERT_TRUE(tBoard.gameState() == X);
}

TEST(PiezasTest, gameStateHorizWinTest)
{
	Piezas tBoard;
	for(int i=0; i<BOARD_COLS; i++){
		tBoard.dropPiece(i);
		tBoard.dropPiece(-1);
	}
	for(int i=1; i<BOARD_ROWS; i++){
    	for(int j=0; j<BOARD_COLS; j++){
        	tBoard.dropPiece(j);
    	}
	}
	ASSERT_TRUE(tBoard.gameState() == X);
}
