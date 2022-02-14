#include <iostream>
#include <cstdlib>
#include <unistd.h>


int board[7][6];
int choice, player;
bool end = false;
int a = 5;

void checkPos(int x)
{
  if (board[x - 1][a] != 0)
  {
    a--;
    check(x);
  }
  else if (player == 1 && a < 6)
  {
    board[x - 1][a] = 1;
    a = 5;
  }
  else if (player == 2 && a < 6)
  {
    board[x - 1][a] = 2;
    a = 5;
  }
  else
  {
    std::cout << "WRONG!" << std::endl;
    a = 5;
    player++;
  }
}

void drawBoard()
{
  system("clear");
  for (int i = 0; i < 9; i++)
  {
    if (i < 2)
    {
      std::cout << "-";
    }
    else if (i > 7)
    {
      std::cout << i - 1 << "--" << std::endl;
    }
    else
    {
      std::cout << i - 1 << "----";
    }
  }
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (board[j][i] != 0)
      {
        if (board[j][i] == 1)
        {
          std::cout << "| R |";
        }
        else std::cout << "| B |";
      }
      else std::cout << "|   |";
    } 
    std::cout << std::endl;
  }
  for (int i = 0; i < 35; i++)
  {
    std::cout << "=";
  } 
  std::cout << std::endl;
}

void win_check()
{
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 7; j++)
    {
      if (board[j][i] == 1 && board[j + 1][i + 1] == 1 && board[j + 2][i + 2] == 1 && board[j + 3][i + 3] == 1)
      {
        end = true;
        std::cout << "\nPLAYER 1 WIN!" << std::endl;
      }
      if (board[j][i] == 1 && board[j + 1][i - 1] == 1 && board[j + 2][i - 2] == 1 && board[j + 3][i - 3] == 1)
      {
        std::cout << "\nPLAYER 1 WIN!" << std::endl;
        end = true;
      }
      else if (board[j][i] == 1 && board[j][i - 1] == 1 && board[j][i - 2] == 1 && board[j][i - 3] == 1)
      {
        std::cout << "\nPLAYER 1 WIN!" << std::endl;
        end = true;
      }
      else if (board[j][i] == 1 && board[j - 1][i] == 1 && board[j - 2][i] == 1 && board[j - 3][i] == 1)
      {
        std::cout << "\nPLAYER 1 WIN!" << std::endl;
        end = true;
      }
      if (board[j][i] == 2 && board[j + 1][i - 1] == 2 && board[j + 2][i - 2] == 2 && board[j + 3][i - 3] == 2)
      {
          std::cout << "\nPLAYER 2 WIN!" << std::endl;
          end = true;
      }
      else if (board[j][i] == 2 && board[j - 1][i - 1] == 2 && board[j - 2][i - 2] == 2 && board[j - 3][i - 3] == 2)
      {
          end = true;
          std::cout << "\nPLAYER 2 WIN!" << std::endl;
      }
      else if (board[j][i] == 2 && board[j][i - 1] == 2 && board[j][i - 2] == 2 && board[j][i - 3] == 2)
      {
        std::cout << "\nPLAYER 2 WIN!" << std::endl;
        end = true;
      }
      else if (board[j][i] == 2 && board[j - 1][i] == 2 && board[j - 2][i] == 2 && board[j - 3][i] == 2)
      {
        std::cout << "\nPLAYER 2 WIN!" << std::endl;
        end = true;
      }
    }
  }
}

void p_choice()
{
  player = 1;
  while(end != true)
  {
    std::cout << "PLAYER " << player << ": ";
    std::cin >> choice;
    if (choice > 0 && choice < 8)
    {
      checkPos(choice);
      draw();
      if (player == 1)
      {
        player++;
      }
      else
      {
        player--;
      }
    }
    else
    {
      std::cout << "WRONG CHOICE!" << std::endl;
    }
    win_check();
  }
}


int main()
{
    system("clear");
    std::cout << "WELCOME IN CONNECT 4" << std::endl;
    sleep(2);
    drawBoard();
    p_choice();
    return 0;
}
