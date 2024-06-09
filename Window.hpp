#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL2/SDL.h>
#include <iostream>
#include <thread>
#include <algorithm>
#include <array>
#include "Fractal.hpp"
#include "Mandelbrot.hpp"
#include "Julia.hpp"

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
    void calculateWindow(Fractal &fractal, std::vector<Fractal::Color> &screen, int h_start, int height);
    void drawWindow(const std::vector<Fractal::Color> &screen, int h_start, int height);
    bool processKey();
    static constexpr int threadNum{8};

private:
    enum fractalNum
    {
        MandelbrotNumber,
        JuliaNumber,
        LastNumber
    };

    int screen_width{};
    int screen_height{};
    SDL_Window *screen_window{};
    SDL_Renderer *gRenderer{};
    fractalNum currentFractal{MandelbrotNumber};
    Fractal* getCurrentFractal(SDL_Keycode key);

    void createWindow();
    void destroyWindow();
};
#endif
