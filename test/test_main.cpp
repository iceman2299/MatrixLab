/*
//Автоматический режим
#include <gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/

//Ручной режим
#pragma once
#include "TVector.h"
//#include "TMatrix.h"
#include <iostream>

int main()//vector
{
  setlocale(LC_ALL, "Russian");


  TVector<double> first, second, sum, razn;
  
  first.Vvod();
  second.Vvod();

  sum = first + second;
  std::cout << "Сумма: " << first+second << "Первый: " << first << "Второй: " << second;
  razn = first - second;
  std::cout << "Сумма: " << sum << "Разность: " << razn;
}


