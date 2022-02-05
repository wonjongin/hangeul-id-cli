#include "char_group_parser.h"
#include <boost/algorithm/string.hpp>

HangeulCharGroup str_to_char_group(std::string str) {
  boost::algorithm::to_lower(str);
  if (str == "ksx1001" || str == "ksx" || str == "k") {
    return HangeulCharGroup::KSX1001;
  } else if (str == "all_hangeul" || str == "all" || str == "a") {
    return HangeulCharGroup::ALL_HANGEUL;
  } else {
    return HangeulCharGroup::KSX1001;
  }
}