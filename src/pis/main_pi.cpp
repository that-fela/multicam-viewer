#include "fmt/format.h" // NOLINT
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <nlohmann/json.hpp>
#include <opencv2/opencv.hpp>

constexpr std::string_view CONFIG_PATH = "../../pi-setup.json";

int main() {
    fmt::print("Hello from pi {}\n");

    std::ifstream file(CONFIG_PATH.data());
    if (!file.is_open()) {
        fmt::print("Failed to open config file: {}\n", CONFIG_PATH);
        return 1;
    }

    nlohmann::json data = nlohmann::json::parse(file);

    for (const auto &pi : data["raspberry-pis"]) {
        std::cout << "Name: " << pi["name"] << ", IP: " << pi["ip"]
                  << std::endl;
    }

    return 0;
}
