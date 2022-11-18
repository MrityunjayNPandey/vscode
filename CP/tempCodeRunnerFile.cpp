#include <iostream>

#include <cstring>

#include <iomanip>

#include <stdio.h>

#include <stdlib.h>

#include <cstdlib>

void currentPlay(float G [4], float g [4], float n, float &v, float &p, float &q)

{

//Missing: Trying to pass E by reference to the main code does not work due to it being created in this function

      //Initialize Values for E

float A = ((n*G[0]+g[0]))/(n+1);

float B = ((n*G[1]+g[1]))/(n+1);

float C = ((n*G[2]+g[2]))/(n+1);

float D = ((n*G[3]+g[3]))/(n+1);

//Create E

float E [4] = {A, B, C, D};

//Saddle Check (Don't know if this works because each values I put in for G and g, I don't get an E with a saddle point)

if (E[0] <= E[1] && E[0] >= E[2])

{

v = E[0];

p = 1;

q = 1;

}

else if (E[1] <= E[0] && E[1] >= E[3])

{

v = E[1];

p = 1;

q = 0;

}

else if (E[2] <= E[3] && E[2] >= E[0])

{

v = E[2];

p = 0;

q = 1;

}

else if (E[3] <= E[2] && E[3] >= E[1])

{

v = E[3];

p = 0;

q = 0;

}

  

//Determine det, trace, ctrace, ddf, and v

float det = ((A*D)-(B*C));

float trace = (A+D);

float ctrace = (B+C);

float ddf = trace + ctrace;

v = det/ddf;

  

//Determine Probabilities

p = abs((D-B)/ddf);

q = abs((D-C)/ddf);

}

//Main Argument (this is my main function)

int main(int argc, char* argv[])

{

   srand((unsigned int) time(NULL));

  

//Gamme value for comparison

   float gamma = 1;

  

//Number of games played (supposed to go through each round and give new values with this being the ending value)

   int N = 10;

  

//Initial 1st game

float G_1 [4] = {7.00, 2.00, 3.00, 5.00};

  

//Initial 2nd game

float G_2 [4] = {1.00, 6.00, 4.00, 8.00};

  

//Needed to initialize these (supposed to be what strategy Rose uses)

   int rows = 2;

  

//Needed to initialize these (supposed to be what strategy Collin uses)

   int cols = 2;

  

//For the little n for the while loop (don't know if the value is right)

int n = 1;

  

   //Expected value matrix

float E [4] = {0, 0, 0, 0};

  

//Don't remember why we have this one

//float W [4] = {0, 0, 0, 0};

  

//Rose's probability

float p = 0.5;

  

//Collin's probability

float q = 0.5;

  

//Payoff value

float payoff = 0;

  

//Value of game initializer

float v = 0;

  

//Game selected to play?

float g [2][2] = {{0,0},{0,0}};

  

   while (n <= N)

{

   float r = rand() % 1;

   if (r <= gamma)

   {

   //g = G_1; //What it's supposed to be

   memcpy(&g, G_1, sizeof(g)); //Attempt at this

   //Saddle Check G_1 //Should be checked in here so we don't have to go through currentPlay if these exist

   if (G_1[0] <= G_1[1] && G_1[0] >= G_1[2])

   {

   v = G_1[0];

   p = 1;

   q = 1;

   }

   else if (G_1[1] <= G_1[0] && G_1[1] >= G_1[3])

   {

   v = G_1[1];

   p = 1;

   q = 0;

   }

   else if (G_1[2] <= G_1[3] && G_1[2] >= G_1[0])

   {

   v = G_1[2];

   p = 0;

   q = 1;

   }

   else if (G_1[3] <= G_1[2] && G_1[3] >= G_1[1])

   {

   v = G_1[3];

   p = 0;

   q = 0;

   }

   }

   else

   {

   //g = G_2; (what it's supposed to be)

   memcpy(&g, G_2, sizeof(g)); //Attempt at this


   //Saddle Check G_2 (Should be checked in here so we don't have to go through currentPlay if these exist)

   if (G_2[0] <= G_2[1] && G_2[0] >= G_2[2])

   {

   v = G_2[0];

   p = 1;

   q = 1;

   }

   else if (G_2[1] <= G_2[0] && G_2[1] >= G_2[3])

   {

   v = G_2[1];

   p = 1;

   q = 0;

   }

   else if (G_2[2] <= G_2[3] && G_2[2] >= G_2[0])

   {

   v = G_2[2];

   p = 0;

   q = 1;

   }

   else if (G_2[3] <= G_2[2] && G_2[3] >= G_2[1])

   {

   v = G_2[3];

   p = 0;

   q = 0;

   }

   }

//The r_p and r_c pieces of code I don't know if they work or if written right (supposed to be what strategy rose (p) and collin (q) pick)

   int r_p = rand() % 1;

   if(r_p <= p)

   {

cols = 1;

   }

   else

   {

cols = 2;

   }

   int r_c = rand() % 1;

   if(r_c <= q)

   {

cols = 1;

   }

   else

   {

cols = 2;

   }

//This does not make sense to me

payoff = payoff + g[rows][cols];

//Should this be in an if Saddles Exist or Not function in order for it to run?

currentPlay(G_1,G_2,N,v,p,q);

   n++;

}

   std::cout << "Round: " << N << "\n";

   std::cout << "Expected Matrix: " << E << "\n";

   std::cout << "Value of Game: " << v << "\n";

   std::cout << "Rose's Probability: " << p << "\n";

   std::cout << "Collin's Probability: " << q << "\n";

//Which n is this dividing?

   std::cout << "Payoff: " << (payoff/n) << "\n";

   return 0;

}