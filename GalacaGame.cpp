#include <iostream>
#include <vector>
#include "raylib.h"


struct Bullet{
    int x;
    int y;
    
};

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
    Image icon = LoadImage("user.png");
    SetWindowIcon(icon);
    UnloadImage(icon);
    
    
    
    
    //Load in all textures 
    Texture2D usersprite = LoadTexture("user.png");
    Texture2D currentusersprite; //This gets changed during the code for the users tilt left and right
    Texture2D background = LoadTexture("background.png");
    Texture2D bulletimage = LoadTexture("bullet.png");
    
    std::vector<Bullet> firingbullets;
    
    

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
            if (userpositionx != 0){// Sets the border ie. cannot go too far left
            userpositionx-= speed;
            }
            
        } else if (IsKeyDown(KEY_D)){// Sets the border ie. cannot go too far right
            if (userpositionx != 530){
            userpositionx+= speed;
            }
        }
        //SHOOTING
        if (IsMouseButtonPressed(0)){
            //When the mouse is pressed, create a new strcut with the bullet x and y being (35,17) from the users
            // then update the y axis by increasing by 8 everytime after
            
            
            Bullet newbullet;
            newbullet.x = userpositionx + 35;
            newbullet.y = userpositiony - 17;
            
            firingbullets.push_back(newbullet); //Adds the struct to a vector, that gets displayed later
            
            
        }
        
        
        //-----------------------------------------
        
        
        
        
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        backgroundy--; // Moves the background down
        
        
        
        
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            DrawTexture(background,0,backgroundy,WHITE);//Draws the starts 
            
            DrawTexture(usersprite, userpositionx, userpositiony, WHITE);//Draws users position
            
            //loop that draws all bullets
            for(size_t i = 0; i < firingbullets.size(); i++){
                
                if (firingbullets[i].y < 5){
                    firingbullets.erase(firingbullets.begin() + i);
                }
                
                
                DrawTexture(bulletimage, firingbullets[i].x, firingbullets[i].y, WHITE);
            
                
                firingbullets[i].y -= 8;
                
                
            
            
            }
            
            
            
            

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