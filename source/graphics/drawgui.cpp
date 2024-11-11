#include <string>
#include "SDL2/SDL.h"

#include "mf/core.h"
#include "mf/colors.h"
#include "mf/graphics.h"

SDL_Rect bg = {25, 25, 400, 300};

SDL_Rect levelRect = {bg.x, bg.y, bg.w, 100};
SDL_Rect timeRect = {bg.x, bg.y + 100, bg.w, 100};

namespace draw {
    void DrawGUI(core::MF_Window &window, int level, int timeM, int timeS) {
        std::string levelText = "Level: " + std::to_string(level);

        std::string timeMtmp = "";
        if(timeM < 10) timeMtmp = "0" + std::to_string(timeM);
        else timeMtmp = std::to_string(timeM);

        std::string timeStmp = "";
        if(timeS < 10) timeStmp = "0" + std::to_string(timeS);
        else timeStmp = std::to_string(timeS);

        std::string timeText = "Time: " + timeMtmp + ":" + timeStmp;

        draw::DrawRect(window.renderer, bg, colors::general::gray);

        draw::DrawText(window.renderer, window.font, levelRect, levelText.c_str(), colors::text::whiteTextColor);
        draw::DrawText(window.renderer, window.font, timeRect, timeText.c_str(), colors::text::whiteTextColor);
    }
}