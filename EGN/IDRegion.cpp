#include "IDRegion.hh"

IDRegion getRegion(size_t num) {
  IDRegion vals[] = { Blagoevgrad,
  Burgas,
  Varna,
  VelikoTarnovo,
  Vidin,
  Vratsa,
  Gabrovo,
  Kardzali,
  Kyustendil,
  Lovech,
  Montana,
  Pazardzhik,
  Pernik,
  Pleven,
  Plovdiv,
  Razgrad,
  Ruse,
  Silistra,
  Sliven,
  Smolyan,
  SofiaCity,
  Sofia, // Sofia Province
  StaraZagora,
  Dobrich,
  Targovishte,
  Haskovo,
  Shumen,
  Yambol,
  Other };

  IDRegion currRegion = Blagoevgrad;

  for(size_t i = 0; i < sizeof(vals)/sizeof(IDRegion); i++) {
    if((int) currRegion <= num) {
      currRegion = vals[i];
    }
    else {
      break;
    }
  }

  return currRegion;
}