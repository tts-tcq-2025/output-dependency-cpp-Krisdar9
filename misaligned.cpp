#include <iostream>
#include <assert.h>
#include <vector>
#include <string>

std::vector<std::string> getColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    std::vector<std::string> colorMap;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::string line = std::to_string(i * 5 + j) + " | " + majorColor[i] + " | " + minorColor[i] + "\n";  
            colorMap.push_back(line);
        }
    }
    return colorMap;
}
int printColorMap() {
    std::vector<std::string> colorMap = getColorMap();
    for(const auto& line : colorMap) {
        std::cout << line << "\n";
    }
    return colorMap.size();
}
void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    int result = printColorMap();
    // Strengthened tests
    assert(result == 25);  // still valid

    // These assertions should FAIL due to the bug
    assert(colorMap[0] == "0 | White | Blue");     // FAILS: actual is "0 | White | White"
    assert(colorMap[1] == "1 | White | Orange");   // FAILS: actual is "1 | White | White"
    assert(colorMap[5] == "5 | Red | Blue");

}

