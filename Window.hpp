#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL2/SDL.h>
#include <iostream>
#include "Fractal.hpp"

class Window
{
public:
    Window(int screen_width = 640, int screen_height = 480)
        : screen_width{screen_width}, screen_height{screen_height}
    {
        createWindow();
    };
    ~Window()
    {
        destroyWindow();
    };

    const int getWidth() { return screen_width; };
    const int getHeight() { return screen_height; };
    void drawWindow(int w_left_top, int h_left_top, int width, int height);
    bool processKey();

private:
    int screen_width{};
    int screen_height{};
    SDL_Window *screen_window{};
    SDL_Renderer *gRenderer{};

    void createWindow();
    void destroyWindow();
    void drawPixel(int x, int y, Mandelbrot mand);
};
#endif
