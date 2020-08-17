// Nazwa pliku wykonywalnego: SmartGeo

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Prosze napisac klasy Point2D, PointAverage
// reprezentujace odpowiednio:
// 1) punkt na plaszczyznie (x,y);
// 2) funktor
//
// ad.1 klasa reprezentujaca punkt na plaszczyznie (x,y), dodatkowo
//      trzeba zdefiniowac dla niej:
//      -operatory post/pre inkrementacji,
//      - przeciazyc operatory new oraz delete, tak aby
//      w przypadku tworzenia/czyszczenia wskaznika wyswietlana byla informacja
//      o tym fakcie na ekran (jak w przykladzie wydruku ponizej)
//      Uwaga: typ size_t zdefiniwany jest w stddef.h
//

//
// ad.2. klasa stanowiaca obiekt funkcyjny (funktor), obliczający średnią 
//       arytmetyczną z podanych Point2D (srednia arytmetyczna osobno dla x i y)
//       i aktualizujący wynik z każdym kolejnym wywołaniem.
//       Metoda Reset() resetuje stan funktora.
//
//
// Pliku Main.cpp, nie wolno modyfikowac
// (w ostatecznej wersji programu nie może być zmodyfikowany)

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow. Można użyć wcześniejszego CMakeLists.txt

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, CMakeLists.txt i Main.cpp)
// nalezy wgrac do UPEL w formie archiwum, spakowany folder projektu do Lab14.tar.gz

// ZESPÓŁ:
// 1.
// 2.

#include <iostream>
#include "PointAverage.h"

int main() {

  std::cout << "*** arithmetic ***"<< std::endl;

  Point2D point1(1.2, 0.5), point2(0.8, 0.5), point3;

  point3 = 0.5 + point1 + point2;

  point1.Print();
  (--point2).Print();
  (point3++).Print();


  Point2D *s_point = new Point2D(0.5, 1.2); // змінив на таке, бо не вчили ще вскажнікі інтелігентне
  s_point->Print();
  


  std::cout << "\n*** average ***"<< std::endl;

  PointAverage average;

  average(point1);
  average(point2);
  average(point3);
  average.Print();

  average.Reset();

  average(point1);
  average(point2);
  average.Print();

  delete s_point;
  
  return 0;
}
/* Wynik dzialania programu

brachwal@vbox:[cmake-build-debug]$ ./SmartGeo
*** arithmetic ***
Point2D:: (1.2,0.5)
Point2D:: (-0.2,-0.5)
Point2D:: (2.5,1)
Point2D:: alokowanie 16 bajtow
Point2D:: (0.5,1.2)

*** average ***
Average Point:: (1.5,0.666667)
Average Point:: (0.5,0)
Point2D:: zwalnianie wskaznika

*/
