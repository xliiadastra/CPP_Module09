#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
#include <vector>

int main() {
    std::ifstream ifs("./data.csv");
    std::string line;
    std::map<std::string, std::string> database;

    // 첫 줄은 헤더이므로 무시
    std::getline(ifs, line);

    // 데이터 라인을 한 줄씩 읽어오며 map에 저장
    while (std::getline(ifs, line)) {
        std::stringstream ss(line);
        std::string key, value;
        std::getline(ss, key, ',');
        std::getline(ss, value, ',');
        database[key] = value;
    }
    double t = 3.31;
    std::cout << t << std::endl;
	// for (std::map<std::string, std::string>::iterator it = database.begin(); it != database.end(); ++it)
	// 	std::cout << it->first << "    " << it->second << std::endl;
    return 0;
}
