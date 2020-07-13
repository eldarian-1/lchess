#pragma once

enum LConst
{
	L_COLOR_WHITE = 1,
	L_COLOR_BLACK = 2,
	L_COLOR_ANY = 4,

	L_TYPE_BI = 0,
	L_TYPE_BOT,
	L_TYPE_NET,

	L_BOT_BEGIN,
	L_BOT_WEAK,
	L_BOT_AVERAGE,
	L_BOT_STRONG,

	L_FIGURE_KING,
	L_FIGURE_QUEEN,
	L_FIGURE_ELEPHANT,
	L_FIGURE_HORSE,
	L_FIGURE_ROOK,
	L_FIGURE_PAWN,

	L_VALUE_KING = 900,
	L_VALUE_QUEEN = 90,
	L_VALUE_ELEPHANT = 50,
	L_VALUE_HORSE = 30,
	L_VALUE_ROOK = 30,
	L_VALUE_PAWN = 10,

	L_SQUARE_NATIVE,
	L_SQUARE_FOCUSED,
	L_SQUARE_SELECTED,
	L_SQUARE_VARIANT,
	L_SQUARE_VARIANT_FOCUSED,

	L_PATH_FALSE = 0,
	L_PATH_TRUE = 1,
	L_PATH_CASTLING = 2,
	L_PATH_TRANSFORMATION = 4,
	L_PATH_CHECK = 8,
	L_PATH_MAT = 16,
	L_PATH_PAT = 32,

	L_GAME_RUNNING = 64,
	L_GAME_PAUSE = 128,
	L_GAME_FINISH = 256,

	L_CHESS_BOARD_SIZE = 8,
	L_FIGURE_COUNT = 32,
	L_SQUARE_COUNT = 64,

	L_PADDING_BOARD = 30,

	L_SIZE_NHD = 1,
	L_SIZE_FWVGA = 2,
	L_SIZE_HD = 4,
	L_SIZE_HDP = 8,
	L_SIZE_FHD = 16,
	L_SIZE_FULL = 32,

	L_SIZE_NHD_WIDTH = 640,
	L_SIZE_NHD_HEIGHT = 360,

	L_SIZE_FWVGA_WIDTH = 854,
	L_SIZE_FWVGA_HEIGHT = 480,

	L_SIZE_HD_WIDTH = 1280,
	L_SIZE_HD_HEIGHT = 720,

	L_SIZE_HDP_WIDTH = 1600,
	L_SIZE_HDP_HEIGHT = 900,

	L_SIZE_FHD_WIDTH = 1920,
	L_SIZE_FHD_HEIGHT = 1080

};
