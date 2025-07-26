/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Parser
*/

#include <string.h>
#include <fstream>
#include "ErrorParser.hpp"

// Usefull functions

const char *COMPONENT[] = {
    "and", "or", "xor", "not", "input", "output", "logger", "clock", "4001", "4011",
    "4030", "4069", "4071", "4081", "4008", "4013", "4017", "4040", "4512",
    "4514", "4801", "2716", "true", "false", "4094"
};

const char *CompLinks[][5] = {
    {"2716", "12", "24", NULL, NULL},
    {"4001", "7", "14", NULL, NULL},
    {"4008", "8", "16", NULL, NULL},
    {"4011", "7", "14", NULL, NULL},
    {"4013", "7", NULL, NULL, NULL},
    {"4030", "7", "14", NULL, NULL},
    {"4040", "8", "16", NULL, NULL},
    {"4069", "7", "14", NULL, NULL},
    {"4071", "7", "14", NULL, NULL},
    {"4081", "7", "14", NULL, NULL},
    {"4094", "8", NULL, NULL, NULL},
    {"4512", "8", NULL, NULL, NULL},
    {"4514", "12", "24", NULL, NULL},
    {"4801", "12", "19", "24", NULL}
};

static int getWhileSpace(std::string str) {
    int i = 0;

    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
        i++;
    return i;
}

static int checkComment(char const *str)
{
    int c = 0;
    while (str[c] != '\0' && (str[c] == ' ' || str[c] == '\t'))
        c++;
    if (str[c] == '#')
        return 1;
    return 0;
}

static int my_str_isprintable(char const *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > ' ' && str[i] < 127)
            return 1;
    }
    return 0;
}

static int checkLabel(std::ifstream &file, char const *cmp) {
    bool chipsets = false;
    std::string line;

    while (file) {
        std::getline(file, line);
        if (strncmp(&line.c_str()[getWhileSpace(line.c_str())], cmp, strlen(cmp)) == 0) {
            chipsets = true;
            break;
        }
    }
    if (!chipsets) {
        file.close();
        throw nts::ErrorParser::LexicalOrSyntacticError();
    }
    return 0;
}

static std::string convertChipset(std::string line)
{
    int n = 0;
    int t = 0;
    std::string chipset;

    while (line[n] <= ' ' && line[n] != '\0')
        n++;
    for (int i = n; line[i] != '\0'; i++) {
        if ((line[i - 1] == ' ' || line[i - 1] == '\t') && (line[i] > ' ' && line[i] != '#') && ((i - n) > 0))
            t++;
        if (line[i] == '#')
            break;
    }
    for (int i = 0; line[n] != '\0'; i++) {
        if (line[n] == '#')
            break;
        if (t == 0 && (line[n] == ' ' || line[n] == '\t'))
            break;
        if ((line[n - 1] == ' ' || line[n - 1] == '\t') && (line[n] > ' ') && i > 0)
            t--;
        chipset += line[n];
        n++;
    }
    return chipset;
}

static int getStartKey(std::string str, int n) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t')
            break;
        i++;
    }
    if (n == 0)
        return i;
    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
        i++;
    return i;
}

static int compareChipsetsAndLinks(nts::ErrorParser &error) {
    bool cmp = false;

    for (auto &link : error.getLinks()) {
        cmp = false;
        std::size_t pos = link.find(':');
        for (auto &chipset : error.getChipsets()) {
            if (link.substr(0, pos) == chipset.substr(getStartKey(chipset, 1))) {
                cmp = true;
                break;
            }
        }
        if (cmp == false) {
            throw nts::ErrorParser::UnknownComponentName();
        }
    }
    return 0;
}

static void checkIgnoredPins(const std::string &componentType, const std::string &pin) {
    for (int i = 0; i < 14; i++) {
        if (strcmp(componentType.c_str(), CompLinks[i][0]) == 0) {
            for (int j = 1; j < 5; j++) {
                if (CompLinks[i][j] != NULL && strcmp(pin.c_str(), CompLinks[i][j]) == 0)
                    throw nts::ErrorParser::InvalidPinNumber();
            }
        }
    }
}

int nts::ErrorParser::checkErroLinks(void) {
    std::string line;

    for (size_t i = 0; i < _links.size(); i++) {
        std::size_t pos = _links[i].find(':');
        std::string beginning = _links[i].substr(0, pos);
        std::string end = _links[i].substr(pos + 1);
        for (size_t j = 0; j < _linksAndName.size(); j++) {
            std::string bgLinks = _linksAndName.begin()->first;
            std::string endLinks = _linksAndName.begin()->second;
            if (strcmp(beginning.c_str(), endLinks.c_str()) == 0)
                checkIgnoredPins(bgLinks, end);
        }
    }
    return 0;
}

nts::ErrorParser::ErrorParser() : _nbLinks(0), _file(""), _chipsets(), _links() {}

nts::ErrorParser::~ErrorParser() {
    if (_chipsets.empty()) {
        for (auto &chipset : _chipsets)
            delete &chipset;
    }
    if (_links.empty()) {
        for (auto &link : _links)
            delete &link;
    }
}

std::vector<std::string> nts::ErrorParser::getChipsets() const {
    return _chipsets;
}

std::vector<std::string> nts::ErrorParser::getLinks() const {
    return _links;
}

int nts::ErrorParser::getNbLinks() const {
    return _nbLinks;
}

std::ifstream nts::ErrorParser::checkFile(char const *file) {
    std::ifstream file_stream(file);

    if (!file_stream.is_open())
        throw nts::ErrorParser::UnfoundFile();
    return file_stream;
}

int nts::ErrorParser::checkChipset(std::ifstream file) {
    std::string line;
    bool component = false;

    checkLabel(file, ".chipsets:");
    while (std::getline(file, line) && strncmp(&line.c_str()[getWhileSpace(line.c_str())], ".links:", 7) != 0) {
        component = false;
        if (line.empty() || checkComment(line.c_str()) == 1 || my_str_isprintable(line.c_str()) == 0)
            continue;
        std::string temp = convertChipset(line);
        for (int i = 0; i < 25; i++) {
            if (COMPONENT[i] == temp.substr(0, strlen(COMPONENT[i]))) {
                component = true;
                _chipsets.push_back(temp);
                std::size_t startKeyPos = getStartKey(line, 0);
                std::string beginning = line.substr(0, startKeyPos);
                if (startKeyPos == line.length() || startKeyPos + 1 == line.length()) {
                    throw nts::ErrorParser::ComponentWithNoName();
                }
                std::string end = line.substr(startKeyPos + 1);
                size_t first = end.find_first_not_of(" \t");
                size_t last = end.find_last_not_of(" \t");
                if (first != std::string::npos && last != std::string::npos) {
                    end = end.substr(first, (last - first + 1));
                }
                _linksAndName.insert(std::pair<std::string, std::string>(beginning, end));
            }
        }
        if (!component) {
            throw nts::ErrorParser::UnknownComponentType();
        }
    }
    file.close();
    if (_chipsets.empty())
        throw nts::ErrorParser::NoChipsetsInCircuit();
    return 0;
}

int nts::ErrorParser::checkLinks(std::ifstream file) {

    std::string line;
    std::string part1;
    std::string part2;

    checkLabel(file, ".links:");
    while (std::getline(file, line)) {
        if (line.empty() || checkComment(line.c_str()) == 1 || my_str_isprintable(line.c_str()) == 0)
            continue;
        std::string temp = convertChipset(line);
        std::size_t pos = temp.find(' ');
        if (pos != std::string::npos) {
            part1 = temp.substr(0, pos);
            part2 = temp.substr(pos + 1);
            size_t first = part2.find_first_not_of(" \t");
            size_t last = part2.find_last_not_of(" \t");
            if (first != std::string::npos && last != std::string::npos) {
                part2 = part2.substr(first, (last - first + 1));
            } else {
                part2 = "";
            }
        } else {
            part1 = temp;
            part2 = "";
        }
        if (strcmp(part1.c_str(), part2.c_str()) == 0)
            throw nts::ErrorParser::PinLinkedToItself();
        _links.push_back(temp.substr(0, getStartKey(temp, 0)));
        _nbLinks++;
        _links.push_back(temp.substr(getStartKey(temp, 1), getStartKey(&temp[getStartKey(temp, 1)], 0)));
        _nbLinks++;
    }
    compareChipsetsAndLinks(*this);
    return 0;
}

int nts::ErrorParser::parseFunction(char *filename) {
    _file = std::string (filename);
    if (_file.size() < 5)
        throw nts::ErrorParser::NotNtsFile();
    std::string end = _file.substr(_file.length() - 4);
    if (strcmp(end.c_str(), ".nts") != 0)
        throw nts::ErrorParser::NotNtsFile();
    checkChipset(checkFile(_file.c_str()));
    checkLinks(checkFile(_file.c_str()));
    checkErroLinks();
    return 0;
}
