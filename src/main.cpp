#include <SDL2/SDL.h>
#ifdef LINUX
	#include <GL/gl.h>
#endif
#ifdef DARWIN
	#include <OpenGL/gl.h>
#endif

#include <iostream>
#include "GLFunctions.h"
#include "World.h"
#include "rigidbodies.h"
#include "rocket.h"
#include "SDL2/SDL_main.h"
#include "camera.h"
#include "math.h"
#include "util.h"
/// @brief function to quit SDL with error message
/// @param[in] _msg the error message to send
void SDLErrorExit(const std::string &_msg);

/// @brief initialize SDL OpenGL context
SDL_GLContext createOpenGLContext(SDL_Window *window);



//#ifdef WIN32
//int SDL_main(int argc, char *argv[])
//#else
int main()
//#endif
{

    // Initialize SDL's Video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) < 0 )
    {

      // Or die on error
      SDLErrorExit("Unable to initialize SDL");
    }

    // now get the size of the display and create a window we need to init the video
    SDL_Rect rect;
    SDL_GetDisplayBounds(0,&rect);
    // now create our window
    SDL_Window *window=SDL_CreateWindow("SDLNGL",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        rect.w/2,
                                        rect.h/2,
                                        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
                                       );
    // check to see if that worked or exit
    if (!window)
    {
      SDLErrorExit("Unable to create window");
    }

    // Create our opengl context and attach it to our window

     SDL_GLContext glContext=createOpenGLContext(window);
     if(!glContext)
     {
       SDLErrorExit("Problem creating OpenGL context");
     }
     // make this our current GL context (we can have more than one window but in this case not)
     SDL_GL_MakeCurrent(window, glContext);
    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
    SDL_GL_SetSwapInterval(1);
  // now clear the screen and swap whilst NGL inits (which may take time)

  glClear(GL_COLOR_BUFFER_BIT);
  GLFunctions::perspective(45,float(1024/720),0.1,500);


  SDL_GL_SwapWindow(window);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glColor3f(1,1,0);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  // flag to indicate if we need to exit
  bool quit=false;
  // sdl event processing data structure
  SDL_Event event;


  const float worldSize = 32.0f;
  World world(worldSize);
  Camera camera;




  world.initAsteroid();
  world.initRocket();




  // now we create an instance of our ngl class, this will init NGL and setup basic
  // opengl stuff ext. When this falls out of scope the dtor will be called and cleanup
  // our gl stuff
  while(!quit)
  {

    while ( SDL_PollEvent(&event) )
    {
      switch (event.type)
      {
        // this is the window x being clicked.
        case SDL_QUIT : quit = true; break;
        case SDL_MOUSEBUTTONDOWN:
        {
           world.makeBullets();
           break;
        }

        // if the window is re-sized pass it to the ngl class to change gl viewport
        // note this is slow as the context is re-create by SDL each time



        default : break;
      } // end of event switch
    } // end of poll events
    
    
    const unsigned char *keys = SDL_GetKeyboardState(NULL);
    
    SDL_PumpEvents();
    
    float offset = 0.0f;
//I used scancode to get a more fluid motion and get rid of that first pause
    if(keys[SDL_SCANCODE_ESCAPE]) { quit = true; }
    if(keys[SDL_SCANCODE_W])      { offset = 0.1f; }
    if(keys[SDL_SCANCODE_UP])     {glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);}
    if(keys[SDL_SCANCODE_DOWN])   {glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);}
    if(keys[SDL_SCANCODE_SPACE])  {world.makeBullets();}


//input mouse movement
    int mouse_x=0, mouse_y=0;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    world.movePlayer(offset, mouse_x);
//    world.spawnAsteroid();


    camera.setPos(world.getPlayerPosition());
    camera.rotateCam(camera.m_position);

    GLFunctions::lookAt((camera.m_position)/*camera.m_lookPos*/,world.getPlayerPosition(),Vec4(0,1,0));

    world.update();
    world.draw();

    // swap the buffers
    SDL_GL_SwapWindow(window);

  }
  // now tidy up and exit SDL
  SDL_Quit();

  return EXIT_SUCCESS;
}

SDL_GLContext createOpenGLContext(SDL_Window *window)
{
  // Request an opengl 3.2 context first we setup our attributes, if you need any
  // more just add them here before the call to create the context
  // SDL doesn't have the ability to choose which profile at this time of writing,
  // but it should default to the core profile
  // for some reason we need this for mac but linux crashes on the latest nvidia drivers
  // under centos
  #ifdef DARWIN
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  #endif
  // set multi sampling else we get really bad graphics that alias
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,2);
  // Turn on double buffering with a 24bit Z buffer.
  // You may need to change this to 16 or 32 for your system
  // on mac up to 32 will work but under linux centos build only 16
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  // enable double buffering (should be on by default)
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  //
  return SDL_GL_CreateContext(window);

}

void SDLErrorExit(const std::string &_msg)
{
  std::cerr<<_msg<<"\n";
  std::cerr<<SDL_GetError()<<"\n";
  SDL_Quit();
  exit(EXIT_FAILURE);
}
