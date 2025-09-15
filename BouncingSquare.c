#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define L 600 //Largura
#define A 480 //Altura

int main(int argc, char **args){
  bool rodando = true;  
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Event evento;
  SDL_Window *tela = SDL_CreateWindow("Teste quadrado", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, L, A,0);
  SDL_Surface *s = SDL_GetWindowSurface(tela); 
  SDL_Rect r = (SDL_Rect){200, 140, 100, 100};

  //Velocidade da bola
  int VelX = 4;
  int VelY = 4;  
  
  while(rodando){
    while(SDL_PollEvent(&evento)){
      if(evento.type == SDL_QUIT){
        rodando = false; //Verifico se houve uma tentativa de fechar, se foi feito, então rodando recebe false e encerra o programa
      }
   }
    //Aqui acaba a de pegar eventos do teclado.
    SDL_FillRect(s, NULL, 0x000000);
    SDL_FillRect(s, &r, 0xfffffff);

    //Somando a velocidade no eixo y, fazemos a deslocação pra baixo(vertical)
    r.y += VelY;

    //Somando a velocidade no eixo x, fazemos a deslocação pra direita(horizontal)
    r.x += VelX;
    
    
    //Aqui verificamos se o quadrado chegou no limite das telas verticais.
    if(r.y > A-r.h || r.y < 0){
      VelY = -VelY; //Se encontrou um limite, inverte o sinal/sentido da velocidade
      r.y += VelY;
    }

    //Aqui verificamos se o quadrado chegou no limite das telas horizontais.
    if(r.x > L-r.w || r.x < 0){
      VelX = -VelX;
      r.x += VelX;
    }

    SDL_Delay(20);
    SDL_UpdateWindowSurface(tela);
 }
  return 0;
}
