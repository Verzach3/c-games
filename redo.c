#include "raylib.h"

////////////////////////////////
////Declaracion de funciones////
////////////////////////////////
void fullscreen(void);
void controls(void);
void physics(void);
void camera(void);
void player(void);


//Funcion principal
int main(void)
{
    //Inicializacion de la ventana
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "FPS Test");

    //Main Game Loop
    while (!WindowShouldClose()) //Detecta ESC o la X de la ventana
    {
        //TODO LO QUE ESTA AQUI SE EJECUTA CADA FRAME



        //Draw
    BeginDrawing();
    
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        //Lo que esta aca dentro se dibuja en la pantalla


        EndMode3D();

        //Muestra la cantidad de FPS en pantalla
        DrawFPS(10, 10);

    EndDrawing();

    }
    
    CloseWindow(); //Cierra la ventana

    return 0;

}



