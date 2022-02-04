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
  sub_uuid->callback([&]() {
    HangeulId id(HangeulCharGroup::KSX1001);
    std::string res = id.generate_hangeul_id_with_uuidv4();
    std::cout << res << std::endl;
  });

  CLI::App *sub_convert = app.add_subcommand("convert", "Convert Hangeul ID");
  std::string value;
  sub_convert->add_option("-i,--int", value, "Integer value")
          ->check(CLI::Number);
  sub_convert->callback([&]() {
    HangeulId id;
    std::cout << id.integer_to_hangel_id(uint1024_t(value)) << std::endl;
  });

  CLI11_PARSE(app, argc, argv);
  return 0;
}