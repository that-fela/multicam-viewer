#include "fmt/format.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <opencv2/opencv.hpp>
#include <string>

constexpr std::string_view CONFIG_PATH = "../../pi-setup.json";

int main() {
    fmt::print("Hello from pi\n");

    boost::property_tree::ptree config_json;
    boost::property_tree::read_json(CONFIG_PATH.data(), config_json);

    for (const auto &rpi : config_json.get_child("raspberry-pis")) {
        fmt::print("Pi {} IP: {}\n", rpi.second.get<std::string>("name"),
                   rpi.second.get<std::string>("ip"));
    }

    return 0;
}
