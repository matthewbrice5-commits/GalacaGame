#include <iostream>
#include "raylib.h"
#include "Bullet.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 600;
    const int screenHeight = 900;
    
    int userpositionx = 235;
    int userpositiony = 800;
    
    int backgroundy = 0;
    
    int speed = 5;
    

    InitWindow(screenWidth, screenHeight, "Galaca Game - Singplayer");
    
    //Load in all textures 
    Texture2D usersprite = LoadTexture("user.png");
    Texture2D background = LoadTexture("background.png");
    
    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------


    

    // Main game loop
    
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //Clears background first 
        ClearBackground(BLACK);
        
        //MOVEMENT
        if (IsKeyDown(KEY_A)) {// This code runs only once each frame, when a button is pressed 
            if (userpositionx != 0){
            userpositionx-= speed;
            }
            
        } else if (IsKeyDown(KEY_D)){
            if (userpositionx != 530){
            userpositionx+= speed;
            }
        }
        //SHOOTING
        if (IsMouseButtonPressed(0)){
            //When the mouse is pressed, create a new class with the bullet x and y being (35,17) from the users
            // then update the y axis by increasing by 8 everytime after
            
            
            //Bullet bullet1(userpositionx + 35,userpositiony-17);
            
        }
        
        
        //-----------------------------------------
        
        backgroundy--;
        
        
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            DrawTexture(background,0,backgroundy,WHITE);

            DrawText("Galaca!", 100, 200, 40, WHITE);
            
            DrawTexture(usersprite, userpositionx, userpositiony, WHITE);//Draws users position
            
            
            
            

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(usersprite);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}