#pragma once
#include <iostream> // size_t

enum IDRegion {
  Blagoevgrad = 0,
  Burgas = 44,
  Varna = 94,
  VelikoTarnovo = 140,
  Vidin = 170,
  Vratsa = 184,
  Gabrovo = 218,
  Kardzali = 234,
  Kyustendil = 282,
  Lovech = 302,
  Montana = 320,
  Pazardzhik = 342,
  Pernik = 378,
  Pleven = 396,
  Plovdiv = 436,
  Razgrad = 502,
  Ruse = 528,
  Silistra = 556,
  Sliven = 576,
  Smolyan = 602,
  SofiaCity = 624,
  Sofia = 722, // Sofia Province
  StaraZagora = 752,
  Dobrich = 790,
  Targovishte = 822,
  Haskovo = 844,
  Shumen = 872,
  Yambol = 904,
  Other = 926
};


IDRegion getRegion(size_t num);