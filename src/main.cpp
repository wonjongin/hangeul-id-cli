#include "char_group_parser.h"
#include <CLI/CLI.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <hangeul_id/HangeulId.h>
#include <iostream>

int main(int argc, char **argv) {
  CLI::App app{"Hangeul id cli app"};
  app.allow_windows_style_options();
  app.set_version_flag("-v,--version", "0.1.1");
  CLI::App *sub_uuid =
          app.add_subcommand("uuid", "Generate Hangeul id with UUID v4");
  std::string char_group_uuid;
  sub_uuid->add_option(
          "-c,--char-group", char_group_uuid, "Set Character Group");
  sub_uuid->callback([&]() {
    HangeulId id(str_to_char_group(char_group_uuid));
    std::string res = id.generate_hangeul_id_with_uuidv4();
    std::cout << res << std::endl;
  });

  CLI::App *sub_convert = app.add_subcommand("convert", "Convert Hangeul ID");
  std::string char_group;
  sub_convert->add_option("-c,--char-group", char_group, "Set Character Group");
  std::string value;
  sub_convert->add_option("-i,--int", value, "Integer value")
          ->check(CLI::Number);
  sub_convert->callback([&]() {
    HangeulId id(str_to_char_group(char_group));
    std::cout << id.integer_to_hangel_id(uint1024_t(value)) << std::endl;
  });

  CLI11_PARSE(app, argc, argv);
  return 0;
}