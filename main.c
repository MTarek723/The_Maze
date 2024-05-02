#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
#undef main

const int WIDTH = 640;
const int HEIGHT = 480;
const int PLAYER_SIZE = 10;
const Uint8 *keystate;
const float PLAYER_SPEED = 10.0f;


int main(int argc, char* argv[])
{
    float PLAYER_ANGLE = 0;
    float dx = cos(PLAYER_ANGLE);
    float dy = sin(PLAYER_ANGLE);
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Can't initialize window Error:%s", SDL_GetError());
    }
    SDL_Window* window;
    window = SDL_CreateWindow("The Maze", SDL_WINDOWPOS_UNDEFINED,
     SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Uint32 lasttick = SDL_GetTicks();
    SDL_Rect Player;
    Player.x = (WIDTH / 2 - 150) - (PLAYER_SIZE / 2);
    Player.y = (HEIGHT  - 150) - (PLAYER_SIZE / 2);
    Player.h = PLAYER_SIZE;
    Player.w = PLAYER_SIZE;
    float player_x = (float)Player.x;
    float player_y = (float)Player.y;

    int map[15][20] = 
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    SDL_Event e;
    bool quit = false;
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        
        Uint32 currtick = SDL_GetTicks();
        float elapsed = (currtick - lasttick) / 1000.0f;
        keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_A])
        {
            PLAYER_ANGLE -= 0.01;
            if (PLAYER_ANGLE < 0)
            {
                PLAYER_ANGLE += 6.28;
            }            
            dx = cos(PLAYER_ANGLE);
            dy = sin(PLAYER_ANGLE);

        }
        if (keystate[SDL_SCANCODE_D])
        {
            PLAYER_ANGLE += 0.01;
            if (PLAYER_ANGLE > 6.26)
            {
                PLAYER_ANGLE -= 6.28;
            }
            dx = cos(PLAYER_ANGLE);
            dy = sin(PLAYER_ANGLE);
        }
        if (keystate[SDL_SCANCODE_W])
        {
            player_x += (dx + elapsed * PLAYER_SPEED) / 2;
            player_y += (dy + elapsed * PLAYER_SPEED) / 2;
        }
        if (keystate[SDL_SCANCODE_S])
        {
            player_x -= (dx + elapsed * PLAYER_SPEED) / 2;
            player_y -= (dy + elapsed * PLAYER_SPEED) / 2;
        }
        if (player_x > WIDTH - PLAYER_SIZE)
        {
            player_x = WIDTH - PLAYER_SIZE;
        }
        else if (player_x < 32)
        {
            player_x = 32;
        }
        if (player_x > WIDTH - PLAYER_SIZE - 33)
        {
            player_x = WIDTH - PLAYER_SIZE - 33;
        }
        if (player_y > HEIGHT - PLAYER_SIZE - 33)
        {
            player_y = HEIGHT - PLAYER_SIZE - 33;
        }
        if (player_y < 32)
        {
            player_y = 32;
        }
        if ((map[(int)(player_y + 10) / 32][(int)(player_x + 10) / 32]) != 1)
        {
            Player.x = (int)player_x;
            Player.y = (int)player_y;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);
        printf("%.1f\n", PLAYER_ANGLE * 180 / 3.14);
        int r;
        float ray_angle;
        ray_angle = PLAYER_ANGLE;
        int rx;
        int ry;
        float yo, xo;
        int dof, mx, my;
        for (r = 0; r < 1; ++r)
        {
            if (ray_angle > 3.14)
            {
                ry = ((Player.y / 32)) * 32;
                rx = ((Player.y - ry) / tan(ray_angle)) + Player.x;
                yo = -64;
                xo = - yo / tan(ray_angle);
            }
            if (ray_angle < 3.14)
            {
                ry = ((Player.y / 32) + 1) * 32;
                rx = ((Player.y - ry) / tan(ray_angle)) + Player.x;
                yo = 64;
                xo = - yo / tan(ray_angle);
            }
            if (ray_angle == 3.14 || ray_angle == 0)
            {
                rx = Player.x;
                ry = Player.y;
                dof = 20;
            }
            while (dof < 20)
            {
                mx = (int)(rx / 32);
                my = (int)(ry / 32);
                if (map[my][mx] == 1)
                {
                    dof = 20;
                }
                else
                {
                    rx += xo;
                    ry += yo;
                    dof += 1;
                }


            }
        }
        printf("%d\n%d\n", rx, ry);


        for (int i = 0; i < 15; ++i)
        {
            for (int j = 0; j < 20; ++j)
            {
                SDL_Rect map_tile = {j * 32, i * 32, 32, 32};
                if (map[i][j] == 1)
                {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderDrawRect(renderer, &map_tile);
                    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
                    SDL_Rect fill_tile = {j * 32 + 1, i * 32 + 1,
                    30, 30};
                    SDL_RenderFillRect(renderer, &fill_tile);
                }
                
            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &Player);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawLine(renderer, Player.x + 5, Player.y + 5, rx, ry);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderPresent(renderer);
        lasttick = currtick;
    }
    
}

