#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream>
#include <filesystem>
#include <List>

#include "restau_config.h"
#include "view_listener.hpp"
#include "observer.hpp"
#include "raylib.h"

class View : public IObserver
{
private:
    int screenWidth;
    int screenHeight;
    ViewListener *listener;

public:
    View(IObservable &observable);
    View(const View&) = delete;
    virtual ~View() = default;
    void setListener(ViewListener *listener);
    void printNumber(int n);

    // GUI CODE
    void configure();
    void run();
    void update(const std::string &message_from_observable) override;
};

View::View(IObservable &observable) : IObserver(observable){}

void View::setListener(ViewListener *listener)
{
    this->listener = listener;
}

void View::printNumber(int n)
{
    std::cout << n << "\n";
}

void View::run()
{
    // int j = 0;
    // int pos_x = 0;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        //j++;
        // if (IsKeyDown(KEY_RIGHT))
        // {
        //     // DrawTexture(char_images[(j / 5) % CHARACTER_IMAGES_AMOUNT], pos_x,0, WHITE);
        //     listener->move_player_right();
        //     pos_x += 4;
        // }
        // pos_x++;
        //  Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        if (IsKeyDown(KEY_LEFT))
        {
            // DrawTexture(rev_char_images[(j / 5) % CHARACTER_IMAGES_AMOUNT], pos_x,0, WHITE);
            listener->move_player_left();
        }
        // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}

void View::configure()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    screenWidth = 2 * 800;
    screenHeight = 2 * 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    // Images loading
    // Texture2D char_images[CHARACTER_IMAGES_AMOUNT];
    // Texture2D rev_char_images[CHARACTER_IMAGES_AMOUNT];
    // int i = 0;
    // for (const auto &entry : std::filesystem::directory_iterator(CHARACTER_PATH))
    // {
    //     char_images[i++] = LoadTexture(entry.path().string().c_str());
    // }
    // i = 0;
    // for (const auto &entry : std::filesystem::directory_iterator(REVERSED_CHARACTER_PATH))
    // {
    //     rev_char_images[i++] = LoadTexture(entry.path().string().c_str());
    // }

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
}

void View::update(const std::string &message_from_observable)
{
    std::cout << "I received a message" << std::endl;
}

#endif