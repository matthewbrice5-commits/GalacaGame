#include <iostream>
#include <vector>
#include "raylib.h"


struct Bullet{  //Keeps track of the bullets x and y coordiante 
    int x;
    int y;
    
};

struct BasicEnemy{ // Holds the top left and bottom right of the image, with a method 
                   // that tells the enemy how to move
    int x;
    int y;
    int bottomx;
    int bottomy;
    
    void updateframe(){
        y += 2;
    }
    
    
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
    Texture2D userspriteleft = LoadTexture("userleft.png");
    Texture2D userspriteright = LoadTexture("userright.png");
    Texture2D currentusersprite = usersprite;; //This gets changed during the code for the users tilt left and right
    Texture2D background = LoadTexture("background.png");
    Texture2D bulletimage = LoadTexture("bullet.png");
    Texture2D enemyimage = LoadTexture("enemy1.png");
    Texture2D explosion = LoadTexture("explosion.png");
    
    std::vector<Bullet> firingbullets; //This vector holds all active bullets on the screenHeight
    
    // This holds enemy positions for the first wave
    std::vector<BasicEnemy> level1;
    int enemypos = 100;
    
    //fills first level with enemies 
    for(int i = 0; i < 6; i++){
        BasicEnemy enemy;
        enemy.x = enemypos;
        enemy.y = 00;
        enemy.bottomx = enemy.x+49;
        enemy.bottomy = enemy.y+49;
        
        
        
        level1.push_back(enemy);
        enemypos+=75;
        
    }
    
    
    

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
            currentusersprite = userspriteleft;
            }
            
        } else if (IsKeyDown(KEY_D)){// Sets the border ie. cannot go too far right
            if (userpositionx != 530){
            userpositionx+= speed;
            currentusersprite = userspriteright;
            }
        } else {
            currentusersprite = usersprite;
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
            
            DrawTexture(currentusersprite, userpositionx, userpositiony, WHITE);//Draws users position
            
            //loop that draws all bullets
            for(size_t i = 0; i < firingbullets.size(); i++){
                
                if (firingbullets[i].y < 5){ //If the bullet goes out of bounds, offload it
                    firingbullets.erase(firingbullets.begin() + i);
                }
                
                firingbullets[i].y -= 8;
                DrawTexture(bulletimage, firingbullets[i].x, firingbullets[i].y, WHITE);   

               
            }
            
            //loop that draws all enemies in level1
            for(int i = (int)level1.size() - 1; i >= 0; i--){
                bool hit = false;
                
                
                
                for(int j = (int)firingbullets.size() - 1; j >= 0; j--){
                    
                    if(firingbullets[j].x > level1[i].x && firingbullets[j].x < level1[i].bottomx && firingbullets[j].y > level1[i].y && firingbullets[j].y < level1[i].bottomy){
                        
                        hit = true;
                        DrawText("Hit!", 100, 100, 20, RED);
                        firingbullets.erase(firingbullets.begin() + j);
                        break;
                        
                    }
                    
                }
              
                if(!hit) {  // Only draw and update if NOT hit
                    DrawTexture(enemyimage, level1[i].x, level1[i].y, WHITE);
                    level1[i].updateframe();
                } else {
                    // Draw explosion here if you want
                    level1.erase(level1.begin() + i);
                }
                    
                
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