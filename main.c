#include "raylib.h"

int main(void)
{
	//Inicialización
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1280;
	const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "Verzach3's FPS Test");



	//Camera
	Camera camera = { 0 };
	camera.position = (Vector3) { 0.0f, 1.0f, -2.0f };
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy = 60.0f;
	camera.type = CAMERA_PERSPECTIVE;
	SetCameraMode(camera, CAMERA_FIRST_PERSON);

    //Player
    Vector3 playerPosition = (Vector3) { camera.position.x, camera.position.y, camera.position.z };
    Vector3 playerSize = { 0.5f, 0.5f, 0.5f };
    Color playerColor = GREEN;


	//Enemigos

		//BOX
	Vector3 enemyBoxPos = { -4.0f, 1.0f, 0.0f };
    Vector3 enemyBoxPos2 = { 6.0f, 1.0f, 0.0f };
	Vector3 enemyBoxSize = { 2.0f, 2.0f, 2.0f };

		//Sphere
	Vector3 enemySpherePos = { 4.0f, 0.0f, 0.0f };
	float enemySphereSize = 1.5f;


	//Booleano de colisiones
	bool collision = false;


	//FPS Objetivo

	SetTargetFPS(120);

    // ToggleFullscreen();


	//Main Game Loop
	while (!WindowShouldClose()) //Detecta ESC o el boton de cerrar
	{
		//Update routines
		//----------------------------------------------------------------------------------
			//Colisiones 
        Vector3 oldCamPos = camera.position;

            //Actualiza la camara
        playerPosition = (Vector3) { camera.position.x, camera.position.y, camera.position.z };
		

			//Movimiento del jugador
		if (IsKeyDown(KEY_D)) playerPosition.x -= 0.2f;
		else if (IsKeyDown(KEY_A)) playerPosition.x += 0.2f;
        else if (IsKeyDown(KEY_S)) playerPosition.z -= 0.2f;
        else if (IsKeyDown(KEY_W)) playerPosition.z += 0.2f;
        else if (IsKeyDown(KEY_SPACE)) camera.fovy += 0.5f;
        UpdateCamera(&camera);



        // Check collisions player vs enemy-box
        if (CheckCollisionBoxes(
            (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
                                     playerPosition.y - playerSize.y/2,
                                     playerPosition.z - playerSize.z/2 },
                          (Vector3){ playerPosition.x + playerSize.x/2,
                                     playerPosition.y + playerSize.y/2,
                                     playerPosition.z + playerSize.z/2 }},
            (BoundingBox){
                            (Vector3){ 
                                    enemyBoxPos.x - enemyBoxSize.x/2,
                                    enemyBoxPos.y - enemyBoxSize.y/2,
                                    enemyBoxPos.z - enemyBoxSize.z/2 },

                            (Vector3){ 
                                    enemyBoxPos.x + enemyBoxSize.x/2,
                                    enemyBoxPos.y + enemyBoxSize.y/2,
                                    enemyBoxPos.z + enemyBoxSize.z/2 }

                                })) collision = true;


        // Check collisions player vs enemy-sphere
        else if (CheckCollisionBoxSphere(
            (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
                                     playerPosition.y - playerSize.y/2,
                                     playerPosition.z - playerSize.z/2 },
                          (Vector3){ playerPosition.x + playerSize.x/2,
                                     playerPosition.y + playerSize.y/2,
                                     playerPosition.z + playerSize.z/2 }},
            enemySpherePos, enemySphereSize)) collision = true;
        else collision = false;

        if (collision) DrawText("Collide", 220, 40, 20, BLUE);
        else DrawText("Dont Collide", 220, 40, 20, BLUE);

        //Colisiones
        if (collision) camera.position = oldCamPos;


		//----------------------------------------------------------------------------------


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // Draw enemy-box
                DrawCube(enemyBoxPos, enemyBoxSize.x, enemyBoxSize.y, enemyBoxSize.z, GRAY);
                DrawCubeWires(enemyBoxPos, enemyBoxSize.x, enemyBoxSize.y, enemyBoxSize.z, DARKGRAY);

                //
                DrawCube(enemyBoxPos2, enemyBoxSize.x, enemyBoxSize.y, enemyBoxSize.z, GRAY);
                //

                // Draw enemy-sphere
                DrawSphere(enemySpherePos, enemySphereSize, GRAY);
                DrawSphere((Vector3) { 1.0f, 1.0f, 1.0f}, enemySphereSize, RED);
                DrawSphereWires(enemySpherePos, enemySphereSize, 16, 16, DARKGRAY);

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