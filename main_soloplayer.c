#include "raylib.h"

int main(void)
{
	//Inicialización
	
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Verzach3's FPS Test");

    //--------------------------------------------------------------------------------------




    //Player
    Vector3 playerPosition = (Vector3) { 0.0f, 1.0f, -2.0f };
    Vector3 playerSize = { 0.5f, 1.0f, 0.5f };
    Color playerColor = GREEN;

    //--------------------------------------------------------------------------------------

    //Camera
    Camera camera = { 0 };
    camera.position = (Vector3) { 0.0f, 3.0f, -4.0f} ;
    camera.target = playerPosition;
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.type = CAMERA_PERSPECTIVE;
    SetCameraMode(camera, CAMERA_THIRD_PERSON);   
    
    //--------------------------------------------------------------------------------------


	//FPS Objetivo

	SetTargetFPS(60);

    // ToggleFullscreen();


	//Main Game Loop
	while (!WindowShouldClose()) //Detecta ESC o el boton de cerrar
	{
		//Update routines
		//----------------------------------------------------------------------------------


            //Actualiza la camara
        camera.target = playerPosition;
		

			//Movimiento del jugador
		if (IsKeyDown(KEY_D)) playerPosition.x -= 0.2f;
		else if (IsKeyDown(KEY_A)) playerPosition.x += 0.2f;
        else if (IsKeyDown(KEY_S)) playerPosition.z -= 0.2f;
        else if (IsKeyDown(KEY_W)) playerPosition.z += 0.2f;
        else if (IsKeyDown(KEY_SPACE)) camera.fovy += 0.5f;
        UpdateCamera(&camera);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                

                // Draw player
                DrawCubeV(playerPosition, playerSize, playerColor);

                DrawGrid(10, 1.0f);        // Draw a grid

            EndMode3D();

            

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    

	}

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;

}