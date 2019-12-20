
/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL, standard IO, and strings
extern "C" {
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
}
#include <cstdio>
#include <string>
#include<iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 1200;

//Key press surfaces constants
enum KeyPressSurfaces
{
    /*KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,*/
    win1,
    win2,
    win3,
    lose2,
    lose3,
    KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load default surface
    /*gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "images/press.bmp" );

    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }*/

    //Load up surface
    gKeyPressSurfaces[ win1] = loadSurface( "images/win1.png" );
    if( gKeyPressSurfaces[ win1 ] == NULL )
    {
        printf( "Failed to load up image!\n" );
        success = false;
    }

    //Load down surface
    gKeyPressSurfaces[ win2 ] = loadSurface( "images/win2.png");
    if( gKeyPressSurfaces[ win2 ] == NULL )
    {
        printf( "Failed to load down image!\n" );
        success = false;
    }

    //Load left surface
    gKeyPressSurfaces[ win3 ] = loadSurface( "images/win3.png" );
    if( gKeyPressSurfaces[ win3 ] == NULL )
    {
        printf( "Failed to load left image!\n" );
        success = false;
    }

    //Load right surface
    gKeyPressSurfaces[ lose2 ] = loadSurface( "images/lose2.png" );
    if( gKeyPressSurfaces[ lose2 ] == NULL )
    {
        printf( "Failed to load right image!\n" );
        success = false;
    }

    gKeyPressSurfaces[ lose3 ] = loadSurface( "images/lose3.png" );
    if( gKeyPressSurfaces[ lose3 ] == NULL )
    {
        printf( "Failed to load right image!\n" );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surfaces
    for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
    {
        SDL_FreeSurface( gKeyPressSurfaces[ i ] );
        gKeyPressSurfaces[ i ] = NULL;
    }

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

SDL_Surface* loadSurface( std::string path )
{
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}


int main( int argc, char* args[] )
{
    struct state{
    int winorlose;
    int op;
    };
    state input;

    input.winorlose=0;
/*    prinf("win enter 1, lose enter 0.\n");
    scanf(input.winorlose,%d);*/



    if(input.winorlose==1){input.op=1;}
    if(input.winorlose==0){input.op=2;}
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //Set default current surface
          if(input.winorlose==1){
                gCurrentSurface = gKeyPressSurfaces[win1];
            }
            if(input.winorlose==0){
                gCurrentSurface = gKeyPressSurfaces[lose2];
            }


            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                        //User presses a key
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                           /* case SDLK_UP:
                               gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                                printf("up\n");
                                break;

                            case SDLK_DOWN:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                                break;*/


                            case SDLK_LEFT:
                               if(input.winorlose==0&&input.op==2){
                                    gCurrentSurface = gKeyPressSurfaces[lose2];
                                    break;

                               }
                               if(input.winorlose==0&&input.op==3){
                                    gCurrentSurface = gKeyPressSurfaces[lose2];
                                    input.op--;
                                    break;
                               }
                               if(input.winorlose==1&&input.op==1){
                                    gCurrentSurface = gKeyPressSurfaces[win1];
                                    break;
                               }
                               if(input.winorlose==1&&input.op==2){
                                    gCurrentSurface = gKeyPressSurfaces[win1];
                                    input.op--;
                                    break;
                               }
                               if(input.winorlose==1&&input.op==3){
                                    gCurrentSurface = gKeyPressSurfaces[win2];
                                    input.op--;
                                    break;
                               }


                            case SDLK_RIGHT:
                                if(input.winorlose==0&&input.op==2){
                                    gCurrentSurface = gKeyPressSurfaces[lose3];
                                    input.op++;
                                    break;
                               }
                               if(input.winorlose==0&&input.op==3){

                                    gCurrentSurface = gKeyPressSurfaces[lose3];
                                    break;
                               }
                               if(input.winorlose==1&&input.op==1){
                                    gCurrentSurface = gKeyPressSurfaces[win2];
                                    input.op++;
                                    break;
                               }
                               if(input.winorlose==1&&input.op==2){
                                    gCurrentSurface = gKeyPressSurfaces[win3];
                                    input.op++;
                                    break;
                               }

                               if(input.winorlose==1&&input.op==3){
                                    gCurrentSurface = gKeyPressSurfaces[win3];
                                    break;
                               }

                               case SDLK_w:

                               input.winorlose=1;
                               gCurrentSurface = gKeyPressSurfaces[win1];
                               input.op=1;
                               break;

                               case SDLK_l:

                                input.winorlose=0;
                                gCurrentSurface = gKeyPressSurfaces[lose2];
                                break;



                            /*default:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                                break;*/
                        }
                    }
                }

                //Apply the current image
                SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );

                //Update the surface
                SDL_UpdateWindowSurface( gWindow );
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}
