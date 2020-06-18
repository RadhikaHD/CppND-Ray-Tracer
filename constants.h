#pragma once
#include <limits>
#include "types.h"

constexpr rgb LIGHT_BLUE{0.5f, 0.7f, 1.0f};
constexpr rgb WHITE{1.0f, 1.0f, 1.0f};
constexpr rgb BLACK{0.0f, 0.0f, 0.0f};
constexpr rgb RED{1.0f, 0.0f, 0.0f};
constexpr position CAMERA(0.0f, 0.0f, 0.0f);
constexpr position SCREEN_BOTTOM_LEFT(-2.0f, -1.0f, -1.0f);
constexpr float SCREEN_WIDTH = 4.0;
constexpr float SCREEN_HEIGHT = 2.0;
constexpr int NCOLS = 200;
constexpr int NROWS = 100;
constexpr float SCREEN_Z_POS = -1.0f;
constexpr float TMIN = 0.0f;
constexpr float TMAX = std::numeric_limits<float>::max();
