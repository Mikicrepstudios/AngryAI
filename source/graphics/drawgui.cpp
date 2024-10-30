#include <string>
#include "SDL2/SDL.h"
#include <SDL_ttf.h>

#include "draw.h"
#include "settings.h"

SDL_Rect bg = {25, 25, 400, 300};

SDL_Rect levelRect = {bg.x, bg.y, bg.w, 100};
SDL_Rect timeRect = {bg.x, bg.y + 100, bg.w, 100};

namespace draw {
    void DrawGUI(settings::SDL_Settings &sdlSettings, int level, int timeM, int timeS) {
        std::string levelText = "Level: " + std::to_string(level);

        std::string timeMtmp = "";
        if(timeM < 10) timeMtmp = "0" + std::to_string(timeM);
        else timeMtmp = std::to_string(timeM);

        std::string timeStmp = "";
        if(timeS < 10) timeStmp = "0" + std::to_string(timeS);
        else timeStmp = std::to_string(timeS);

        std::string timeText = "Time: " + timeMtmp + ":" + timeStmp;

        draw::DrawRect(sdlSettings.renderer, bg, 100, 100, 100);

        draw::DrawText(sdlSettings.renderer, sdlSettings.font, levelRect, levelText.c_str(), sdlSettings.textColor);
        draw::DrawText(sdlSettings.renderer, sdlSettings.font, timeRect, timeText.c_str(), sdlSettings.textColor);
    }
}